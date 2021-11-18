#include "Replay.h"

Replay::Replay()
{
	m_strFileName = "match-records.txt";
	m_ifsMatchReplay.open(m_strFileName, ios::in);
	if (!m_ifsMatchReplay.is_open())
	{
		string errorStr = "File opening failed\n";
		throw errorStr;
	}
}

Replay::~Replay()
{
	m_ifsMatchReplay.close();
}

void Replay::DisplayListReplay()
{
	string line;
	int index = 0;
	cout << "--- List Replay ---\n";
	while (!m_ifsMatchReplay.eof())
	{
		getline(m_ifsMatchReplay, line);
		if (index == 1)
		{
			cout << line << " ";
			index++;
		}
		else if (index == 2)
		{
			cout << line << " vs ";
			index++;
		}
		else if (index == 3)
		{
			cout << line << "\n";
			index++;
		}
		if (line.length() == 1)
		{
			cout << line << ". ";
			index = 1;
		}
	}

}

int Replay::SelectOption(int numbersRecords)
{
	int option;
	while (1)
	{
		cout << "Press number to choice ('0' to exit): ";
		cin >> option;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid Input\n";
		}
		else if (!cin.fail())
		{
			if (option < 0 || option > numbersRecords)
			{
				cout << "Invalid Input\n";
			}
			else
				break;
		}
	}

	return option;
}

void Replay::StartPlayback(int idRecord)
{
	Board board;
	string line;
	bool start = false; // check game is start
	int index = 1; // index of line in file
	int turn = 0; // turn play
	string timePlay; // store time play of replay
	string namePlayer1;
	string namePlayer2;

	// reset pointer of file to beginning file
	m_ifsMatchReplay.clear();
	m_ifsMatchReplay.seekg(0);

	// Read file
	while (!m_ifsMatchReplay.eof())
	{
		getline(m_ifsMatchReplay, line);

		if (start)
		{
			if (index == 1)
			{
				timePlay += line;
				index++;
			}
			else if (index == 2)
			{
				namePlayer1 = line;
				index++;
			}
			else if (index == 3)
			{
				namePlayer2 = line;
				index++;
			}
			else
			{
				system("cls");
				cout << "Match " << timePlay << " " << namePlayer1 << " vs " << namePlayer2 << "\n";
				board.DisplayBoard(); 
				this_thread::sleep_for(chrono::milliseconds(500));

				int x, y;
				char val;
				if (line.length() == 3)
				{
					x = line[0] - '0';
					y = line[2] - '0';
					val = (turn == 0) ? 'X' : 'O';
					board.UpdateBoard(Move(x, y, val));
					turn += 1;
					turn %= 2;
				}
				else
				{
					cout << line << "\n";
					system("pause");
					break;
				}

			}
		}

		if (line.length() == 1 && line == to_string(idRecord))
		{
			start = true;
		}
	}

	// reset pointer of file to beginning file
	m_ifsMatchReplay.clear();
	m_ifsMatchReplay.seekg(0);

}

