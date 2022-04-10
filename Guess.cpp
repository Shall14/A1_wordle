//#include<bits/stdc++.h>
#include<string>
#include<vector>
#include<map>
#include<array>
#include <iostream>
using namespace std;
#include <iosfwd>

#include "Guess.h"


guess::guess(string word)
{
	vector<string> allGuesses;
	for (int turns = 0; turns < 6; turns++)
	{
		cout << "\nGuess > ";
		string wordFromUser;
		cin >> wordFromUser;

		if (wordFromUser.length() != 5)
		{
			cout << "Must guess a 5 letter word!" << endl;
			turns--;
			continue;
		}
		bool guessIsCorrect = guessTheWord(wordFromUser, word, allGuesses);

		if (guessIsCorrect)
		{
			if (turns == 0)
				cout << "Impossible!\n\n";
			else if (turns == 1)
				cout << "Amazing!\n\n";
			else if (turns == 2)
				cout << "Outstanding!\n\n";
			else if (turns == 3)
				cout << "Great!\n\n";
			else if (turns == 4)
				cout << "Nice One!\n\n";
			else if (turns == 5)
				cout << "You Got There!\n\n";
			else
				cout << "Try Again!\n\n";

			numberOfTurns = turns + 1;
			break;
		}
		else if (turns == 5)
		{
			cout << "\n\nCorrect Answer: " << word << "\n\n";
			numberOfTurns = turns + 2;
		}
	}

}

int guess::getTurns() {
	return numberOfTurns;
}

bool guess::guessTheWord(string wordFromUser, string word, vector<string>& allGuesses)
{
	int pos[5] = { 0, 0, 0, 0, 0 };


	map<char, int> mp;

	for (int i = 0; i < word.length(); i++)
		mp[word[i]]++;

	string ans[5];
	for (int i = 0; i < 5; i++)
		ans[i] = "";

	for (int i = 0; i < wordFromUser.length(); i++)
	{
		if (wordFromUser[i] == word[i])
		{
			pos[i] = 1;
			mp[word[i]]--;

			ans[i] += "[";
			ans[i] += word[i];
			ans[i] += "]";
		}
	}

	for (int i = 0; i < wordFromUser.length(); i++)
	{
		if (mp[wordFromUser[i]] && pos[i] != 1)
		{
			ans[i] += "|";
			ans[i] += wordFromUser[i];
			ans[i] += "|";
			mp[wordFromUser[i]]--;
		}
		else if (pos[i] != 1)
		{
			ans[i] += " ";
			ans[i] += wordFromUser[i];
			ans[i] += " ";
		}
	}

	string merging = "";

	for (int i = 0; i < 5; i++)
		merging += ans[i], merging += " ";

	allGuesses.push_back(merging);
	for (int i = 0; i < allGuesses.size(); i++)
		cout << allGuesses[i] << "\n";

	if (wordFromUser.compare(word) == 0)
		return true;

	return false;
}


