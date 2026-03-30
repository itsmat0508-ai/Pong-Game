#pragma once
#include"raylib.h"
#include"player.h"
#include<iostream>
using namespace std;

class Ball
{
private:
	float X_axis;
	float Y_axis;
	float pixel_x;
	float pixel_y;
	int radius;
	float resetTimer;

public:
	Ball(float x, float y, float pix_x, float pix_y, int radius);
	float getX_axis();
	float getY_axis();
	float getPixel_x();
	float getPixel_y();
	int getRadius();
	void setX_axis(float x);
	void setY_axis(float y);
	void setPixel_x(float pix_x);
	void setPixel_y(float pix_y);
	void setRadius(int radius);
	void draw(Color color);
	void resetBall();
	void update(Player& p1, Player& p2, int& targetFps, Sound& wallhit, Sound& goal);
};