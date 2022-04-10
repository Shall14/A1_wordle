#ifndef GAME_H
#define GAME_H
#include<iostream>
using namespace std;
//#include<bits/stdc++.h>
#include<string>
#include<vector>
#include<map>
#include<array>
#include<iosfwd>

class Game {
public:

	int choice, numberOfTurns, currentStreak = 0, maxStreak = 0, totalPlayed = 0, totalWin = 0;
	vector<int> guessArray;

	Game();

	void startGame();
	void playGame();
	void viewStatistic();
	void viewHelp();
};
#endif
