#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include "Player.h"

using namespace std;

class ListPlayer
{
private:
	vector<Player> m_vecPlayerList;
public:
	ListPlayer();
	~ListPlayer();
	bool ComparePlayerForSort(Player&, Player&);
	void DisplayPlayerList();
	void UpdateUser(string, int, int, int);
	void SearchPlayerByName(string);
};

