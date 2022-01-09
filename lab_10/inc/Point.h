#pragma once
#include <iostream>

using namespace std;

class Point {
	int m_x, m_y =1;
public:
	Point(int x = 0, int y = 0);
	void f() { return; };

	Point operator +(const Point &other) const;
	Point operator +(int val) const;

	Point& operator +=(const Point &other);
	Point& operator +=(int val);

	bool operator ==(const Point &other) const;
	bool operator <(const Point &other) const;
	bool operator >(const Point &other) const;

	bool IsInDiapason(int left, int right) const;

	Point operator -();
	Point& operator +();
	Point& operator -(int delta);

	friend Point operator -(Point &pt1, const Point & pt2);
	friend Point operator -(Point &pt1, int val);
	friend Point operator +(int val, Point &pt1);
	friend ostream& operator<<(ostream &os, const Point& p);
	friend ostream& operator<<(ostream &os, const Point* p);
	

	friend bool IsNegative(const Point& p);
};

Point operator -(Point &pt1, const Point & pt2);
Point operator -(Point &pt1, int val);

Point& operator-=(Point &pt1, const Point & pt2);
Point& operator-=(Point &pt1, int val);

Point operator +(int val, Point &pt1);

bool Compare(const Point& left, const Point& right);