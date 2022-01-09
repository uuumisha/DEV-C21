#pragma once
#include "Shape.h"
#include <iostream>
class Rect : public Shape {
	int m_left, m_right, m_top, m_bottom;
public:
	Rect();
	Rect(int left, int right, int top, int bottom, COLOR c = GREEN);
	void InflateRect(int dleft, int dright, int dtop, int dbottom);
	void InflateRect(int dwidth = 1, int dhight = 1);
	void SetAll(int left, int right, int top, int bottom);
	void GetAll(int &left, int &right, int &top, int &bottom) const;
	void Inflate(int val);
	Rect(const Rect &other);
	~Rect();
	bool Check(int left, int right, int top, int bottom);
	double GetArea() const;
	double GetDistance() const;
	Shape* Clone() const;
	void Print(std::ostream& os) const;
	bool operator==(const Shape& other) const;

	friend std::ostream& operator<<(std::ostream& os, const Rect& r);
	Rect& operator=(const Rect& other);
	Shape& operator=(const Shape& other);
};

bool CopmareRects(const Rect &r1, const Rect& r2);
