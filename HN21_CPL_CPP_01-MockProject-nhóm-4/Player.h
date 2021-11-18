#pragma once
#include <string>
#include "Move.h"

using namespace std;

class Player
{
private:
	string m_strName;
	int m_nNumberOfWins;
	int m_nNumberOfLoses;
	int m_nNumberOfDraws;
public:
	Player();
	Player(string, int, int, int);
	~Player();
	void SetName(string name);
	string GetName();
	int GetNumsWin();
	int GetNumsDraw();
	int GetNumsLose();
	Move InputMove();

};

