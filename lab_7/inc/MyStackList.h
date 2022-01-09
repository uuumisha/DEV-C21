#pragma once

#include <iostream>
#include <cmath>

// шаблон класса узла для односвязного списка
template <typename T> class Node {

	Node<T>* pNext;
	T m_data;
	template <typename T> friend class MyStackList;
public:
	Node() { pNext = nullptr; }
	Node(Node<T> *node, const T& data) { m_data = data; this->pNext = node->pNext; node->pNext = this; }

	friend std::ostream& operator<<(std::ostream& os, const Node<T>& node) {
		std::cout << node.m_data << std::endl;
		return os;
	}
	friend std::ostream& operator<<(std::ostream& os, MyStackList<T>& mystack2);
};

// шаблон класса односвязного списка
template <typename T = int> class MyStackList {
	int m_capacity = 0;
	Node<T> Head;
public:
	void push(const T& t) {
		new Node<T>(&Head, t);
		m_capacity++;
	}
	void pop() {
		if (m_capacity) {
			Node<T> *rem = Head.pNext;
			Head.pNext = rem->pNext;
			delete rem;
			m_capacity--;
		}
	}

	T& getTopData() {
		if(m_capacity) return Head.pNext->m_data;
		throw "The Stack is Empty";
	}

	T& operator[](int i) {
		if ((i >= 0) && (i <= m_capacity)) {
			Node<T> *start = &Head;
			for (int i = 0; i < m_capacity; i++) start = start->pNext;
			return start->m_data;
		}
		else
			throw "Index MyStack2 out of range";
	}

	// либо развернуть на месте либо рекурсия
	friend std::ostream& operator<<(std::ostream& os, MyStackList<T>& mystack2) {
		//Node<T> *start = mystack2.Head.pNext;
		//for (int i = 0; i < mystack2.m_capacity; i++) {
		//	std::cout << *(start->pNext);
		//	start = start->pNext;
		//}


		Node<T> *prHead = nullptr; // Здесь в итоге окажется указатель на голову перевёрнутого списка.

		while (prHead)
		{
			Node<T> *p = mystack2.Head.pNext;
		}

		for (int i = 0; i < mystack2.m_capacity; i++) {
			std::cout << *prHead;
			prHead = prHead->pNext;
		}

		return os;
	}

	void DoEmpty() {
		if (m_capacity) {
			Node<T> *start;
			while (m_capacity) {
				start = Head.pNext;
				for (int i = 0; i < m_capacity-1; i++) start = start->pNext;
				delete start;
				m_capacity--;
			}
			Head.pNext = nullptr;
		}
	}
	
	MyStackList() {}

	// конструктор копирования
	MyStackList(const MyStackList<T> &other) {
		if (other.m_capacity) {
			m_capacity = other.m_capacity;
			Node<T> *start = &Head;
			Node<T> *start_other = other.Head.pNext;
			for (int i = 0; i < other.m_capacity; i++) {
				start->pNext = new Node<T>(start, start_other->m_data);
				//start = start->pNext;
				start_other = start_other->pNext;
			}
		}
	}

	// move конструктор копирования
	MyStackList(MyStackList<T> &&tmp) {
		m_capacity = tmp.m_capacity;
		Head.pNext = tmp.Head.pNext;
		tmp.Head.pNext = nullptr;
		tmp.m_capacity = 0;
	}

	// оператор присваивания (с учетом реверсивности)
	MyStackList<T>& operator=(const MyStackList<T>& other) {
		if (this != &other) {
			//DoEmpty();
			//m_capacity = other.m_capacity;
			//Node<T> *start = &Head;
			//Node<T> *start_other = other.Head.pNext;
			//for (int i = 0; i < other.m_capacity; i++) {
			//	new Node<T>(start, start_other->m_data);
			//	start = start->pNext;
			//	start_other = start_other->pNext;
			//}
			int min_capacity = ((m_capacity < other.m_capacity) ? m_capacity : other.m_capacity);

			Node<T> *start = &Head;
			Node<T> *start_other = other.Head.pNext;
			int i;
			for (i = 0; i < min_capacity; i++) { // копируем ту чать данных, которая уже существует 
				start->pNext->m_data = start_other->m_data;
				start = start->pNext;
				start_other = start_other->pNext;
			}
			if (m_capacity < other.m_capacity) { // создаем новые узлы при необходимости
				for (; i < other.m_capacity; i++) {
					new Node<T>(start, start_other->m_data);
					start = start->pNext;
					start_other = start_other->pNext;
				}
			}
			else {
				while (m_capacity > other.m_capacity) { // удаляем ненужные узлы при необходимости
					start = Head.pNext;
					for (int i = 0; i < m_capacity - 1; i++) start = start->pNext;
					delete start;
					m_capacity--;
				}
			}

		}
		return *this;
	}

	// move оператор присваивания
	MyStackList<T>& operator=(MyStackList<T>&& other) {
		if (this != &other) {
			DoEmpty();
			m_capacity = other.m_capacity;
			Head.pNext = other.Head.pNext;
			other.Head.pNext = nullptr;
			other.m_capacity = 0;
		}
		return *this;
	}
};