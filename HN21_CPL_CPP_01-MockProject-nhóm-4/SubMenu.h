#pragma once
#include <iostream>
#include <vector>

using namespace std;

class SubMenu
{
private:
	vector<string> m_strOptions;
public:
	SubMenu();
	void DisplayOnTheScreen();
	int SelectOption();
};

