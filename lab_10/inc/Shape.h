#pragma once
enum COLOR {RED, GREEN, BLUE};
#include <iostream>

class Shape {
	COLOR m_color;
public:
	Shape();
	Shape(COLOR c);
	Shape(const Shape &other);
	COLOR GetColor() const;
	virtual ~Shape();
	virtual void Inflate(int val) = 0;
	virtual double GetArea() const = 0;
	virtual double GetDistance() const = 0;
	virtual bool operator==(const Shape& other) const = 0;
	virtual Shape* Clone() const = 0;
	virtual void Print(std::ostream& os) const = 0;
	virtual Shape& operator=(const Shape& other) = 0;
};

std::ostream& operator<<(std::ostream &os, COLOR color);
COLOR StrToColor(const char *str);