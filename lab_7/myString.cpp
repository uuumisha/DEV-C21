#include <string>
#include <iostream>
#include "inc\myString.h"

using namespace std;

// Определение конструктора по умолчанию
MyString::MyString() {
	char buff[20] = "Default string";
	m_pStr = new char[strlen(buff) + 1];
	strcpy(m_pStr, buff);
}


// Определение конструктора
MyString::MyString(const char *str) {
	if (str) {
		m_pStr = new char[strlen(str) + 1];
		strcpy(m_pStr, str);
	}
	else
		m_pStr = nullptr;
}

// Определение деструктора
MyString::~MyString() {
	delete[] m_pStr;
}

// Определение конструктора копирования
MyString::MyString(const MyString &other) {
	if (other.m_pStr) {
		m_pStr = new char[strlen(other.m_pStr) + 1];
		strcpy(m_pStr, other.m_pStr);
	}
	else
		m_pStr = nullptr;
}

// Определение перемещающего конструктора копирования
MyString::MyString(MyString&& tmp) {
	m_pStr = tmp.m_pStr;
	tmp.m_pStr = nullptr;
}

// Получить строку из класса
const char* MyString::GetString() const {
	if (m_pStr)
		return m_pStr;
	else
		return "Error\n";
}

// Замена строки на новую
void MyString::SetNewString(const char* str) {
	delete[] m_pStr;
	if (str) {
		m_pStr = new char[strlen(str) + 1];
		strcpy(m_pStr, str);
	}
	else
		m_pStr = nullptr;
}

MyString Concatenation(const char* str, ...) {
	const char **cpptr = &str;
	unsigned length = 0;

	// Определяем общую длину входных строк
	while (*cpptr) {
		length += strlen(*cpptr);
		cpptr++;
	}

	// Выделяем память
	char *buff = new char[length + 1];
	buff[0] = 0;
	cpptr = &str;

	// Конкатенация
	while (*cpptr) {
		strcat(buff, *cpptr);
		cpptr++;
	}
	MyString ret(buff);
	delete[] buff;
	return ret;
}

// ----------------------------- Операторы -----------------------------

MyString& MyString::operator = (const MyString& str) {
	if (this != &str) {
		delete[] m_pStr;
		m_pStr = new char[strlen(str.m_pStr) + 1];
		strcpy(m_pStr, str.m_pStr);
	}
	return *this;
}

MyString& MyString::operator = (const char *str) {
	delete[] m_pStr;
	m_pStr = new char[strlen(str) + 1];
	strcpy(m_pStr, str);
	return *this;
}

MyString& MyString::operator=(MyString&& other) {
	if (this != &other) {
		delete[] m_pStr;
		m_pStr = other.m_pStr;
		other.m_pStr = nullptr;
	}
	return *this;
}

ostream& operator<<(std::ostream &os, const MyString& str) {
	os << str.GetString();
	return os;
}

MyString MyString::operator +(const MyString& str) {
	MyString tmp = Concatenation(m_pStr, str.m_pStr, 0);
	return tmp;
}

MyString& MyString::operator +=(const MyString& str) {
	*this = Concatenation(m_pStr, str.m_pStr, 0);
	return *this;
}