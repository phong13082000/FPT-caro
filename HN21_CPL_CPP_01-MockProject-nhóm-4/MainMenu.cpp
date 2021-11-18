#include "MainMenu.h"
#include <iostream>

using namespace std;

MainMenu::MainMenu()
{
	m_strOptions.push_back("Play with Other Player");
	m_strOptions.push_back("Play with BOT");
	m_strOptions.push_back("Reply");
	m_strOptions.push_back("Player's Information");
	m_strOptions.push_back("Guide");
	m_strOptions.push_back("About");
	m_strOptions.push_back("Exit");
}

void MainMenu::DisplayOnTheScreen()
{
	cout << "*-------MAIN MENU-------*\n";
	for (int i=0; i<m_strOptions.size(); ++i) 
	{
		cout << (i+1) << ". " << m_strOptions[i] << "\n";
	}
}

int MainMenu::SelectOption()
{
	int option;
	while (1)
	{
		cout << "Press number to choice: ";
		cin >> option;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input\n";
		}
		else if (!cin.fail())
		{
			if (option < 1 || option > m_strOptions.size())
			{
				cout << "Invalid Input\n";
			}
			else
				break;
		}
	}
	return option;
}
