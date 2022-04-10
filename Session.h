#ifndef SESSION_H
#define SESSION_H
//#include<bits/stdc++.h>
#include<string>
#include<vector>
#include<map>
#include<array>
#include <iostream>
using namespace std;
#include <iosfwd>

class session {

public:
	static int numberOfSessions;
	int numberOfTurns;
	session();
	int getTurns();
};
#endif
