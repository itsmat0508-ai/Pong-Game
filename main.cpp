#include"ball.h"
#include"paddle.h"
#include"player.h"
#include"bot.h"
#include <iostream>
using namespace std;

void boardDraw(const int screenWidth, const int screenHeight, int radius, Color circle, Color line)
{
    DrawCircle(screenWidth / 2, screenHeight / 2, radius, circle);
    DrawLine(screenWidth / 2, 0, screenWidth / 2, screenHeight, line);
}

int main()
{
    // setup
    const int screen_width = 1080;
    const int screen_height = 600;
    const int padWidth = 25;
    const int padHeight = 120;   
    const int fontSize = 40;
    const int elementCircleRadius = 120;
    const int textPadding = 20;
    const int paddlePadding = 10;
    const int ballpixel = 7;
    const int paddlePixel = 6;
    const int ballRadiius = 20;
    const int initialScore = 0;
    int targetFps = 60;
    bool bot = true;

    Ball ball(screen_width / 2, screen_height / 2, ballpixel, ballpixel, ballRadiius);
    Bot cpu(paddlePadding, screen_height / 2 - padHeight / 2, padWidth, padHeight, paddlePixel);
    Paddle padR(screen_width - padWidth - paddlePadding, screen_height / 2 - padHeight / 2, padWidth, padHeight, paddlePixel);
    Paddle padL(paddlePadding, screen_height / 2 - padHeight / 2, padWidth, padHeight, paddlePixel);
    Player player1("player1", initialScore);
    Player player2("player2", initialScore);

    Color background = { 45, 30, 85, 255 };
    Color textColor = RAYWHITE;
    Color paddleColor = { 255, 0, 150, 255 };
    Color ballColor = { 255, 235, 0, 255 };
    Color lineElement = { 255, 255, 255, 50 };
    Color circleElement = { 255, 255, 255, 30 };

    InitWindow(screen_width, screen_height, "PONG GAME!");
    InitAudioDevice();

    Sound hitSound = LoadSound("../assects/audio/hit_sound.mp3");
    Sound wallSound = LoadSound("../assects/audio/wall_hit.mp3");
    Sound goalSound = LoadSound("../assects/audio/goal_sound.mp3");

    // gameLoop
    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_C))
            bot = !bot;

        SetTargetFPS(targetFps);

        cout << "FPS: " << targetFps << endl;
        BeginDrawing();

        // Updating
        ball.update(player1, player2, targetFps, wallSound, goalSound);
        padR.update(KEY_UP, KEY_DOWN);
        if (bot)
            cpu.update(ball.getY_axis());
        else
            padL.update(KEY_W, KEY_S);


        // event handeling
        Rectangle rec;
        if (bot)
            rec = cpu.getRec();
        else
            rec = padL.getRec();

        if (CheckCollisionCircleRec({ ball.getX_axis(), ball.getY_axis() }, ball.getRadius(), padR.getRec()))
        {
            ball.setPixel_x(ball.getPixel_x() * -1);   // ball.pixel_x = ball.pixel_x * -1
            PlaySound(hitSound);
            if (targetFps < 120)
                targetFps += 5;
        }

        if (CheckCollisionCircleRec({ ball.getX_axis(), ball.getY_axis() }, ball.getRadius(), rec))
        {
            PlaySound(hitSound);
            ball.setPixel_x(ball.getPixel_x() * -1);   // ball.pixel_x = ball.pixel_x * -1
            if (targetFps < 120)
                targetFps += 5;
        }

        // Drawing
        ClearBackground(background);
        boardDraw(screen_width, screen_height, elementCircleRadius, circleElement, lineElement);

        ball.draw(ballColor);
        padR.draw(paddleColor);
        if (bot)
            cpu.draw(paddleColor);
        else
            padL.draw(paddleColor);

        player1.print(screen_width / 4, textPadding, fontSize, textColor);
        player2.print(3 * screen_width / 4, textPadding, fontSize, textColor);

        EndDrawing();
    }

    UnloadSound(hitSound);
    UnloadSound(wallSound);
    UnloadSound(goalSound);
    CloseAudioDevice();
    CloseWindow();
    return 0;
}