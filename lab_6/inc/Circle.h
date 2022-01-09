#pragma once
#include "Shape.h"
#include "Rect.h"
#include <iostream>
class Circle : public Shape {
	int m_x_center, m_y_center;
	double m_radius;
public:
	Circle(int x_center = 0, int y_center = 0, int radius = 1, COLOR c = RED);
	Circle(const Circle& other);
	Circle(const Rect &r);
	void Inflate(int val);
	Shape* Clone() const;

	double GetArea() const;
	double GetDistance() const;
	bool operator==(const Shape&other) const;
	friend std::ostream& operator<<(std::ostream &os, const Circle& c);
	void Print(std::ostream& os) const;
	//Circle& operator=(const Circle& other);
	Shape& operator=(const Shape& other);
	~Circle();
};
