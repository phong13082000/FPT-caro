#pragma once

#define ROW_SIZE 10
#define COL_SIZE 10
#define NUMS_TO_WIN 4
#define EASY_MODE 0
#define NORMAL_MODE 1
#define HARD_MODE 2
#define MAX_VALUE 100
#define MIN_VALUE -100
#define DRAW_VALUE 0

enum returnCodeMainMenu {
	playWithOthers = 1,
	playWithBot = 2,
	replay = 3,
	information = 4,
	guild = 5,
	about = 6,
	exitGame = 7
};

enum returnCodeSubMenu {
	easyMode = 1,
	normalMode = 2,
	hardMode = 3,
	backToMainMenu = 4
};

const unsigned int sleepTimes = 2000;