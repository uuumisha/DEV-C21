#include "inc\Source.h"
#include <algorithm>

bool PairEven(const pair<const string, int> &p) {
	return !(p.second % 2);
}

bool PairUnEven(const pair<const string, int> &p) {
	return p.second % 2;
}

ostream& operator<<(ostream &os, const std::pair<string, int>& p) {
	os << p.first << "	" << p.second;
	return os;
}

string MyStringToLower(string &str) {
	transform(str.begin(), str.end(), str.begin(), tr_my_tolower);
	return str;
}

char tr_my_tolower(char ch) {
	if ((ch <= 'Z') && (ch >= 'A'))
		return ch - ('Z' - 'z');
	return ch;
}