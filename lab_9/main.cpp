// Контейнеры STL: 
//stack, queue, priority_queue
//set, multiset, map, multimap

#include <stack>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <clocale>
#include <deque>

#include <iostream>

#include "inc\Point.h"
#include "inc\my_templates.h"

using namespace std;

#define stop __asm nop

int main(int argc, char* argv[])
{


	//Напишите шаблон функции для вывода значений stack, queue, priority_queue
	//обратите внимание на то, что контейнеры предоставляют РАЗНЫЕ методы для 
	//получения значений




	////////////////////////////////////////////////////////////////////////////////////
	//stack

	//Создайте стек таким образом, чтобы
	//а) элементы стека стали копиями элементов вектора
	//б) при выводе значений как вектора, так и стека порядок значений был одинаковым 


	// STACK ------------------------------------------------------
	vector<int> vInt1 = { 0, 1, 2, 3, 4, 5 };
	stack<int, vector<int>> sInt1(vector<int>(vInt1.rbegin(), vInt1.rend()));
	//stack<int, vector<int>> sInt1;
	//for (size_t i = 0; i < vInt1.size(); i++)
	//	sInt1.push(vInt1[vInt1.size()-i-1]);

	cout << "I'm a vector\n";
	for (size_t i = 0; i < vInt1.size(); i++) {
		cout << vInt1[i] << " ";
	}
	cout << endl;

	cout << "I'm a stack\n";
	print_nonbase_container_info(sInt1);


	// QUEUE ------------------------------------------------------
	list<int> lInt1 = { 0, 1, 2, 3, 4, 5 };
	queue<int, list<int>> qInt1(lInt1);

	cout << "I'm a queue\n";
	print_nonbase_container_info(qInt1);

	// PRIORITY_QUEUE ------------------------------------------------------
	priority_queue<int, deque<int>> pqInt1;
	for (int i = 0; i < 6; i++)
		pqInt1.push(i);

	cout << "I'm a priority_queue\n";
	print_nonbase_container_info(pqInt1);

	stop


		////////////////////////////////////////////////////////////////////////////////////
		//queue

		//Создайте очередь, которая содержит указатели на объекты типа Point,
		//при этом явно задайте базовый контейнер.
		//Измените значения первого и последнего элементов посредством front() и back()
		//Подумайте, что требуется сделать при уничтожении такой очереди?

	{
		queue<Point*, list<Point*>> qPoint;

		qPoint.push(new Point(1, 1));
		qPoint.push(new Point(2, 2));
		qPoint.push(new Point(3, 3));
		qPoint.push(new Point(4, 4));

		*(qPoint.front()) = Point(11, 11);
		*(qPoint.back()) = Point(44, 44);

		size_t qPointsize = qPoint.size();
		for (size_t i = 0; i < qPointsize; i++) {
			delete qPoint.front();
			qPoint.pop();
		}
	}

		////////////////////////////////////////////////////////////////////////////////////
		//priority_queue
		//а) создайте очередь с приоритетами, которая будет хранить адреса строковых литералов - const char*
		//б) проинициализируйте очередь при создании с помощью вспомогательного массива с элементами const char*
		//в) проверьте "упорядоченность" значений (с помощью pop() ) - если они оказываются не упорядоченными, подумайте:
		//		что сравнивается при вставке?




		const char * cptrmass[4] = {"BBB", "CCC", "AAA", "DDD"};
		priority_queue<const char *, vector<const char *>, MyComparator> prqueue(&cptrmass[0], &cptrmass[4]);

		size_t prqueuesize = prqueue.size();
		for (size_t i = 0; i < prqueuesize; i++) {
			cout << prqueue.top() << " ";
			prqueue.pop();
		}

		////////////////////////////////////////////////////////////////////////////////////
		//set
		//a) создайте множество с элементами типа Point - подумайте, что необходимо определить
		//		в классе Point (и каким образом)
		//б) распечатайте значения элементов с помощью шаблона, реализованного в предыдущей лаб. работе
		//в) попробуйте изменить любое значение...
		//г) Создайте два множества, которые будут содержать одинаковые значения
		//		типа int, но занесенные в разном порядке
		//д) Вставьте в любое множество диапазон элементов из любого другого
		//	контейнера, например, элементов массива	(что происходит, если в массиве имеются дубли?) (они игнорируются)

	set<Point> setPt1;
	setPt1.insert(Point(3, 3));
	setPt1.insert(Point(2, 2));
	setPt1.insert(Point(4, 4));
	setPt1.insert(Point(5, 5));
	setPt1.insert(Point(1, 1));
	print_container_info(setPt1);

	//set<Point>::iterator setPt1It = setPt1.begin();
	//*setPt1It = Point(1, 1); // итератор set только для чтения
	{
		set<int> setInt1;
		set<int> setInt2;
		int set_size = 10;

		for (int i = 0; i < set_size; i++) {
			setInt1.insert(i);
			setInt2.insert(set_size - i - 1);
		}

		int my_mass[5] = { 0,1,1,2,2 };
		set<int> setInt3;
		setInt3.insert(&my_mass[0], &my_mass[sizeof(my_mass) / sizeof(int)]);

		stop
	}

	////////////////////////////////////////////////////////////////////////////////////
	//map, multiset
	//а) создайте map, который хранит пары "фамилия, зарплата" - pair<const char*, int>,
	//	при этом строки задаются строковыми литералами
	//б) заполните контейнер значениями посредством operator[] и insert()
	//в) распечатайте содержимое

	map<const char*, int, MyComparator> map_sur_cel;

	map_sur_cel.insert(pair<const char *, int>("Ivanov",  11111));
	map_sur_cel.insert(pair<const char *, int>("Sidorov", 33333));
	map_sur_cel.insert(pair<const char *, int>("Petrov", 22222));
	map_sur_cel["Smirnov"] = 44444;

	map<const char*, int>::iterator map_it_begin = map_sur_cel.begin(),
									map_it_end = map_sur_cel.end();
	while (map_it_begin != map_it_end) {
		cout << (*map_it_begin).first << "	" << (*map_it_begin).second << endl;
		++map_it_begin;
	}

	//г) замените один из КЛЮЧЕЙ на новый (была "Иванова", вышла замуж => стала "Петрова")

	int sal_petrov = map_sur_cel["Petrov"];
	map_sur_cel.erase("Petrov");
	map_sur_cel.insert(pair<const char *, int>("Petrova", sal_petrov));

	map_it_begin = map_sur_cel.begin();
	map_it_end = map_sur_cel.end();

	cout << endl;
	while (map_it_begin != map_it_end) {
		cout << (*map_it_begin).first << "	" << (*map_it_begin).second << endl;
		++map_it_begin;
	}

	stop




	//д) Сформируйте любым способом вектор с элементами типа string.
	//Создайте (и распечатайте для проверки) map<string, int>, который будет
	//содержать упорядоченные по алфавиту строки и
	//количество повторений каждой строки в векторе

	vector<string> srtVector = {"qqq", "qqq", "www", "eee", "rrr", "ttt", "yyy", "yyy"};
		
	map<string, int> strIntMap;

	vector<string>::iterator it1 = srtVector.begin(), it2 = srtVector.end();

	while (it1 != it2) {
		strIntMap[*it1]++;
	}

	//pair<map<string, int>::iterator, bool> result;

	//for (size_t i = 0; i < srtVector.size(); i++) {
	//	result = strIntMap.insert(make_pair(srtVector[i], 1));
	//	if (!result.second)
	//		strIntMap[srtVector[i]]++;
	//}

	stop

	//е) 
	//задан массив:
	//const char* words[] = {"Abba", "Alfa", "Beta", "Beauty" ,...};
	//создайте map, в котором каждой букве будет соответствовать совокупность 
	//лексиграфически упорядоченных слов, начинающихся с этой буквы.
	//Подсказка: не стоит хранить дубли одной и той же строки
	
	//'A' -  "Abba" "Alfa"
	//'B' -  "Beauty" "Beta"  ...
	//...
		
	const char* words[] = { "Abba", "Alfa", "Alfa", "Beta", "Beauty", "Gamma", "Goverment", "" };

	map<char, set<string>> charStringMap;
	size_t cnt = 0;
	while (strcmp(words[cnt], "")) {
		charStringMap[words[cnt][0]].insert(words[cnt]);
		cnt++;
		
	}

	//print_container_info(charStringMap['A']);
	//print_container_info(charStringMap['B']);
	//print_container_info(charStringMap['G']);


	//ж)
	//создайте структуру данных, которая будет хранить информацию о студенческих группах.
	//Для каждой группы должны хранится фамилии студентов (по алфавиту). При этом 
	//фамилии могут дублироваться
	//Сами группы тоже должны быть упорядочены по номеру
	//
	//номера 

	map<int, multiset<string>> st_groups;

	st_groups.insert(make_pair(0, multiset<string> { "Ivanov", "Ivanov", "Petrov" }));
	st_groups.insert(make_pair(1, multiset<string> { "Ivanov", "Sidorov", "Kovalenko" }));
	st_groups.insert(make_pair(2, multiset<string> { "Gavrilov", "Komkov", "Polyakov" }));
	
	st_groups[2].insert("Zlatkin");

	for (size_t i = 0; i < st_groups.size(); i++) {
		cout << "Group " << i << endl;
		print_container_info(st_groups[i]);
		
	}

	stop


	////////////////////////////////////////////////////////////////////////////////////
	//multimap
	//а) создайте "англо-русский" словарь, где одному и тому же ключу будут соответствовать
	//		несколько русских значений - pair<string,string>, например: strange: чужой, странный...
	//б) Заполните словарь парами с помощью метода insert или проинициализируйте с помощью 
	//		вспомогательного массива пара (пары можно конструировать или создавать с помощью шаблона make_pair)
	//в) Выведите все содержимое словаря на экран
	//г) Выведите на экран только варианты "переводов" для заданного ключа. Подсказка: для нахождения диапазона
	//		итераторов можно использовать методы lower_bound() и upper_bound()

	multimap<string, string> dictionary;

	pair<string, string> st_pair_mass[4] = {make_pair("strange", "stranniy"), make_pair("strange", "chuzhoy"), make_pair("big", "bolshoy"), make_pair("big", "ogromniy")};
	
	dictionary.insert(st_pair_mass[0]);
	dictionary.insert(st_pair_mass[1]);
	dictionary.insert(st_pair_mass[2]);
	dictionary.insert(st_pair_mass[3]);


	multimap<string, string>::iterator dict_it;

	dict_it = dictionary.begin();
	cout << "I'm a full ENG-RUS dictionary" << endl;
	while (dict_it != dictionary.end()) {
		cout << (*dict_it).first << "	" << (*dict_it).second << endl;
		++dict_it;
	}

	dict_it = dictionary.lower_bound("strange");
	cout << "This is variants for translations: " << endl;
	while (dict_it != dictionary.upper_bound("strange")) {
		cout << (*dict_it).first << "	" << (*dict_it).second << endl;
		++dict_it;
	}

	stop

	return 0;
}

