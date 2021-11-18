#pragma once


class Move
{
private:
	int m_nX, m_nY;
	char m_type;
public:
	Move();
	Move(int, int);
	Move(int, int, char);
	~Move();
	void SetX(int);
	void SetY(int);
	void SetType(char);
	char GetType();
	int GetX();
	int GetY();
};

