#include "GameField.h"

GameField::GameField()
{
	
}

GameField::~GameField() {}

Player GameField::GetPlayer1()
{
	return m_player1;
}

Player GameField::GetPlayer2()
{
	return m_player2;
}

Board GameField::GetBoard()
{
	return m_board;
}


// --- Start Heuritic Algorithm ---
Move GameField::BestMoveHeuristic()
{
	long bestScore = INT_MIN;
	int x = 0, y = 0;
	for (int i = 0; i < ROW_SIZE; ++i)
	{
		for (int j = 0; j < COL_SIZE; ++j)
		{
			// Heuritic
			if (m_board.CheckCellIsEmpty(i, j))
			{
				long attackPoint = AttackPointRow(i, j) + AttackPointColumn(i, j) + AttackPointBackSlash(i, j) + AttackPointForwardSlash(i, j);
				long defensePoint = DefensePointRow(i, j) + DefensePointColumn(i, j) + DefensePointBackSlash(i, j) + DefensePointForwardSlash(i, j);
				long score = max(attackPoint, defensePoint);
				if (score > bestScore)
				{
					bestScore = score;
					x = i;
					y = j;
				}
			}
		}
	}
	return Move(x, y);
}

long GameField::AttackPointRow(int curRow, int curCol)
{
	long point = 0;
	int numsOfMovePlayer = 0;
	int numsOfMoveAI = 0;

	for (int count = 1; count < NUMS_TO_WIN && curCol + count < COL_SIZE; ++count)
	{
		if (m_board.GetValueCell(curRow, curCol + count) == 'X')
		{
			numsOfMovePlayer++;
			break;
		}
		else if (m_board.GetValueCell(curRow, curCol + count) == 'O')
		{
			numsOfMoveAI++;
		}
		else
			break;
	}

	for (int count = 1; count < 5 && curCol - count >= 0; ++count)
	{
		if (m_board.GetValueCell(curRow, curCol - count) == 'X')
		{
			numsOfMovePlayer++;
			break;
		}
		else if (m_board.GetValueCell(curRow, curCol - count) == 'O')
		{
			numsOfMoveAI++;
		}
		else
			break;
	}

	if (numsOfMovePlayer == 2)
		return 0;

	point -= m_arrDefensePoints[numsOfMovePlayer + 1];
	point += m_arrAttackPoints[numsOfMoveAI];

	return point;

}

long GameField::AttackPointColumn(int curRow, int curCol)
{
	long point = 0;
	int numsOfMovePlayer = 0;
	int numsOfMoveAI = 0;

	for (int count = 1; count < NUMS_TO_WIN && curRow + count < ROW_SIZE; ++count)
	{
		if (m_board.GetValueCell(curRow + count, curCol) == 'X')
		{
			numsOfMovePlayer++;
			break;
		}
		else if (m_board.GetValueCell(curRow + count, curCol) == 'O')
		{
			numsOfMoveAI++;
		}
		else
			break;
	}

	for (int count = 1; count < 5 && curRow - count >= 0; ++count)
	{
		if (m_board.GetValueCell(curRow - count, curCol) == 'X')
		{
			numsOfMovePlayer++;
			break;
		}
		else if (m_board.GetValueCell(curRow - count, curCol) == 'O')
		{
			numsOfMoveAI++;
		}
		else
			break;
	}

	if (numsOfMovePlayer == 2)
		return 0;

	point -= m_arrDefensePoints[numsOfMovePlayer + 1];
	point += m_arrAttackPoints[numsOfMoveAI];

	return point;
}

long GameField::AttackPointBackSlash(int curRow, int curCol)
{
	long point = 0;
	int numsOfMovePlayer = 0;
	int numsOfMoveAI = 0;

	for (int count = 1; count < NUMS_TO_WIN && curRow + count < ROW_SIZE && curCol - count >= 0; ++count)
	{
		if (m_board.GetValueCell(curRow + count, curCol - count) == 'X')
		{
			numsOfMovePlayer++;
			break;
		}
		else if (m_board.GetValueCell(curRow + count, curCol - count) == 'O')
		{
			numsOfMoveAI++;
		}
		else
			break;
	}

	for (int count = 1; count < 5 && curRow - count >= 0 && curCol + count < COL_SIZE; ++count)
	{
		if (m_board.GetValueCell(curRow - count, curCol + count) == 'X')
		{
			numsOfMovePlayer++;
			break;
		}
		else if (m_board.GetValueCell(curRow - count, curCol + count) == 'O')
		{
			numsOfMoveAI++;
		}
		else
			break;
	}

	if (numsOfMovePlayer == 2)
		return 0;

	point -= m_arrDefensePoints[numsOfMovePlayer + 1];
	point += m_arrAttackPoints[numsOfMoveAI];

	return point;
}

long GameField::AttackPointForwardSlash(int curRow, int curCol)
{
	long point = 0;
	int numsOfMovePlayer = 0;
	int numsOfMoveAI = 0;

	for (int count = 1; count < NUMS_TO_WIN && curRow + count < ROW_SIZE && curCol + count <= COL_SIZE; ++count)
	{
		if (m_board.GetValueCell(curRow + count, curCol + count) == 'X')
		{
			numsOfMovePlayer++;
			break;
		}
		else if (m_board.GetValueCell(curRow + count, curCol + count) == 'O')
		{
			numsOfMoveAI++;
		}
		else
			break;
	}

	for (int count = 1; count < 5 && curRow - count >= 0 && curCol + count >= 0; ++count)
	{
		if (m_board.GetValueCell(curRow - count, curCol - count) == 'X')
		{
			numsOfMovePlayer++;
			break;
		}
		else if (m_board.GetValueCell(curRow - count, curCol - count) == 'O')
		{
			numsOfMoveAI++;
		}
		else
			break;
	}

	if (numsOfMovePlayer == 2)
		return 0;

	point -= m_arrDefensePoints[numsOfMovePlayer + 1];
	point += m_arrAttackPoints[numsOfMoveAI];

	return point;
}

long GameField::DefensePointRow(int curRow, int curCol)
{
	long point = 0;
	int numsOfMovePlayer = 0;
	int numsOfMoveAI = 0;

	for (int count = 1; count < NUMS_TO_WIN && curCol + count < COL_SIZE; ++count)
	{
		if (m_board.GetValueCell(curRow, curCol + count) == 'X')
		{
			numsOfMovePlayer++;
		}
		else if (m_board.GetValueCell(curRow, curCol + count) == 'O')
		{
			numsOfMoveAI++;
			break;
		}
		else
			break;
	}

	for (int count = 1; count < 5 && curCol - count >= 0; ++count)
	{
		if (m_board.GetValueCell(curRow, curCol - count) == 'X')
		{
			numsOfMovePlayer++;
		}
		else if (m_board.GetValueCell(curRow, curCol - count) == 'O')
		{
			numsOfMoveAI++;
			break;
		}
		else
			break;
	}

	if (numsOfMoveAI == 2)
		return 0;

	//point -= m_arrAttackPoints[numsOfMoveAI + 1];

	point += m_arrDefensePoints[numsOfMovePlayer];

	return point;
}

long GameField::DefensePointColumn(int curRow, int curCol)
{
	long point = 0;
	int numsOfMovePlayer = 0;
	int numsOfMoveAI = 0;

	for (int count = 1; count < NUMS_TO_WIN && curRow + count < ROW_SIZE; ++count)
	{
		if (m_board.GetValueCell(curRow + count, curCol) == 'X')
		{
			numsOfMovePlayer++;
		}
		else if (m_board.GetValueCell(curRow + count, curCol) == 'O')
		{
			numsOfMoveAI++;
			break;
		}
		else
			break;
	}

	for (int count = 1; count < 5 && curRow - count >= 0; ++count)
	{
		if (m_board.GetValueCell(curRow - count, curCol) == 'X')
		{
			numsOfMovePlayer++;
		}
		else if (m_board.GetValueCell(curRow - count, curCol) == 'O')
		{
			numsOfMoveAI++;
			break;
		}
		else
			break;
	}

	if (numsOfMoveAI == 2)
		return 0;

	//point -= m_arrAttackPoints[numsOfMoveAI + 1];
	point += m_arrDefensePoints[numsOfMovePlayer];

	return point;
}

long GameField::DefensePointBackSlash(int curRow, int curCol)
{
	long point = 0;
	int numsOfMovePlayer = 0;
	int numsOfMoveAI = 0;

	for (int count = 1; count < NUMS_TO_WIN && curRow + count < ROW_SIZE && curCol - count >= 0; ++count)
	{
		if (m_board.GetValueCell(curRow + count, curCol - count) == 'X')
		{
			numsOfMovePlayer++;
		}
		else if (m_board.GetValueCell(curRow + count, curCol - count) == 'O')
		{
			numsOfMoveAI++;
			break;
		}
		else
			break;
	}

	for (int count = 1; count < 5 && curRow - count >= 0 && curCol + count < COL_SIZE; ++count)
	{
		if (m_board.GetValueCell(curRow - count, curCol + count) == 'X')
		{
			numsOfMovePlayer++;
		}
		else if (m_board.GetValueCell(curRow - count, curCol + count) == 'O')
		{
			numsOfMoveAI++;
			break;
		}
		else
			break;
	}

	if (numsOfMoveAI == 2)
		return 0;

	//point -= m_arrAttackPoints[numsOfMoveAI + 1];
	point += m_arrDefensePoints[numsOfMovePlayer];

	return point;
}

long GameField::DefensePointForwardSlash(int curRow, int curCol)
{
	long point = 0;
	int numsOfMovePlayer = 0;
	int numsOfMoveAI = 0;

	for (int count = 1; count < NUMS_TO_WIN && curRow + count < ROW_SIZE && curCol + count <= COL_SIZE; ++count)
	{
		if (m_board.GetValueCell(curRow + count, curCol + count) == 'X')
		{
			numsOfMovePlayer++;
		}
		else if (m_board.GetValueCell(curRow + count, curCol + count) == 'O')
		{
			numsOfMoveAI++;
			break;
		}
		else
			break;
	}

	for (int count = 1; count < 5 && curRow - count >= 0 && curCol + count >= 0; ++count)
	{
		if (m_board.GetValueCell(curRow - count, curCol - count) == 'X')
		{
			numsOfMovePlayer++;
		}
		else if (m_board.GetValueCell(curRow - count, curCol - count) == 'O')
		{
			numsOfMoveAI++;
			break;
		}
		else
			break;
	}

	if (numsOfMoveAI == 2)
		return 0;

	//point -= m_arrAttackPoints[numsOfMoveAI + 1];
	point += m_arrDefensePoints[numsOfMovePlayer];

	return point;
}
// --- End Heuritics Algorithm ---

// --- Start Minimax Algorithm ---
Move GameField::BestMoveMinimax()
{
	int bestScore = INT_MIN;
	int x = 0, y = 0;
	for (int i = 0; i < ROW_SIZE; ++i)
	{
		for (int j = 0; j < COL_SIZE; ++j)
		{
			if (m_board.CheckCellIsEmpty(i, j))
			{
				Move temp(i, j, 'O');
				m_board.UpdateBoard(temp);
				int score = Minimax(0, true);
				m_board.UpdateBoard(i, j);
				if (score > bestScore)
				{
					bestScore = score;
					x = i;
					y = j;
				}
			}
		}
	}
	return Move(x, y);
}

int GameField::Minimax(int depth, bool isMaximizing)
{
	int score = m_board.CheckStateGame();
	if (score != -1)
	{
		if (score == MAX_VALUE)
			return MAX_VALUE - depth;
		if (score == MIN_VALUE)
			return MIN_VALUE + depth;
		if (score == DRAW_VALUE)
			return DRAW_VALUE;
	}
	if (isMaximizing)
	{
		int bestVal = INT_MIN;
		for (int i = 0; i < ROW_SIZE; ++i)
		{
			for (int j = 0; j < COL_SIZE; ++j)
			{
				if (m_board.CheckCellIsEmpty(i, j))
				{
					m_board.UpdateBoard(Move(i, j, 'X'));
					int value = Minimax(depth + 1, !isMaximizing);
					bestVal = max(value, bestVal);
					m_board.UpdateBoard(i, j);
				}
			}
		}

		return bestVal;
	}
	else
	{
		int bestVal = INT_MAX;
		for (int i = 0; i < ROW_SIZE; ++i)
		{
			for (int j = 0; j < COL_SIZE; ++j)
			{
				if (m_board.CheckCellIsEmpty(i, j))
				{
					m_board.UpdateBoard(Move(i, j, 'O'));
					int value = Minimax(depth + 1, !isMaximizing);
					bestVal = min(value, bestVal);
					m_board.UpdateBoard(i, j);
				}
			}
		}

		return bestVal;
	}
}

// ---- End Minimax Algorithm ----