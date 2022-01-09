//Исключения

//Шаблоны: 
	//		шаблоны функций,
	//		шаблоны классов,


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
	//Тема. Шаблоны функций.
	//Создайте шаблон функции перестановки местами двух
	//значений - Swap(). Проверьте работоспособность созданного
	//шаблона с помощью приведенного ниже фрагмента кода.
	//Подсказка 1: объявление шаблона корректнее поместить в .h-файл.

	int iX = 1, iY = -1;
	Swap(iX, iY);

	double dX = 0.5, dY = -5.5;
	Swap(dX, dY);


	//Подсказка 2: подумайте, что нужно реализовать, для того,
	//			чтобы следующий вызов работал с объектами MyString
	//			не только корректно, но и эффективно
	MyString str1("One"), str2("Two");
	Swap(str1, str2);

/////////////////////////////////////////////////////////////////////
	
	//Тема. Шаблоны классов.
	//Задание 1.
	//Создайте шаблон класса MyStack для хранения элементов любого типа T.
	//Подсказка: 1.элементы нужно где-то хранить - простым и удобным средством
	//			для хранения последовательно расположенных в памяти элементов
	//			является массив, 
	//			2.для задания максимального размера стека может быть использован
	//			параметр-константа шаблона
	//			3.обязательными операциями со стеком являются "push" и "pop". Для
	//			того, чтобы гарантировать корректное выполнение этих операций 
	//			хорошо было бы генерировать исключение в аварийной ситуации
	//			4. дополнительно реализуйте operator[] таким образом, чтобы пользователь
	//			мог читать/изменять значения только тех элементов, которые он формировал

	
	//С помощью шаблона MyStack создайте стек из 5 элементов int - iStack и
	//стек из 10 элементов MyString - strStack и поэкспериментируйте с функциями
	//push() и pop(), operator[]
	
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




	//Задание 2. Реализуйте шаблон стека - MyStack2 таким образом, чтобы 
	//для хранения элементов использовался ОДНОСВЯЗНЫЙ список.
	//Реализуйте возможность распечатать элементы стека в том порядке, в котором их заносил (push())
	//пользователь

	MyStackList<MyString> stackList;
	stackList.push("4");
	stackList.push("5");
	stackList.push("6");
	stackList.push("7");
	stackList.pop();

	// Вывод списка на экран
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

	// Вывод списка на экран
	std::cout << stackList2;

	stackList2.DoEmpty();

	return 0;
}

