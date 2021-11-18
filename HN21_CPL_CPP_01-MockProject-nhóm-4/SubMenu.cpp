#include "SubMenu.h"


SubMenu::SubMenu()
{
	m_strOptions.push_back("Easy Mode");
	m_strOptions.push_back("Normal Mode");
	m_strOptions.push_back("Hard Mode");
	m_strOptions.push_back("Back to MAIN MENU");
}

void SubMenu::DisplayOnTheScreen()
{
	cout << "*-------MAIN MENU-------*\n";
	for (int i = 0; i < m_strOptions.size(); ++i)
	{
		cout << (i + 1) << ". " << m_strOptions[i] << "\n";
	}
}

int SubMenu::SelectOption()
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