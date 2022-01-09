//����������

//�������: 
	//		������� �������,
	//		������� �������,


#include <tchar.h>
#include <iostream>
#include "inc\Swap.h"
#include "inc\myString.h"
#include "inc\MyStackMass.h"
#include "inc\MyStackList.h"
#include <stdexcept>


#define stop __asm nop

int _tmain(int argc, _TCHAR* argv[])
{
	

////////////////////////////////////////////////////////////////////////////
	//����. ������� �������.
	//�������� ������ ������� ������������ ������� ����
	//�������� - Swap(). ��������� ����������������� ����������
	//������� � ������� ������������ ���� ��������� ����.
	//��������� 1: ���������� ������� ���������� ��������� � .h-����.

	int iX = 1, iY = -1;
	Swap(iX, iY);

	double dX = 0.5, dY = -5.5;
	Swap(dX, dY);


	//��������� 2: ���������, ��� ����� �����������, ��� ����,
	//			����� ��������� ����� ������� � ��������� MyString
	//			�� ������ ���������, �� � ����������
	MyString str1("One"), str2("Two");
	Swap(str1, str2);

/////////////////////////////////////////////////////////////////////
	
	//����. ������� �������.
	//������� 1.
	//�������� ������ ������ MyStack ��� �������� ��������� ������ ���� T.
	//���������: 1.�������� ����� ���-�� ������� - ������� � ������� ���������
	//			��� �������� ��������������� ������������� � ������ ���������
	//			�������� ������, 
	//			2.��� ������� ������������� ������� ����� ����� ���� �����������
	//			��������-��������� �������
	//			3.������������� ���������� �� ������ �������� "push" � "pop". ���
	//			����, ����� ������������� ���������� ���������� ���� �������� 
	//			������ ���� �� ������������ ���������� � ��������� ��������
	//			4. ������������� ���������� operator[] ����� �������, ����� ������������
	//			��� ������/�������� �������� ������ ��� ���������, ������� �� ����������

	
	//� ������� ������� MyStack �������� ���� �� 5 ��������� int - iStack �
	//���� �� 10 ��������� MyString - strStack � ������������������� � ���������
	//push() � pop(), operator[]
	
	MyStack<int, 5> iStack;
	MyStack<MyString, 10> strStack;
	 
	iStack.push(1);
	iStack.push(2);
	try {
		iStack[8] = 3;
	}
	catch (const char *err) {
		std::cout << err << std::endl;
	}
	iStack.pop();

	strStack.push("String1");
	strStack.push("String2");
	strStack.push("String3");
	strStack.push("String4");
	strStack.pop();




	//������� 2. ���������� ������ ����� - MyStack2 ����� �������, ����� 
	//��� �������� ��������� ������������� ����������� ������.
	//���������� ����������� ����������� �������� ����� � ��� �������, � ������� �� ������� (push())
	//������������

	MyStackList<MyString> stackList;
	stackList.push("4");
	stackList.push("5");
	stackList.push("6");
	stackList.push("7");
	stackList.pop();

	// ����� ������ �� �����
	std::cout << stackList;
	
	std::cout << stackList[3] << std::endl;
	try {
		std::cout << stackList[4] << std::endl;
	}
	catch (const char *err) {
		std::cout << err << std::endl;
	}

	MyStackList<MyString> stackList2(stackList);

	stackList2.pop();
	stackList2 = stackList;

	// ����� ������ �� �����
	std::cout << stackList2;

	stackList2.DoEmpty();

	return 0;
}

