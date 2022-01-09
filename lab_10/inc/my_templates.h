#pragma once
#include <iostream>
#include <typeinfo>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include "Point.h"

// вывод информации о любом базовом контейнере
template <typename T> void print_container_info(const T& v) {
	std::cout << typeid(T).name() << std::endl;
	std::cout << "size = " << v.size() << std::endl;
	typename T::const_iterator it = v.begin();

	for (size_t i = 0; i < v.size(); i++) {
		std::cout << "container[" << i << "] = " << *it << std::endl;
		++it;
	}
}

template <typename T> const typename T::value_type& getContTopVal(const T& cont) {
	return cont.top();
}


template <typename T, typename Y> const T& getContTopVal(const queue<T, Y>& cont) {
	return cont.front();
}


// вывод информации о любом производном контейнере
template <typename T> void print_nonbase_container_info(T cont) {
	std::cout << typeid(T).name() << std::endl;
	std::cout << "size = " << cont.size() << std::endl;

	while (!cont.empty()) {
		std::cout << getContTopVal(cont) << " ";
		cont.pop();
	}

	std::cout << std::endl;
}

 template<typename T> void print_one_value(const T& val) {
	cout << val << " ";
}

template<typename T> void print_all_values(const T& val) {
	for_each(val.begin(), val.end(), print_one_value<T::value_type>);
}

class FunctorDeltaPoint {
	int m_delta;
public:
	FunctorDeltaPoint(int delta) :m_delta(delta) {}
	void operator() (Point& pt) {
		pt -= m_delta;
	}
};

template<typename T> void delta_all_points(T& cont, int delta) {
	for_each(cont.begin(), cont.end(), FunctorDeltaPoint(delta));
	print_all_values(cont);
}

class FunctorPointInDiapason {
	int m_left, m_right;
public:
	FunctorPointInDiapason(int left, int right) : m_left(-left), m_right(right) {}
	bool operator() (const Point& pt) const {
		return pt.IsInDiapason(m_left, m_right);
	}
};

class FunctorIsFirstSympolIs {
	char m_ch;
	bool &m_b;
public:
	FunctorIsFirstSympolIs(char ch, bool &val) : m_ch(ch), m_b(val) {}
	bool operator() (const string& str) const {
		bool b = ((str[0] == toupper(m_ch)) || (str[0] == tolower(m_ch)));
		if (b) m_b = true; 
		return b;
	}
};
