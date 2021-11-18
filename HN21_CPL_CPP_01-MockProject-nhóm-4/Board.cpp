#include "Board.h"
#include <iostream>

using namespace std;

Board::Board()
{
	m_nTotalCells = ROW_SIZE * COL_SIZE;
	for (int i = 0; i < ROW_SIZE; ++i)
	{
		for (int j = 0; j < COL_SIZE; ++j)
		{
			m_board[i][j] = ' ';
		}
	}
}

Board::~Board() {}

int Board::GetTotalCells()
{
	return m_nTotalCells;
}

char Board::GetValueCell(int x, int y)
{
	return m_board[x][y];
}

void Board::UpdateBoard(Move move)
{
	int x = move.GetX();
	int y = move.GetY();
	if (m_board[x][y] == ' ')
	{
		m_board[x][y] = move.GetType();
		--m_nTotalCells;
	}
}

void Board::UpdateBoard(int x, int y)
{
	if (m_board[x][y] != ' ')
	{
		m_board[x][y] = ' ';
		++m_nTotalCells;
	}
}

void Board::DisplayBoard()
{
	cout << "  ";
	for (int i = 0; i < COL_SIZE; ++i)
	{
		cout << "   " << i;
	}
	cout << "\n";
	cout << "   |";
	for (int i = 0; i < COL_SIZE; ++i)
	{
		cout << "---|";
	}
	cout << "\n";
	for (int i = 0; i < ROW_SIZE; ++i)
	{
		cout << " " << i;
		for (int j = 0; j < COL_SIZE; ++j)
		{
			cout << " | " << m_board[i][j];
		}
		cout << " |\n";
		cout << "   |";
		for (int j = 0; j < COL_SIZE; ++j)
		{
			cout << "---|";
		}
		cout << "\n";
	}
}

bool Board::CheckCellIsEmpty(int x, int y)
{
	if (m_board[x][y] != ' ')
		return false;
	return true;
}

// Check win condition block two ends.
bool Board::CheckWinCondition(int curRow, int curCol)
{
	// vars to check
	char currentCell = m_board[curRow][curCol];
	int countCellsSameVal = 0;
	int countCellsDiffVal = 0;

	// Check column
	for (int row = 1; row + curRow < ROW_SIZE; ++row) // check from current to bottom
	{
		if (m_board[row + curRow][curCol] == currentCell)
		{
			countCellsSameVal++;
		}
		else if (m_board[row + curRow][curCol] == ' ')
			break;
		else
		{
			countCellsDiffVal++;
			break;
		}
	}
	for (int row = 1; curRow - row >= 0; ++row) // check from current to top
	{
		if (m_board[curRow - row][curCol] == currentCell)
			countCellsSameVal++;
		else if (m_board[curRow - row][curCol] == ' ')
			break;
		else 
		{
			countCellsDiffVal++;
			break;
		}
	}
	if (countCellsDiffVal == 2)
		return false;
	if (countCellsSameVal >= NUMS_TO_WIN - 1)
		return true;

	countCellsSameVal = 0;
	countCellsDiffVal = 0;
	// Check row
	for (int col = 1; col + curCol < COL_SIZE; ++col) // check from current to right
	{
		if (m_board[curRow][curCol + col] == currentCell)
			countCellsSameVal++;
		else if (m_board[curRow][curCol + col] == ' ')
			break;
		else
		{
			countCellsDiffVal++;
			break;
		}
	}
	for (int col = 1; curCol - col >= 0; ++col) // check from current to left
	{
		if (m_board[curRow][curCol - col] == currentCell)
			countCellsSameVal++;
		else if (m_board[curRow][curCol - col] == ' ')
			break;
		else
		{
			countCellsDiffVal++;
			break;
		}
	}
	if (countCellsDiffVal == 2)
		return false;
	if (countCellsSameVal >= NUMS_TO_WIN - 1)
		return true;

	countCellsSameVal = 0;
	countCellsDiffVal = 0;
	// Check diagonal backslash
	for (int idx = 1; idx + curCol < COL_SIZE && curRow - idx >= 0; ++idx) // check from current to right top
	{
		if (m_board[curRow - idx][curCol + idx] == currentCell)
			countCellsSameVal++;
		else if (m_board[curRow - idx][curCol + idx] == ' ')
			break;
		else
		{
			countCellsDiffVal++;
			break;
		}
	}
	for (int idx = 1; curCol - idx >= 0 && curRow + idx < ROW_SIZE; ++idx) // check from current to bottom left
	{
		if (m_board[curRow + idx][curCol - idx] == currentCell)
			countCellsSameVal++;
		else if (m_board[curRow + idx][curCol - idx] == ' ')
			break;
		else
		{
			countCellsDiffVal++;
			break;
		}
	}
	if (countCellsDiffVal == 2)
		return false;
	if (countCellsSameVal >= NUMS_TO_WIN - 1)
		return true;

	countCellsSameVal = 0;
	countCellsDiffVal = 0;
	// Check diagonal forwardslash
	for (int idx = 1; idx + curCol < COL_SIZE && curRow + idx < ROW_SIZE; ++idx) // check from current to right bottom
	{
		if (m_board[curRow + idx][curCol + idx] == currentCell)
			countCellsSameVal++;
		else if (m_board[curRow + idx][curCol + idx] == ' ')
			break;
		else
		{
			countCellsDiffVal++;
			break;
		}
	}
	for (int idx = 1; curCol - idx >= 0 && curRow - idx >= 0; ++idx) // check from current to left top
	{
		if (m_board[curRow - idx][curCol - idx] == currentCell)
			countCellsSameVal++;
		else if (m_board[curRow - idx][curCol - idx] == ' ')
			break;
		else
		{
			countCellsDiffVal++;
			break;
		}
	}
	if (countCellsDiffVal == 2)
		return false;
	if (countCellsSameVal >= NUMS_TO_WIN - 1)
		return true;

	// no conditions are satisfied return false
	return false;
}

// Check win don't block the two ends
//bool Board::CheckWinCondition(int i, int j)
//{
//	// vars to check
//	int count = 0;
//	int row = i;
//	int col;
//	// ---- check col ----
//	while (row < ROW_SIZE && m_board[row][j] == m_board[i][j]) // check row from current to bottom
//	{ 
//		count++;
//		row++;
//	}
//	row = i - 1;
//	while (row >= 0 && m_board[row][j] == m_board[i][j]) // check row from current to top
//	{ 
//		count++;
//		row--;
//	}
//	if (count >= NUMS_TO_WIN)
//		return true;
//
//	// reset vars to check
//	count = 0; 
//	col = j;
//	// ---- check row ----
//	while (col < COL_SIZE && m_board[i][col] == m_board[i][j]) // check col from current to right
//	{ 
//		count++;
//		col++;
//	}
//	col = j - 1;
//	while (col >= 0 && m_board[i][col] == m_board[i][j]) // check col from current to left
//	{ 
//		count++;
//		col--;
//	}
//	if (count >= NUMS_TO_WIN)
//		return true;
//
//	// reset vars to check
//	row = i; 
//	col = j; 
//	count = 0;
//	// check diagonal backslash
//	while (row < ROW_SIZE && col < COL_SIZE && m_board[i][j] == m_board[row][col]) // check diagonal from current to right bottom
//	{  
//		count++;
//		row++;
//		col++;
//	}
//	row = i - 1; 
//	col = j - 1;
//	while (row >= 0 && col >= 0 && m_board[i][j] == m_board[row][col]) // check diagonal from current to top left
//	{ 
//		count++;
//		row--;
//		col--;
//	}
//	if (count >= NUMS_TO_WIN)
//		return true;
//
//	// reset vars to check
//	row = i; 
//	col = j; 
//	count = 0;
//	// check diagonal forwardslash
//	while (row < ROW_SIZE && col >= 0 && m_board[i][j] == m_board[row][col]) // check diagonal from current to left bottom
//	{
//		count++;
//		row++;
//		col--;
//	}
//	row = i - 1; 
//	col = j + 1;
//	while (row >= 0 && col < COL_SIZE && m_board[i][j] == m_board[row][col]) // check diagonal from current to top right
//	{
//		count++;
//		row--;
//		col++;
//	}
//	if (count >= NUMS_TO_WIN)
//		return true;
//
//	// no conditions are satisfied return false
//	return false;
//}

bool Board::CheckDrawCondition()
{
	return (m_nTotalCells == 0);
}

int Board::CheckStateGame()
{
	int count = 0;

	for (int i = 0; i < ROW_SIZE; ++i)
	{
		for (int j = 0; j < COL_SIZE; ++j)
		{
			if (!CheckCellIsEmpty(i, j))
			{
				if (CheckWinCondition(i, j) && m_board[i][j] == 'X')
				{
					return MAX_VALUE;
				}
				if (CheckWinCondition(i, j) && m_board[i][j] == 'O')
				{
					return MIN_VALUE;
				}
			}
			else
				count++;
		}
	}

	if (count == 0)
		return DRAW_VALUE;

	return -1;
}
