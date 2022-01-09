#include "inc\Rect.h"
#include <iostream>
#include <algorithm>

// Конструктор с параметрами
Rect::Rect(int left, int right, int top, int bottom, COLOR c) : Shape(c) {

	if (Check(left, right, top, bottom)) {
		std::cout << "Rect Constructor: wrong parameters. Now its were set to zero.\n";
		m_left		= 0;
		m_right		= 0;
		m_top		= 0;
		m_bottom	= 0;
	}
	else {
		m_left		= left;
		m_right		= right;
		m_top		= top;
		m_bottom	= bottom;
	}
}

// Конструктор без параметров
Rect::Rect() : Shape(RED) {
	m_left		= 0;
	m_right		= 0;
	m_top		= 0;
	m_bottom	= 0;
}

Rect::~Rect() {
	//std::cout << "Now I am in Rect's destructor!\n";
}

// Растяжение прямоугольника на 4 разные дельты
void Rect::InflateRect(int dleft, int dright, int dtop, int dbottom) {
	if (Check(m_left - dleft, m_right + dright, m_top + dtop, m_bottom + dbottom))
		std::cout << "Wrong delta parameters\n";
	else {
		m_left -= dleft;
		m_right += dright;
		m_top += dtop;
		m_bottom -= dbottom;
	}
}

// Конструктор копирования
Rect::Rect(const Rect &other) : Shape(other) {
	m_left		= other.m_left;
	m_right		= other.m_right;
	m_top		= other.m_top;
	m_bottom	= other.m_bottom;
}

// Растяжение прямоугольника на 2 разные дельты
void Rect::InflateRect(int dwidth, int dhight) {
	if (Check(m_left - dwidth, m_right + dwidth, m_top + dhight, m_bottom + dhight))
		std::cout << "Wrong delta parameters\n";
	else {
		m_left -= dwidth;
		m_right += dwidth;
		m_top += dhight;
		m_bottom -= dhight;
	}
}

// Задать private переменные (вершины)
void Rect::SetAll(int left, int right, int top, int bottom) {
	if (Check(left, right, top, bottom))
		std::cout << "SetAll: wrong parameters.\n";
	else {
		m_left = left;
		m_right = right;
		m_top = top;
		m_bottom = bottom;
	}
}

// Получить private переменные (вершины)
void Rect::GetAll(int &left, int &right, int &top, int &bottom) const {
	left = m_left;
	right = m_right;
	top = m_top;
	bottom = m_bottom;
}

void Rect::Inflate(int val) {
	if(val < 0)
		std::cout << "Sorry, we can't inflate with negative parameter" << std::endl;
	else {
		m_left -= val;
		m_right += val;
		m_top += val;
		m_bottom -= val;
	}
}

bool Rect::Check(int left, int right, int top, int bottom) {
	if ((left > right) || (bottom > top))
		return true;
	else
		return false;
}

double Rect::GetArea() const {
	return ((m_right - m_left) * (m_top - m_bottom));
}

double Rect::GetDistance() const {
	return sqrt((m_right-m_left)*(m_right - m_left) + (m_top - m_bottom)*(m_top - m_bottom));
}


Shape* Rect::Clone() const {
	return new Rect(*this);
}

std::ostream& operator<<(std::ostream& os, const Rect& r) {
	os << "Rect with vertexes: TopLeft(" << r.m_left << ", " << r.m_top << "), BottomRight(" << r.m_right << ", " << r.m_bottom << "). ";
	r.Shape::Print(os);
	return os;
}

void Rect::Print(std::ostream& os) const {
	os << *this;
}

bool Rect::operator==(const Shape& other) const {
	if (typeid(other) != typeid(Rect))
		return false;
	if (Shape::operator==(other))
		return false;
	return ((m_left == static_cast<const Rect&>(other).m_left) &&
		(m_right == static_cast<const Rect&>(other).m_right) &&
		(m_top == static_cast<const Rect&>(other).m_top) &&
		(m_bottom == static_cast<const Rect&>(other).m_bottom));
}

Rect& Rect::operator=(const Rect& other) {
	Shape::operator=(other);
	m_left = other.m_left;
	m_right = other.m_right;
	m_top = other.m_top;
	m_bottom = other.m_bottom;
	return *this;
}

Shape& Rect::operator=(const Shape& other) {
	return static_cast<Shape&>(operator=(static_cast<const Rect&>(other)));
}

bool CopmareRects(const Rect& r1, const Rect& r2) {
	return r1.GetDistance() < r2.GetDistance();
}