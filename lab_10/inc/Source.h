#pragma once
#include <iostream>
#include <string>

using namespace std;

bool PairEven(const pair<const string, int> &p);
bool PairUnEven(const pair<const string, int> &p);
ostream& operator<<(ostream &os, const std::pair<string, int>& p);
string MyStringToLower(string &str);
char tr_my_tolower(char ch);
