#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>
#include "Board.h"

using namespace std;

class Replay
{
private:
	ifstream m_ifsMatchReplay;
	string m_strFileName;
public:
	Replay();
	~Replay();
	void DisplayListReplay();
	void StartPlayback(int);
	int SelectOption(int);
};

