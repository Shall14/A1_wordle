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

	unique_ptr<Game> g = make_unique<Game>();
	g->startGame();

	return 0;
}
