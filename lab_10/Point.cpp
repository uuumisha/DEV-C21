#include "inc\Point.h"
#include <utility>

// Конструкторы

Point::Point(int x, int y) {
	m_x = x;
	m_y = y;
}

// Операторы через методы класса
Point Point::operator +(const Point &other) const {
	Point tmp(m_x + other.m_x, m_y + other.m_y);
	return tmp;
}

Point Point::operator +(int val) const {
	Point tmp(m_x + val, m_y + val);
	return tmp;
}

bool Point::operator ==(const Point &other) const {
	if ((m_x == other.m_x) && (m_y == other.m_y))
		return true;
	else
		return false;
}

bool Point::operator <(const Point &other) const {
	return ((m_x*m_x + m_y*m_y) < (other.m_x*other.m_x + other.m_y*other.m_y));
}

Point& Point::operator +=(const Point &other) {
	this->operator+(other);
	return *this;
}

Point& Point::operator +=(int val) {
	this->operator+(val);
	return *this;
}

Point Point::operator -() {
	Point tmp(-m_x, -m_y);
	return tmp;
}

Point& Point::operator +() {
	return *this;
}

Point& Point::operator -(int delta) {
	m_x -= delta;
	m_y -= delta;
	return *this;
}

// Операторы через глобальные функции

Point operator -(Point &pt1, const Point & pt2) {
	Point tmp(pt1.m_x - pt2.m_x, pt1.m_y - pt2.m_y);
	return tmp;
}

Point operator -(Point &pt1, int val) {
	Point tmp(pt1.m_x - val, pt1.m_y - val);
	return tmp;
}

Point& operator-=(Point &pt1, int val) {
	pt1.operator-(val);
	return pt1;
}

Point& operator-=(Point &pt1, const Point &pt2) {
	operator-(pt1, pt2);
	return pt1;
}

Point operator +(int val, Point &pt1) {
	Point tmp(pt1.m_x + val, pt1.m_y + val);
	return tmp;
}

ostream& operator<<(ostream &os, const Point& p) {
	os << "( " << p.m_x << " " << p.m_y << " )";
	return os;
}

ostream& operator<<(ostream &os, const Point* p) {
	os << "( " << p->m_x << " " << p->m_y << " )";
	return os;
}

bool Compare(const Point& left, const Point& right) {
	return left < right;
}

bool IsNegative(const Point& p) {
	return ((p.m_x < 0) || (p.m_y < 0));
}

bool Point::IsInDiapason(int left, int right) const {
	return (m_x > left) && (m_y > left) && (m_x < right) && (m_y < right);
}