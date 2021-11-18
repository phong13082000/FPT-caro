#include "ListPlayer.h"

ListPlayer::ListPlayer()
{
	
}

ListPlayer::~ListPlayer()
{
	
}

bool ListPlayer::ComparePlayerForSort(Player& a, Player& b)
{
	int scoreA = a.GetNumsWin() * 3 + a.GetNumsDraw() * 1 + a.GetNumsLose() * (-2);
	int scoreB = b.GetNumsWin() * 3 + b.GetNumsDraw() * 1 + b.GetNumsLose() * (-2);

	return (scoreA > scoreB);
}

void ListPlayer::DisplayPlayerList()
{
	ifstream infile;
	infile.open("data-users.txt", ios::in);
	string line;
	string delimiter = " ";
	string name;
	int numsWin = 0;
	int numsDraw = 0;
	int numsLose = 0;
	while (!infile.eof())
	{
		getline(infile, line);

		int index = 0;
		if (line.length() != 0)
		{
			int start = 0;
			int end = line.find(delimiter);
			while (end != -1) {
				if (index == 0)
					name = line.substr(start, end - start);
				else if (index == 1)
					numsWin = stoi(line.substr(start, end - start));
				else if (index == 2)
					numsDraw = stoi(line.substr(start, end - start));
				start = end + delimiter.size();
				end = line.find(delimiter, start);
				index++;
			}
			numsLose = stoi(line.substr(start, end - start));

			m_vecPlayerList.push_back(Player(name, numsWin, numsDraw, numsLose));
		}
	}

	const int width = 15;
	cout << "--- List Players ---\n";
	cout << left << setw(width) << setfill(' ') << "Name"
		<< left << setw(width) << setfill(' ') << "Win"
		<< left << setw(width) << setfill(' ') << "Draw"
		<< left << setw(width) << setfill(' ') << "Lose";
	cout << endl;
	for (int i = 0; i < m_vecPlayerList.size(); ++i)
	{
		cout << left << setw(width) << setfill(' ') << m_vecPlayerList[i].GetName();
		cout << left << setw(width) << setfill(' ') << m_vecPlayerList[i].GetNumsWin();
		cout << left << setw(width) << setfill(' ') << m_vecPlayerList[i].GetNumsDraw();
		cout << left << setw(width) << setfill(' ') << m_vecPlayerList[i].GetNumsLose();
		cout << "\n";
	}

}

void ListPlayer::UpdateUser(string name, int addWin, int addDraw, int addLose)
{
	ifstream infile;
	infile.open("data-users.txt", ios::in);
	ofstream temp;
	temp.open("temp.txt");
	string line;
	string delimiter = " ";
	string nameInLine;
	int numsWin = 0;
	int numsDraw = 0;
	int numsLose = 0;
	bool check = false;
	while (!infile.eof())
	{
		getline(infile, line);
		
		int index = 0;
		string tmp = line;
		if (tmp.length() != 0)
		{
			int start = 0;
			int end = tmp.find(delimiter);
			while (end != -1) 
			{
				if (index == 0)
				{
					nameInLine = tmp.substr(start, end - start);
				}
				else if (index == 1)
				{
					numsWin = stoi(tmp.substr(start, end - start));
				}
				else if (index == 2)
				{
					numsDraw = stoi(tmp.substr(start, end - start));
				}
				start = end + delimiter.size();
				end = tmp.find(delimiter, start);
				index++;
			}
			numsLose =  stoi(tmp.substr(start, end - start));

			if (nameInLine == name)
			{
				check = true;
				temp << name << " " << to_string(addWin + numsWin) << " " << to_string(addDraw + numsDraw) << " " << to_string(addLose + numsLose) << "\n";
			}
			else
			{
				temp << line << endl;
			}
		}
	}
	if (check == false)
		temp << name << " " << to_string(addWin) << " " << to_string(addDraw) << " " << to_string(addLose) << "\n";
	temp.close();
	infile.close();

	remove("data-users.txt");
	rename("temp.txt", "data-users.txt");

}

void ListPlayer::SearchPlayerByName(string name)
{
	bool check = false;
	const int width = 15;
	cout << left << setw(width) << setfill(' ') << "Name"
		<< left << setw(width) << setfill(' ') << "Win"
		<< left << setw(width) << setfill(' ') << "Draw"
		<< left << setw(width) << setfill(' ') << "Lose";
	cout << endl;
	for (int i = 0; i < m_vecPlayerList.size(); ++i)
	{
		if (m_vecPlayerList[i].GetName() == name)
		{
			check = true;
			cout << left << setw(width) << setfill(' ') << m_vecPlayerList[i].GetName();
			cout << left << setw(width) << setfill(' ') << m_vecPlayerList[i].GetNumsWin();
			cout << left << setw(width) << setfill(' ') << m_vecPlayerList[i].GetNumsDraw();
			cout << left << setw(width) << setfill(' ') << m_vecPlayerList[i].GetNumsLose();
			cout << "\n";
			break;
		}
	}

	if (!check)
		cout << "Player not exist!\n";
}