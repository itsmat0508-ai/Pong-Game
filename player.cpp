#include"player.h"

// data member:
// string name;
// int score;


Player::Player(string name, int score)
{
	this->name = name;
	this->score = score;
}

void Player::setName(string name) { this->name = name; }
void Player::setScore(int score) { this->score = score; }
string Player::getName() { return name; }
int Player::getScore() { return score; }
void Player::incScore() { score++; }
void Player::print(int posX, int posY, int fontSize, Color color)
{
	const char* text = TextFormat("%s : %d", name.c_str(), score);
	int textWidth = MeasureText(text, fontSize);
	int actualX = posX - (textWidth / 2);
	DrawText(text, actualX, posY, fontSize, color);
}