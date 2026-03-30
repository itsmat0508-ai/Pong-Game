#pragma once
#include"raylib.h"
#include<iostream>
using namespace std;


class Paddle
{
private:
	float X_axis;
	float Y_axis;
	float width;
	float height;
	int pixel;
	

public:
	Paddle(float x, float y, float width, float height, int pixel);
	
	int getPixel();
	float getHeight();
	float getWidth();
	float getX_axis();
	float getY_axis();

	void setPixel(int pixel);
	void setHeight(float height);
	void setWidth(float width);
	void setX_axis(float x);
	void setY_axis(float y);

	void draw(Color color);
	void update(int keyUp, int keyDown);
	Rectangle getRec();
};