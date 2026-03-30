#include"paddle.h"

// data memeber:-
// float X_axis;
// float Y_axis;
// float width;
// float height;
// int pixel;



Paddle::Paddle(float x, float y, float width, float height, int pixel)
{
	X_axis = x;
	Y_axis = y;
	this->width = width;
	this->height = height;
	this->pixel = pixel;
}

int Paddle::getPixel() { return pixel; }
float Paddle::getHeight() { return height; }
float Paddle::getWidth() { return width; }
float Paddle::getX_axis() { return X_axis; }
float Paddle::getY_axis() { return Y_axis; }

void Paddle::setPixel(int pixel) { this->pixel = pixel; }
void Paddle::setHeight(float height) { this->height = height; }
void Paddle::setWidth(float width) { this->width = width; }
void Paddle::setX_axis(float x) { this->X_axis = x; }
void Paddle::setY_axis(float y) { this->Y_axis = y; }

void Paddle::draw(Color color)
{
	float roundness = 0.8;
	int smoothness = 0;
	DrawRectangleRounded(Rectangle{ X_axis, Y_axis, width, height }, roundness, smoothness, color);
}
void Paddle::update(int keyUp, int keyDown)
{
    if (IsKeyDown(keyUp))
    {
        if (Y_axis != 0)
        {
            Y_axis = Y_axis - pixel;
        }
    }
    if (IsKeyDown(keyDown))
    {
        if (Y_axis + height != GetScreenHeight())
        {
            Y_axis = Y_axis + pixel;
        }
    }
}

Rectangle Paddle::getRec() 
{
    return Rectangle{ X_axis, Y_axis, width, height };
}