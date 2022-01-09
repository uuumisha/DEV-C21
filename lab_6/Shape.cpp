#include "inc\Shape.h"
#include <iostream>

Shape::Shape() {
	m_color = BLUE;
}

Shape::Shape(COLOR c) {
	m_color = c;
}

Shape::Shape(const Shape &other) {
	m_color = other.m_color;
}

COLOR Shape::GetColor() const {
	return m_color;
}

Shape::~Shape() {
	//std::cout << "Now I am in Shape's destructor!\n";
}

void Shape::Print(std::ostream& os) const {
	os << "Color = " << m_color << "\n";
};

bool Shape::operator==(const Shape& other) const {
	return (m_color == other.m_color);
}

std::ostream& operator<<(std::ostream &os, COLOR color) {
	switch (color) {
	case RED:
		os << "RED";
		break;
	case GREEN:
		os << "GREEN";
		break;
	case BLUE:
		os << "BLUE";
		break;
	}
	return os;
}

Shape& Shape::operator=(const Shape& other) {
	m_color = other.m_color;
	return *this;
}

COLOR StrToColor(const char *str) {
	if (!strcmp(str, "RED"))
		return RED;
	if (!strcmp(str, "GREEN"))
		return GREEN;
	if (!strcmp(str, "BLUE"))
		return BLUE;
	return BLUE;
}