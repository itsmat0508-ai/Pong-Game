#pragma once
#include"raylib.h"
#include<cstring>
#include<iostream>
using namespace std;

class Player
{
private:
	string name;
	int score;

public:
	Player(string name, int score);
	void setName(string name);
	void setScore(int score);
	string getName();
	int getScore();
	void incScore();
	void print(int posX, int posY, int fontSize, Color color);
};