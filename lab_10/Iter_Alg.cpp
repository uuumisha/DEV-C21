// Iter_Alg.cpp : Defines the entry point for the console application.
//
//���������. ����������� ���������. ���������.

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

	//������� 1. ���������

	//����������� ���������. ����������� set<Point>. ���������, ���
	//����� ����������� � ������ Point. �������� ������, �������� �������� 
	//�������� ������� ��������� set, �� ����������� �� ��������

	set<Point> pointSet;
	pointSet.insert(Point(1, 1));
	pointSet.insert(Point(2, 2));
	pointSet.insert(Point(3, 3));

	set<Point>::reverse_iterator set_it = pointSet.rbegin();
	vector<Point> pointVector(pointSet.rbegin(), pointSet.rend());

	stop 

	//��������� ���������. � ������� ostream_iterator �������� ����������
	//vector � set �� ����������� ������� �� �����.

	ostream_iterator<Point> point_os_out(cout, " "); //stream of output

	cout << "I'm a Point Set" << endl;
	copy(pointSet.begin(), pointSet.end(), point_os_out);

	cout << endl << "I'm a Point Vector" << endl;
	copy(pointVector.begin(), pointVector.end(), point_os_out);
	cout << endl;

	stop

	//��������� �������. � ������� ������������ ���������:
	//back_inserter()
	//front_inserter()
	//inserter()
	//���������� ������� �������� �������� � ����� �� ��������� �����������. ���������:
	//����� �� ���������� ������� ����� ������������ � ������ �����������.

	list<Point> pointList(pointVector.begin(), pointVector.end());

	back_insert_iterator<vector<Point>> back_it = back_inserter(pointVector);
	front_insert_iterator<list<Point>> front_it = front_inserter(pointList); // ��� ������� �� ��������
	insert_iterator<set<Point>> ins_it = inserter(pointSet, pointSet.end());


	*back_it = Point(4, 4);
	++back_it;

	*front_it = Point(5, 5);
	++front_it;

	*ins_it = Point(6, 6);
	++ins_it;

	stop

	///////////////////////////////////////////////////////////////////

	//������� 2. ���������� ��������� (������������ ���� <algorithm>). ���������.

	// �������� for_each() - ����� �������� ������� ��� ������� �������� ����� ������������������
	//(������, vector, list...)
	//� ������� ��������� for_each � ����� ������������������ � ���������� ������ ����
	//������������ �������� ���������
	//��������� : ������� ���������� ������� ���������� ��� ������

	print_all_values(pointVector);
	cout << endl;
	stop

	//� ������� ��������� for_each � ����� ������������������ � ���������� ���� Point
	//�������� "����������" �� ��������� �������� (����� �������� ���� ����� ����������� 
	//��� ������) � �������� ��������� � ������� ����������� ���������
	delta_all_points(pointVector,1);


	//� ������� ��������� find() ������� � ����� ������������������ ��������� Point
	//��� ��������� �� ������� Point � ��������� ���������.

	list<Point>::iterator find_it = pointList.begin();
	size_t cntPointsList = 0;
	while (find_it != pointList.end()) {
		find_it = find(find_it, pointList.end(), Point(1, 1));
		++find_it;
		cntPointsList++;
	}
	cout << endl << cntPointsList << " points was finded" << endl;

	
	
	//� ������� ��������� sort() ������������ ����� ������������������ ��������� Point. 
	////�� ��������� �������� ��������� ������������������ �� �����������.
	//��� ������ ���� ���������� � ������ Point?
	// ���������: ���������� �������� sort �� �������� �� �������, ��� ���
	//��� ���� �� �� ���������� => ��� ������ ���������� ����������� ������� ������!!!
	
	sort(pointVector.begin(), pointVector.end());


	
	//� ������� ��������� find_if() ������� � ����� ������������������ ��������� Point
	//�������� �� ������� Point, ��������������� �������: ���������� x � y ����� � ����������
	//[-n, +m].
	int n = 0, m = 3;
	vector<Point>::iterator pV_it = find_if(pointVector.begin(), pointVector.end(), FunctorPointInDiapason(n, m));
	cout << *pV_it << endl;

	//� ������� ��������� sort() ������������ ����� ������������������ ��������� Rect,
	//���������� �������������� �� �������� ������ �� ������ ���������.
	
	vector<Rect> vectorRect;
	vectorRect.push_back(Rect(0, 2, 2, 0));
	vectorRect.push_back(Rect(0, 1, 1, 0));
	vectorRect.push_back(Rect(0, 4, 4, 0));
	vectorRect.push_back(Rect(0, 3, 3, 0));

	sort(vectorRect.begin(), vectorRect.end(), CopmareRects);

	stop

	{//transform
		//�������� �������, ������� � ������� ��������� transform ��������� 
		//���������� ������� string � ������ �������.
		//���������: ����� string - ��� "�����" ���������, ������� ��� ����
		// ���������� ������ begin() � end()

		string testStr = "ABCDEF";
		transform(testStr.begin(), testStr.end(), testStr.begin(), tolower);

		//��������� list ��������� string. � ������� ��������� transform �����������
		//�������� "�������" set, ����������� ������ � ������ �������
	
		list<string> MyStringList = { "ABC", "DEF", "QWERTY" };
		set<string> MyStringSet;
		transform(MyStringList.begin(), MyStringList.end(), inserter(MyStringSet, MyStringSet.begin()), MyStringToLower);


		stop
	}
	
	{//copy_if
		//��� ������ � ���������� ���� string. � ������� copy_if() ���������
		//������� ������� ������, ������������ � ����� "�" ��� "�", ����� � "�"...
		//��� ���� ������� ����� � �������� ������� ������ �� �����!
		
		vector<string> MyStringVector = { "ABC", "DEF", "QWERTY", "abc", "def", "qwerty", "qrcvv" };

		ostream_iterator<string> str_os_it(cout, " "); //stream of output

		for (char letter = 'a'; letter <= 'z'; letter++) {
			bool val = false;
			copy_if(MyStringVector.begin(), MyStringVector.end(), str_os_it, FunctorIsFirstSympolIs(letter, val));
			if (val) cout << endl;
		}
		cout << endl;


		stop

		//��� multimap, ���������� ����: "����� - ���������� ���� � ������"
		//pair<string, int>. � ������� copy_if ����������� ��� map-�: ������ -
		//� ������, ����������� ������ ���������� ����, 2-�� - ��������.
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

		//������������ multimap � map-�, ��������� ���������� ���� ����� ������
		//�������, ��������� �������� ������ ���������� �� ������.
		//��� ����� ������� ������������� ��� ������ ����?

		print_container_info(month);
		print_container_info(month_even);
		print_container_info(month_uneven);
	
		stop
	}

	return 0;
}