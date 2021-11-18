#pragma once
#include "Board.h"
#include "Player.h"

class GameField
{
private:
	long m_arrAttackPoints[7]{ 0, 3, 24, 192, 1536, 12288, 98304 };
	long m_arrDefensePoints[7]{ 0, 1, 9, 81, 729, 6561, 59049 };
public:
	Board m_board;
	Player m_player1;
	Player m_player2;
	GameField();
	~GameField();
	Player GetPlayer1();
	Player GetPlayer2();
	Board GetBoard();
	Move BestMoveHeuristic();
	Move BestMoveMinimax();
	int Minimax(int, bool);
	long AttackPointRow(int, int);
	long AttackPointColumn(int, int);
	long AttackPointBackSlash(int, int);
	long AttackPointForwardSlash(int, int);
	long DefensePointRow(int, int);
	long DefensePointColumn(int, int);
	long DefensePointBackSlash(int, int);
	long DefensePointForwardSlash(int, int);
};

