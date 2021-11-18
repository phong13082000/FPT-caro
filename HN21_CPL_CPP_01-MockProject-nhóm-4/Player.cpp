#include "Player.h"
#include "Contants.h"
#include <iostream>

using namespace std;

Player::Player() {}

Player::Player(string name, int numsWin, int numsDraw, int numsLose)
{
	m_strName = name;
	m_nNumberOfWins = numsWin;
	m_nNumberOfDraws = numsDraw;
	m_nNumberOfLoses = numsLose;
}

Player::~Player() {}

void Player::SetName(string name)
{
	m_strName = name;
}

string Player::GetName()
{
	return m_strName;
}

int Player::GetNumsWin()
{
	return m_nNumberOfWins;
}

int Player::GetNumsDraw()
{
	return m_nNumberOfDraws;
}

int Player::GetNumsLose()
{
	return m_nNumberOfLoses;
}

Move Player::InputMove()
{
	int x, y;
	cin >> x >> y;
	if (cin.fail())
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		throw x;
	}
	else if (x < 0 || x >= ROW_SIZE)
	{
		throw x;
	}
	else if (y < 0 || y >= COL_SIZE)
	{
		throw y;
	}
	return Move(x, y);
}
