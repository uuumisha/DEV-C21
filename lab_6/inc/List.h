#pragma once

#include "Node.h"
#include <iostream>

enum SORTFLAGS {AREA, DISTANCE, FIGURECOLOR};

class List {
	Node Head, Tail;
	size_t m_size;
public:
	List();
	~List();

	List(const List& other);
	List(List&& other);

	void AddToHead(const Shape &c); 
	void AddToTail(const Shape &c);
	bool RemoveOne(const Shape &c);
	unsigned RemoveEveryOne(const Shape &c);
	void DoEmpty();
	void Sort(SORTFLAGS flag);

	void WriteList() const;
	void ReadList();

	List& operator=(const List& other);
	List& operator=(List&& other);

	friend std::ostream& operator<<(std::ostream& os, const List& list);
};
