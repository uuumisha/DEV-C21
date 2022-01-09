#pragma once
#include "Shape.h"
#include <iostream>

class Node {
	Node* pNext;
	Node* pPrev;
	Shape* m_data;

	friend class List;
	friend std::ostream& operator<<(std::ostream& os, const List& list);

	Node();
	Node(const Shape* pc);
	Node(Node* n, const Shape* c);
	~Node();
};