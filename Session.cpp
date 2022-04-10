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

int session::numberOfSessions = 0; // To get the next string from the dictionary

session::session() {

	unique_ptr<Dictionary> d = make_unique<Dictionary>(); // To create dictionary pointer for accessing the functions
	string nextWordFromDic = d->getTheWord(numberOfSessions); // Getting the next string from the dictionary 

	unique_ptr<guess> g = make_unique<guess>(nextWordFromDic); // Creating a guess pointer for accessing the functions of guess class

	numberOfSessions++; // Increment the index for getting the next string from the dictionary
	numberOfTurns = g->getTurns();
}

int session::getTurns() {
	return numberOfTurns;
}
