#pragma once

template <typename T, int size> class MyStack {
	int m_capacity = 0;
	T m_ar[size];
public:
	T& operator[](int i) {
		if ((i >= 0) && (i < m_capacity))
			return m_ar[i];
		else
			throw "Index out of range";
	}
	void push(const T& t) {
		if (m_capacity < size) {
			m_ar[m_capacity] = t;
			m_capacity++;
		}
		else throw "Error, can't add element, the stack is full";
	}
	void pop() {
		if (m_capacity > 0) {
			//m_ar[m_capacity - 1].~T();
			m_capacity--;
		}
		else throw "Error, can't delete element, the stack is empty";
	}
};