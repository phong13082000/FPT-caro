#pragma once
#include "Contants.h"
#include "Move.h"
#include <iostream>
#include <vector>

using namespace std;


class Board
{
private:
	char m_board[ROW_SIZE][COL_SIZE];
	int m_nTotalCells; // number cells is empty
public:
	Board();
	~Board();
	int GetTotalCells();
	char GetValueCell(int, int);
	void UpdateBoard(Move);
	void UpdateBoard(int, int);
	void DisplayBoard();
	bool CheckCellIsEmpty(int, int);
	bool CheckWinCondition(int, int);
	bool CheckDrawCondition();
	int CheckStateGame();
};

