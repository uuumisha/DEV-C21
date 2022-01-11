#pragma once
#include <iostream>
#include <typeinfo>

// вывод информации о векторе
template <typename T> void print_vector_info(const T& v) {
	std::cout << "capacity = " << v.capacity() << std::endl;
	std::cout << "size = "     << v.size() << std::endl;
	std::cout << "max_size = " << v.max_size() << std::endl;
	for (size_t i = 0; i < v.size(); i++)
		std::cout << "v[" << i << "] = " << v[i] << std::endl;
}

// поиск заданного элемента
template <typename T, typename Y> bool isExist(const T& v, const Y& data) {
	for (size_t i = 0; i < v.size(); i++) {
		if (v[i] == data)
			return true;
	}
	return false;
}

// удаление повторяющихся последовательностей
template <typename T> void deleteRetryElements(T& v) {
	size_t cnt = 0;
	for (size_t i = 0; i < v.size() - 1; i++) {
		if (v[i] == v[i + 1]) {
			size_t cnt2 = i + 1;
			while (v[cnt2] == v[cnt2 + 1]) {
				cnt2++;
			}
			cnt2++;
			v.erase(v.begin() + cnt, v.begin() + cnt2);
			i--;
		}
		else
			cnt++;
	}
}

// удаление из вектора всех дублей
template <typename T> void deleteEveryDubli(T& v) {
	for (size_t i = 0; i < v.size(); i++) {
		for (size_t j = i + 1; j < v.size(); j++) {
			if (v[i] == v[j]) {
				v.erase(v.begin() + j);
				j--;
			}
		}
	}
}

// вывод информации о любом контейнере
template <typename T> void print_container_info(T& v) {
	std::cout << "size = " << v.size() << std::endl;
	typename T::iterator it = v.begin();
	for (size_t i = 0; i < v.size(); i++) {
		std::cout << "container[" << i << "] = " << *it << std::endl;
		++it;
	}
}
