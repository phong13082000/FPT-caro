#include "Move.h"

Move::Move()
{

}

Move::Move(int x, int y)
{
	m_nX = x;
	m_nY = y;
}

Move::Move(int x, int y, char type)
{
	m_nX = x;
	m_nY = y;
	m_type = type;
}

Move::~Move()
{
}

void Move::SetX(int x)
{
	m_nX = x;
}

void Move::SetY(int y)
{
	m_nY = y;
}

void Move::SetType(char type)
{
	m_type = type;
}

char Move::GetType()
{
	return m_type;
}

int Move::GetX()
{
	return m_nX;
}

int Move::GetY()
{
	return m_nY;
}
