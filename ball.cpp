#include"ball.h"
#include"paddle.h"

// data members
// float X_axis;
// float Y_axis;
// float pixel_x;
// float pixel_y;
// int radius;


Ball::Ball(float x, float y, float pix_x, float pix_y, int radius)
{
	X_axis = x;
	Y_axis = y;
	pixel_x = pix_x;
	pixel_y = pix_y;
	this->radius = radius;
    this->resetTimer = 0.0f;
}

float Ball::getX_axis() { return X_axis; }
float Ball::getY_axis() { return Y_axis; }
float Ball::getPixel_x() { return pixel_x; }
float Ball::getPixel_y() { return pixel_y; }
int Ball::getRadius() { return radius; }
void Ball::setX_axis(float x) { X_axis = x; }
void Ball::setY_axis(float y) { Y_axis = y; }
void Ball::setPixel_x(float pix_x){ pixel_x = pix_x; }
void Ball::setPixel_y(float pix_y) { pixel_y = pix_y; }
void Ball::setRadius(int radius) { this->radius = radius; }
void Ball::draw(Color color)
{
		DrawCircle(X_axis, Y_axis, radius, color);
}
void Ball::resetBall()
{
    
	X_axis = GetScreenWidth() / 2;
	Y_axis = GetScreenHeight() / 2;

	int speed_choices[2] = { 1, -1 };
	pixel_x *= -1;
	pixel_y *= speed_choices[GetRandomValue(0, 1)];
}

void Ball::update(Player& p1, Player& p2, int& targetFps, Sound& wallhit, Sound& goal)
{
    
    if (resetTimer > 0) 
    {
        resetTimer -= GetFrameTime(); 
        return;
    }

    X_axis += pixel_x;
    Y_axis += pixel_y;

    // Bounce
    if (Y_axis + radius >= GetScreenHeight() || Y_axis - radius <= 0) 
    {
        PlaySound(wallhit);
        pixel_y *= -1;
    }

    // Goal Scoring
    if (X_axis + radius >= GetScreenWidth() || X_axis - radius <= 0)
    {
        if (X_axis + radius >= GetScreenWidth()) 
            p1.incScore();
        else 
            p2.incScore();

        PlaySound(goal);
        resetBall();
        resetTimer = 0.5; 
    }
}
