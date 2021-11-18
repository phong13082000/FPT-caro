#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include "GameField.h"
#include "MainMenu.h"
#include "SubMenu.h"
#include "Move.h"
#include "Contants.h"
#include "Recorder.h"
#include <ctime>
#include "Replay.h"
#include "ListPlayer.h"

using namespace std;

void GameMain();
void GamePlay2Player();
void SelectSubMenu();
void GamePlayWithBot(int);
void SelectReplay();
void DisplayUsers();
void DisplayGuide();
void DisplayAbout();
void ExitGame();

int main()
{
	GameMain();
	return 0;
}

void GameMain()
{
	MainMenu mainMenu;

	int userOptionSelect;

	// Loop game 
	while (1)
	{
		system("cls");
		mainMenu.DisplayOnTheScreen();
		userOptionSelect = mainMenu.SelectOption();

		switch (userOptionSelect)
		{
		case playWithOthers:
			GamePlay2Player();
			break;
		case playWithBot:
			SelectSubMenu();
			break;
		case replay:
			SelectReplay();
			break;
		case information:
			DisplayUsers();
			break;
		case guild:
			DisplayGuide();
			break;
		case about:
			DisplayAbout();
			break;
		case exitGame:
			ExitGame();
			break;
		}

		if (userOptionSelect == exitGame)
			break;
	}
}

void GamePlay2Player()
{
	cout << "Start game ...\n";
	this_thread::sleep_for(chrono::milliseconds(sleepTimes));

	// Clear Screen
	system("cls");
	// Init Game Field 
	GameField gameField;
	// Init record file
	Record record;
	string lineRecord;

	// Record id match
	int numsRecords = record.GetNumberRecords();
	lineRecord = "";
	lineRecord += to_string(numsRecords + 1);
	lineRecord += "\n";
	record.AddLine(lineRecord);

	// Record time
	lineRecord = "";
	time_t now = time(0);
	char str[26];
	ctime_s(str, sizeof str, &now);
	for (int i = 0; i < 25; ++i)
	{
		lineRecord += str[i];
	}
	//lineRecord += "\n";
	record.AddLine(lineRecord);

	// User input name
	string name;
	cout << "Enter name of Player 1's: ";
	cin >> name;

	// record name of player1
	lineRecord = "";
	lineRecord += name;
	lineRecord += "\n";
	record.AddLine(lineRecord);

	gameField.m_player1.SetName(name);
	cout << "Enter name of Player 2's: ";
	cin >> name;

	// record name of player1
	lineRecord = "";
	lineRecord += name;
	lineRecord += "\n";
	record.AddLine(lineRecord);

	gameField.m_player2.SetName(name);


	// Turn play
	// 0 is player1 (x)
	// 1 is player2 (o)
	int turn = 0;
	Move move;

	// Loop stage game
	while (true)
	{
		// Render Board
		system("cls");
		gameField.m_board.DisplayBoard();
		lineRecord = "";

		// User Input Move
		do
		{
			cout << "Player " << (turn + 1) << " " << ((!turn) ? gameField.m_player1.GetName() : gameField.m_player2.GetName()) << "'s turn: ";
			try
			{
				if (turn == 0)
				{
					move = gameField.m_player1.InputMove();
					move.SetType('X');
				}
				else
				{
					move = gameField.m_player2.InputMove();
					move.SetType('O');
				}
			}
			catch (...)
			{
				cout << "Invalid Input. PLay again\n";
				continue;
			}
			
			if (!gameField.m_board.CheckCellIsEmpty(move.GetX(), move.GetY()))
			{
				cout << "Invalid Input. Play again!\n";
				continue;
			}
			
			break;

		} while (1);

		// record Move
		lineRecord += to_string(move.GetX());
		lineRecord += " ";
		lineRecord += to_string(move.GetY());
		lineRecord += "\n";
		record.AddLine(lineRecord);


		// Update Board
		gameField.m_board.UpdateBoard(move);
		
		// Check win condition - break loop
		if (gameField.m_board.CheckWinCondition(move.GetX(), move.GetY()))
		{
			system("cls");
			gameField.m_board.DisplayBoard();
			cout << "Congratulations player " << (turn + 1) << " " << ((!turn) ? gameField.m_player1.GetName() : gameField.m_player2.GetName()) << " win!\n";

			// record player win
			lineRecord = "";
			lineRecord += ((!turn) ? gameField.m_player1.GetName() : gameField.m_player2.GetName());
			lineRecord += " win\n";
			record.AddLine(lineRecord);

			// Write record to file
			Recorder recorder;
			recorder.WriteToFile(record);

			// Add player to file
			ListPlayer listPlayer;
			if (!turn)
			{
				listPlayer.UpdateUser(gameField.m_player1.GetName(), 1, 0, 0);
				listPlayer.UpdateUser(gameField.m_player2.GetName(), 0, 0, 1);
			}
			else
			{
				listPlayer.UpdateUser(gameField.m_player2.GetName(), 1, 0, 0);
				listPlayer.UpdateUser(gameField.m_player1.GetName(), 0, 0, 1);
			}

			this_thread::sleep_for(chrono::milliseconds(sleepTimes));
			break;
		}

		// Check draw condition - break loop
		if (gameField.m_board.CheckDrawCondition())
		{
			system("cls");
			gameField.m_board.DisplayBoard();
			cout << "Game draw!\n";

			// record draw
			lineRecord = "";
			lineRecord += "Game draw\n";
			record.AddLine(lineRecord);

			// Write record to file
			Recorder recorder;
			recorder.WriteToFile(record);

			// Add player to file
			ListPlayer listPlayer;
			listPlayer.UpdateUser(gameField.m_player1.GetName(), 0, 1, 0);
			listPlayer.UpdateUser(gameField.m_player2.GetName(), 0, 1, 0);

			this_thread::sleep_for(chrono::milliseconds(sleepTimes));
			break;
		}

		// Update turn of player
		turn++;
		turn %= 2;
	}
}

void SelectSubMenu()
{
	SubMenu subMenu;
	int userOptionSelect;
	while (1)
	{
		system("cls");
		subMenu.DisplayOnTheScreen();
		userOptionSelect = subMenu.SelectOption();

		switch (userOptionSelect)
		{
		case easyMode:
			GamePlayWithBot(0);
			break;
		case normalMode:
			GamePlayWithBot(1);
			break;
		case hardMode:
			GamePlayWithBot(2);
			break;
		case backToMainMenu:
			break;
		}

		if (userOptionSelect == backToMainMenu)
			break;
	}
}

void GamePlayWithBot(int mode)
{
	cout << "Start game ...\n";
	this_thread::sleep_for(chrono::milliseconds(sleepTimes));

	// Clear Screen
	system("cls");
	// Init Game Field 
	GameField gameField;

	// Init record file
	Record record;
	string lineRecord;

	// Record id match
	int numsRecords = record.GetNumberRecords();
	lineRecord = "";
	lineRecord += to_string(numsRecords + 1);
	lineRecord += "\n";
	record.AddLine(lineRecord);

	// Record time start game
	lineRecord = "";
	time_t now = time(0);
	char str[26];
	ctime_s(str, sizeof str, &now);
	for (int i = 0; i < 25; ++i)
	{
		lineRecord += str[i];
	}
	//lineRecord += "\n";
	record.AddLine(lineRecord);

	// User input name
	string name;
	cout << "Enter name of Player : ";
	cin >> name;
	gameField.m_player1.SetName(name);

	// record name of player1
	lineRecord = "";
	lineRecord += name;
	lineRecord += "\n";
	record.AddLine(lineRecord);

	if (mode == 0)
	{
		name = "BOT EASY";
	}
	else if (mode == 1)
	{
		name = "BOT NORMAL";
	}
	else if (mode == 2)
	{
		name = "BOT HARD";
	}
	gameField.m_player2.SetName(name);

	// record name of player2 BOT
	lineRecord = "";
	lineRecord += name;
	lineRecord += "\n";
	record.AddLine(lineRecord);

	// Turn play
	// 0 is player1 (x)
	// 1 is player2 (o)
	int turn = 0;
	Move move;

	// Loop stage game
	while (true)
	{
		// Render Board
		system("cls");
		gameField.m_board.DisplayBoard();
		lineRecord = "";

		// User Input
		do
		{
			cout << "Player " << (turn + 1) << " " << ((!turn) ? gameField.m_player1.GetName() : gameField.m_player2.GetName()) << "'s turn: ";

			if (turn == 0)
			{
				try
				{
					move = gameField.m_player1.InputMove();
					move.SetType('X');
				}
				catch (...)
				{
					cout << "Invalid Input. PLay again\n";
					continue;
				}

				if (!gameField.m_board.CheckCellIsEmpty(move.GetX(), move.GetY()))
				{
					cout << "Invalid Input. Play again!\n";
					continue;
				}

			}
			else
			{
				if (mode == 0)
				{
					move = gameField.BestMoveHeuristic();
					move.SetType('O');
				}
				else if (mode == 1)
				{
					move = gameField.BestMoveHeuristic();
					move.SetType('O');
				}
				else if (mode == 2)
				{
					move = gameField.BestMoveHeuristic();
					move.SetType('O');
				}

			}

			break;

		} while (1);

		// Record Move
		lineRecord += to_string(move.GetX());
		lineRecord += " ";
		lineRecord += to_string(move.GetY());
		lineRecord += "\n";
		record.AddLine(lineRecord);

		// Update Board
		gameField.m_board.UpdateBoard(move);


		// Check win condition - break loop
		if (gameField.m_board.CheckWinCondition(move.GetX(), move.GetY()))
		{
			system("cls");
			gameField.m_board.DisplayBoard();
			cout << "Congratulations player " << (turn + 1) << " " << ((!turn) ? gameField.m_player1.GetName() : gameField.m_player2.GetName()) << " win!\n";

			// record player win
			lineRecord = "";
			lineRecord += ((!turn) ? gameField.m_player1.GetName() : gameField.m_player2.GetName());
			lineRecord += " win\n";
			record.AddLine(lineRecord);

			// Add player to file
			ListPlayer listPlayer;
			if (turn == 0)
				listPlayer.UpdateUser(gameField.m_player1.GetName(), 1, 0, 0);
			else
				listPlayer.UpdateUser(gameField.m_player1.GetName(), 0, 0, 1);

			// Write record to file
			Recorder recorder;
			recorder.WriteToFile(record);

			this_thread::sleep_for(chrono::milliseconds(sleepTimes));
			break;
		}

		// Check draw condition - break loop
		if (gameField.m_board.CheckDrawCondition())
		{
			system("cls");
			gameField.m_board.DisplayBoard();
			cout << "Game draw!\n";

			// record draw
			lineRecord = "";
			lineRecord += "Game draw\n";
			record.AddLine(lineRecord);

			// Add player to file
			ListPlayer listPlayer;
			listPlayer.UpdateUser(gameField.m_player1.GetName(), 0, 1, 0);

			// Write record to file
			Recorder recorder;
			recorder.WriteToFile(record);

			this_thread::sleep_for(chrono::milliseconds(sleepTimes));
			break;
		}

		// Update turn of player
		turn++;
		turn %= 2;
	}
}

void SelectReplay()
{
	Replay replay;
	int userOptionSelect;
	Record record;
	int numsOfRecords = record.GetNumberRecords();
	while (1)
	{
		system("cls");
		replay.DisplayListReplay();
		userOptionSelect = replay.SelectOption(numsOfRecords);

		replay.StartPlayback(userOptionSelect);

		if (userOptionSelect == 0)
			break;
	}
}

void DisplayUsers()
{
	ListPlayer listPlayer;
	system("cls");
	listPlayer.DisplayPlayerList();
	string name;
	do
	{
		cout << "Enter name to search ('0' to exit): ";
		cin >> name;

		if (name == "0")
			break;

		listPlayer.SearchPlayerByName(name);


	} while (1);

}

void DisplayGuide()
{
	system("cls");
	cout << "* * * Tutorial * * *\n";
	cout << "Nhap toa do cua vi tri ban muon danh ( tu 0 den 9)\n";
	cout << "Khong duoc phep nhap vao vi tri da duoc danh dau hoac ngoai pham vi ban co\n";
	cout << "Dieu kien de gianh chien thang la ben nao co duoc 4 quan lien tiep theo duong cheo, hang ngang hay cot doc truoc va chi bi chan mot dau\n";
	cout << "khi tat ca cac o da danh het thi 2 ben se hoa nhau\n";
	system("pause");
}

void DisplayAbout()
{
	system("cls");
	cout << "* * * About * * *\n";
	cout << "* Game caro 10 x 10 on console\n";
	cout << "* Product of group 4 of class HN21_CPL_CPP_01\n";
	cout << "* Members of group: \n";
	cout << "\tTuanNA137 - Nguyen Anh Tuan\n";
	cout << "\tTungLT43 - Le Thanh Tung\n";
	cout << "\tAnhNV80 - Nguyen Viet Anh\n";
	cout << "\tYenTT7 - Trinh Thi Yen\n";
	cout << "\tThunaVN2 - Vu Nhu Thuan\n";
	system("pause");
}

void ExitGame()
{
	cout << "Good Bye! See you later!\n";
	//this_thread::sleep_for(chrono::milliseconds(sleepTimes / 2));
}