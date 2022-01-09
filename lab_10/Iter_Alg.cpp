// Iter_Alg.cpp : Defines the entry point for the console application.
//
//Итераторы. Стандартные алгоритмы. Предикаты.

#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include "inc/Point.h"
#include "inc/Rect.h"
#include "inc/my_templates.h"
#include "inc\Source.h"


using namespace std;	
#define	  stop __asm nop

string MyStringToLower(string &str);
char tr_my_tolower(char ch);


int main(int argc, char* argv[])
{
	
///////////////////////////////////////////////////////////////////

	//Задание 1. Итераторы

	//Реверсивные итераторы. Сформируйте set<Point>. Подумайте, что
	//нужно перегрузить в классе Point. Создайте вектор, элементы которого 
	//являются копиями элементов set, но упорядочены по убыванию

	set<Point> pointSet;
	pointSet.insert(Point(1, 1));
	pointSet.insert(Point(2, 2));
	pointSet.insert(Point(3, 3));

	set<Point>::reverse_iterator set_it = pointSet.rbegin();
	vector<Point> pointVector(pointSet.rbegin(), pointSet.rend());

	stop 

	//Потоковые итераторы. С помощью ostream_iterator выведите содержимое
	//vector и set из предыдущего задания на экран.

	ostream_iterator<Point> point_os_out(cout, " "); //stream of output

	cout << "I'm a Point Set" << endl;
	copy(pointSet.begin(), pointSet.end(), point_os_out);

	cout << endl << "I'm a Point Vector" << endl;
	copy(pointVector.begin(), pointVector.end(), point_os_out);
	cout << endl;

	stop

	//Итераторы вставки. С помощью возвращаемых функциями:
	//back_inserter()
	//front_inserter()
	//inserter()
	//итераторов вставки добавьте элементы в любой из созданных контейнеров. Подумайте:
	//какие из итераторов вставки можно использовать с каждым контейнером.

	list<Point> pointList(pointVector.begin(), pointVector.end());

	back_insert_iterator<vector<Point>> back_it = back_inserter(pointVector);
	front_insert_iterator<list<Point>> front_it = front_inserter(pointList); // для вектора не подходит
	insert_iterator<set<Point>> ins_it = inserter(pointSet, pointSet.end());


	*back_it = Point(4, 4);
	++back_it;

	*front_it = Point(5, 5);
	++front_it;

	*ins_it = Point(6, 6);
	++ins_it;

	stop

	///////////////////////////////////////////////////////////////////

	//Задание 2. Обобщенные алгоритмы (заголовочный файл <algorithm>). Предикаты.

	// алгоритм for_each() - вызов заданной функции для каждого элемента любой последовательности
	//(массив, vector, list...)
	//С помощью алгоритма for_each в любой последовательности с элементами любого типа
	//распечатайте значения элементов
	//Подсказка : неплохо вызываемую функцию определить как шаблон

	print_all_values(pointVector);
	cout << endl;
	stop

	//С помощью алгоритма for_each в любой последовательности с элементами типа Point
	//измените "координаты" на указанное значение (такой предикат тоже стоит реализовать 
	//как шаблон) и выведите результат с помощью предыдущего предиката
	delta_all_points(pointVector,1);


	//С помощью алгоритма find() найдите в любой последовательности элементов Point
	//все итераторы на элемент Point с указанным значением.

	list<Point>::iterator find_it = pointList.begin();
	size_t cntPointsList = 0;
	while (find_it != pointList.end()) {
		find_it = find(find_it, pointList.end(), Point(1, 1));
		++find_it;
		cntPointsList++;
	}
	cout << endl << cntPointsList << " points was finded" << endl;

	
	
	//С помощью алгоритма sort() отсортируйте любую последовательность элементов Point. 
	////По умолчанию алгоритм сортирует последовательность по возрастанию.
	//Что должно быть определено в классе Point?
	// Замечание: обобщенный алгоритм sort не работает со списком, так как
	//это было бы не эффективно => для списка сортировка реализована методом класса!!!
	
	sort(pointVector.begin(), pointVector.end());


	
	//С помощью алгоритма find_if() найдите в любой последовательности элементов Point
	//итератор на элемент Point, удовлетворяющий условию: координаты x и y лежат в промежутке
	//[-n, +m].
	int n = 0, m = 3;
	vector<Point>::iterator pV_it = find_if(pointVector.begin(), pointVector.end(), FunctorPointInDiapason(n, m));
	cout << *pV_it << endl;

	//С помощью алгоритма sort() отсортируйте любую последовательность элементов Rect,
	//располагая прямоугольники по удалению центра от начала координат.
	
	vector<Rect> vectorRect;
	vectorRect.push_back(Rect(0, 2, 2, 0));
	vectorRect.push_back(Rect(0, 1, 1, 0));
	vectorRect.push_back(Rect(0, 4, 4, 0));
	vectorRect.push_back(Rect(0, 3, 3, 0));

	sort(vectorRect.begin(), vectorRect.end(), CopmareRects);

	stop

	{//transform
		//Напишите функцию, которая с помощью алгоритма transform переводит 
		//содержимое объекта string в нижний регистр.
		//Подсказка: класс string - это "почти" контейнер, поэтому для него
		// определены методы begin() и end()

		string testStr = "ABCDEF";
		transform(testStr.begin(), testStr.end(), testStr.begin(), tolower);

		//Заполните list объектами string. С помощью алгоритма transform сформируйте
		//значения "пустого" set, конвертируя строки в нижний регистр
	
		list<string> MyStringList = { "ABC", "DEF", "QWERTY" };
		set<string> MyStringSet;
		transform(MyStringList.begin(), MyStringList.end(), inserter(MyStringSet, MyStringSet.begin()), MyStringToLower);


		stop
	}
	
	{//copy_if
		//Дан вектор с элементами типа string. С помощью copy_if() требуется
		//вывести сначала строки, начинающиеся с буквы "А" или "а", затем с "Б"...
		//При этом порядок строк в исходном векторе менять не нужно!
		
		vector<string> MyStringVector = { "ABC", "DEF", "QWERTY", "abc", "def", "qwerty", "qrcvv" };

		ostream_iterator<string> str_os_it(cout, " "); //stream of output

		for (char letter = 'a'; letter <= 'z'; letter++) {
			bool val = false;
			copy_if(MyStringVector.begin(), MyStringVector.end(), str_os_it, FunctorIsFirstSympolIs(letter, val));
			if (val) cout << endl;
		}
		cout << endl;


		stop

		//Дан multimap, содержаций пары: "месяц - количество дней в месяце"
		//pair<string, int>. С помощью copy_if сформируйте ДВА map-а: первый -
		//с парами, содержащими четное количество дней, 2-ой - нечетное.
		std::multimap<string, int> month {
			{"January", 31}, {"February", 28}, {"February", 29}, { "March", 31},
			{"April", 30}, {"May",31}, {"June", 30}, {"July", 31}, {"August",31},
			{"September",30}, {"October", 31}, {"November",30}, {"December",31}
		};

		std::multimap<string, int> month_even, month_uneven;
		copy_if(month.begin(), month.end(), inserter(month_even, month_even.begin()), PairEven);
		copy_if(month.begin(), month.end(), inserter(month_uneven, month_uneven.begin()), PairUnEven);
		

		queue<int> my;
		

		stop

		//Распечатайте multimap и map-ы, используя написанный вами ранее шаблон
		//функции, выводящей элементы ЛЮБОГО контейнера на печать.
		//Что нужно сделать дополнительно для вывода пары?

		print_container_info(month);
		print_container_info(month_even);
		print_container_info(month_uneven);
	
		stop
	}

	return 0;
}