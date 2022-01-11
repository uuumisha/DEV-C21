#pragma once
#include <iostream>
#include <typeinfo>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>

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

// поэксперементировать без второго параметра (queue на базе списка)
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

struct MyComparator {
	bool operator()(const char *a, const char* b) const
	{
		return strcmp(a,b) < 0;
	}
};
