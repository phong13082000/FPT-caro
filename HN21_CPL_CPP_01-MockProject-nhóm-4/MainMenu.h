#pragma once
#include <iostream>
#include <vector>

using namespace std;

class MainMenu
{
private:
	vector<string> m_strOptions;
public:
	MainMenu();
	void DisplayOnTheScreen();
	int SelectOption();
};

