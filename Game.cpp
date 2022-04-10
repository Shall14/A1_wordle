//#include<bits/stdc++.h>
#include<string>
#include<vector>
#include<map>
#include<array>
#include <iostream>
using namespace std;
#include <iosfwd>

#include "Session.h"
#include "Game.h"


// Firstly this function will be called by the main and after that depending on the inputs entered by the user it will call the other functions


Game::Game() :guessArray(6) {
}

void Game::startGame() {
	cout << "\nWelcome To Werdle.\n";
	cout << "Select An Option:\n\n\n";
	cout << "1. Play A Game\n";
	cout << "2. View Statistic\n";
	cout << "3. View Help\n";
	cout << ">  ";
	cin >> choice;


	if (choice == 1)
		playGame();
	else if (choice == 2)
		viewStatistic();
	else
		viewHelp();
}

void Game::playGame() {

	totalPlayed++;

	unique_ptr<session> s = make_unique<session>();
	numberOfTurns = s->getTurns();

	if (numberOfTurns != 7)
	{
		totalWin++;
		currentStreak++;
		maxStreak = max(maxStreak, currentStreak);
		guessArray[numberOfTurns - 1]++;
	}
	else
		currentStreak = 0;

	startGame();
}

void Game::viewStatistic() {

	cout << "\n";
	cout << "Played: " << totalPlayed << "  ";

	int winpercentage;
	if (totalPlayed == 0)
		winpercentage = 0;
	else
		winpercentage = (totalWin / (double)totalPlayed) * 100;

	cout << "Win%: " << winpercentage << "%  ";

	cout << "Current Streak:" << " " << currentStreak << "  " << " Max streak: " << maxStreak << endl;
	cout << "\n\n";

	cout << "GUESS DISTRIBUTION\n";

	for (int i = 0; i < 6; i++)
		cout << i + 1 << ": " << guessArray[i] << "\n";
	cout << "\n\n";

	startGame();
}

void Game::viewHelp() {

	cout << "\n\nGuess the WERDLE in six tries.\n\n";
	cout << "Each guess must be a five-letter word. Hit the enter button to submit.\n";
	cout << "Examples\n\n";
	cout << "[A] P P L E\n";
	cout << "The letter A is in the correct position.\n\n";
	cout << "D |E| A L T\n";
	cout << "The letter E is in the word but in the wrong position.\n\n";
	startGame();

}


