#ifndef GUESS_H
#define GUESS_H
//#include<bits/stdc++.h>
#include<string>
#include<vector>
#include<map>
#include<array>
#include <iostream>
using namespace std;
#include <iosfwd>

class guess
{
public:
	int numberOfTurns;

	guess(string word);
	int getTurns();
	bool guessTheWord(string wordFromUser, string word, vector<string>& allGuesses);
};
#endif
