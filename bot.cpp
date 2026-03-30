#include"bot.h"



Bot::Bot(float x, float y, float width, float height, int pixel)
	:Paddle(x, y, width, height, pixel) {}

void Bot::update(int ball_y_axis)
{
    float object = getY_axis() + getHeight() / 2;
    if (object > ball_y_axis)
        setY_axis(getY_axis() - getPixel()); // Y_axis = Y_axis - pixel
    
    if (object <= ball_y_axis)
        setY_axis(getY_axis() + getPixel()); // Y_axis = Y_axis + pixel
}