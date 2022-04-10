//#include<bits/stdc++.h>
#include<string>
#include<vector>
#include<map>
#include<array>
#include <iostream>
using namespace std;
#include <iosfwd>

#include "Session.h"
#include "Dictionary.h"
#include "Guess.h"

int session::numberOfSessions = 0;

session::session() {

	unique_ptr<Dictionary> d = make_unique<Dictionary>();
	string nextWordFromDic = d->getTheWord(numberOfSessions);

	unique_ptr<guess> g = make_unique<guess>(nextWordFromDic);

	numberOfSessions++;
	numberOfTurns = g->getTurns();
}

int session::getTurns() {
	return numberOfTurns;
}
