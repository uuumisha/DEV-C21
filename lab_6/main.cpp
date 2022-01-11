#include "inc/Rect.h"
#include "inc/Circle.h"
#include "inc/List.h"
#include <iostream>

using namespace std;

int main() {

	List myList, myList2, mylist3;
	Circle c1(0, 0, 1, RED);
	Circle c2(0, 0, 2, BLUE);
	Rect r1(0, 2, 2, 0, GREEN);
	Rect r2(0, 10, 10, 0, GREEN);

	myList.AddToHead(c1);
	myList.AddToHead(r1);
	myList.AddToTail(c2);
	myList.AddToTail(r2);

	cout << myList;	// вывод текущего состояния списка

	myList.Sort(DISTANCE);
	cout << myList;	// вывод отсортированного списка


	myList2.AddToHead(r1);
	myList2 = myList;
	myList2.RemoveOne(c1);

	myList.WriteList();	// запись списка в файл
	mylist3.ReadList();	// чтение списка из файла
	cout << mylist3;	// вывод прочитанного из файла списка на экран

	return 0;
}
