#pragma once
#include"paddle.h"

class Bot : public Paddle
{
private:
	// no data member

public:
	Bot(float x, float y, float width, float height, int pixel);
	void update(int ball_y_axis);
};