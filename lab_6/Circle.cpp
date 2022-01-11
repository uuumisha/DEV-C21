#include "inc\Circle.h"
#include <iostream>
#include <cmath>
#include <typeinfo>

// Конструктор с параметрами
Circle::Circle(int x_center, int y_center, int radius,  COLOR c) : Shape(c) {
	m_x_center = x_center;
	m_y_center = y_center;
	if (radius < 0) {
		std::cout << "Sorry, we can't create circle with negative radius. It will be set to one." << std::endl;
		m_radius = 1;
	}
	else
		m_radius = radius;
}

// Деструктор
Circle::~Circle() {
	//std::cout << "Now I am in Circle's destructor!\n";
}

// Конструктор с параметром класса прямоульников
Circle::Circle(const Rect &r) : Shape(r) {
	int left, right, top, bottom;
	r.GetAll(left, right, top, bottom);
	m_x_center = right - left;
	m_y_center = top - bottom;
	m_radius = (top - bottom) / 2.0;
}

Circle::Circle(const Circle& other) : Shape(other) {
	m_x_center = other.m_x_center;
	m_y_center = other.m_y_center;
	m_radius = other.m_radius;
}

void Circle::Inflate(int val) {
	if (val < 0)
		std::cout << "Sorry, we can't inflate with negative parameter" << std::endl;
	else
		m_radius += val;
}

bool Circle::operator==(const Shape &other) const {

	if (typeid(other) != typeid(Circle))
		return false;
	if (!Shape::operator==(other))
		return false;
	return ((m_radius == static_cast<const Circle&>(other).m_radius) &&
		(m_x_center == static_cast<const Circle&>(other).m_x_center) &&
		(m_y_center == static_cast<const Circle&>(other).m_y_center));
}

std::ostream& operator<<(std::ostream &os, const Circle& c) {
	os << "Circle with radius " << c.m_radius << " and center (" << c.m_x_center << ", " << c.m_y_center << "). ";
	c.Shape::Print(os);
	return os;
}

double Circle::GetArea() const {
	return 3.14 * m_radius * m_radius;
}

double Circle::GetDistance() const {
	return sqrt(m_x_center*m_x_center + m_y_center*m_y_center);
}

Shape* Circle::Clone() const {
	return new Circle(*this);
}

void Circle::Print(std::ostream& os) const {
	os << *this;
}

//Circle& Circle::operator=(const Circle& other) {
//	Shape::operator=(other);
//	m_x_center = other.m_x_center;
//	m_y_center = other.m_y_center;
//	m_radius = other.m_radius;
//	return *this;
//}

Shape& Circle::operator=(const Shape& other) {

	//return static_cast<Shape&>(operator=(static_cast<const Circle&>(other)));
	*this = static_cast<const Circle&>(other);
	return *this;
}
