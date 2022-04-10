//#include<bits/stdc++.h>
#include<string>
#include<vector>
#include<map>
#include<array>
#include <iostream>
using namespace std;

#include "Game.h"
#include "Session.h"
#include "Dictionary.h"
#include "Guess.h"


int main() {

	// Creating a game pointer for starting the game
	unique_ptr<Game> g = make_unique<Game>();

	// It will call the function in the Game.cpp file 
	g->startGame();

	return 0;
}
