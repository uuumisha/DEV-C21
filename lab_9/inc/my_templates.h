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

	//const std::type_info& this_type		= typeid(cont);

	//const std::type_info& type_stack1	= typeid(std::stack<T::value_type, std::vector<T::value_type>>);
	//const std::type_info& type_stack2	= typeid(std::stack<T::value_type, std::list<T::value_type>>);
	//const std::type_info& type_stack3	= typeid(std::stack<T::value_type, std::deque<T::value_type>>);

	//const std::type_info& type_queue1	= typeid(std::queue<T::value_type, std::list<T::value_type>>);
	//const std::type_info& type_queue2	= typeid(std::queue<T::value_type, std::deque<T::value_type>>);

	//const std::type_info& type_p_queue1	= typeid(std::priority_queue<T::value_type, std::vector<T::value_type>>);
	//const std::type_info& type_p_queue2 = typeid(std::priority_queue<T::value_type, std::deque<T::value_type>>);

	//if ((this_type == type_stack1) || (this_type == type_stack2) || (this_type == type_stack3)) {
	//	std::cout << "I'm a stack" << std::endl;
	//	std::cout << cont.top() << endl;
	//	cont.pop();
	//}
	//else if ((this_type == type_queue1) || (this_type == type_queue2)) {
	//	std::cout << "I'm a queue" << std::endl;
	//	//std::cout << cont.front() << endl;
	//	cont.pop();
	//}
	//else if ((this_type == type_p_queue1) || (this_type == type_p_queue2)) {
	//	std::cout << "I'm a priority_queue" << std::endl;
	//	std::cout << cont.top() << endl;
	//	cont.pop();
	//}
	//else {
	//	std::cout << "I'm a unknown container" << std::endl;
	//}

	//T::iterator it = v.begin();

	//for (size_t i = 0; i < v.size(); i++) {
	//	std::cout << "container[" << i << "] = " << *it << std::endl;
	//	++it;
	//}
}

struct MyComparator {
	bool operator()(const char *a, const char* b) const
	{
		return strcmp(a,b) < 0;
	}
};