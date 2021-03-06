//??????????? ?????????? ???????? - STL 
	//?????????? ??????????? ?????????? - vector
	//?????????

#include <iostream>
#include <vector>
#include <list>
#include "inc/my_vector_funcs.h"
#include "inc/myString.h"
#include "inc/Point.h"


#pragma warning(disable: 4786)


using namespace std;	

#define	  stop __asm nop


int main()
{
	// ????????? ??????????? ?????????? vector 

//////////////////////////////////////////////////////////////////////
	//???????? ????????. 

	//???????? ????????? ???????:
	//---------------------------
	//?????? ?????? ????? ????? - vInt ? ????????? ? ??????? ??????? size(),
	//??? ??? ?????? ???????. 
	vector<int> vInt;
	cout << "sizeof(vInt) = " << vInt.size() << endl;
	
	
	//???????????????? ????????? ????????, ????????? - ??? ?? ?????????
	//???? ???? ??????????????, - ?????????

	vInt.push_back(0);
	vInt.front() = 1;


	//? ??????? ??????? push_back() ? ????? ????????? ?????? ??????-???? ??????????.
	//?? ?????? ???????? ????? ??????? ?? ???????? ??????? ? ??????? ???????
	//size(), capacity(), max_size() ? ???????? ???????? ?????????. 
	//
	//?????????: ??? ??? ????? ???????? ??????????? ??? ? ? ????????? ????????,
	//???????? ?????? ???????, ??????? ??? ???????, ??????????? ???????? ?????? ????
	//??????? ??? "?????????" ? ???????? ????????? ?? ???????.

	for (int i = 0; i < 5; i++) vInt.push_back(i);
	print_vector_info(vInt);
	
	stop

	//?????? ???????????? - vDouble1 ? ???????? ???? ????????? ????????  ?
	//????????? ????????? ? ??????? ?????????? ???? ???????. ??? ?????
	//??????????????????? ???????? ???????? (??????)

	vector<double> vDouble1(10);
	vDouble1.at(0) = 1.1;
	print_vector_info(vDouble1);

	stop

	//?????? ???????? ???? MyString ? ????????? ???????? - 5 ?????????
	//? ?????????????? ??????? ???????? ??????? "A"
	//C ??????? ??????? at() ? ????? ? ??????? ?????????
	//?????????????? []  ???????? ???????? ?????-???? ?????????.
	//?????????? "?????" ?? ??????? ??????? ? ??????? at() ?
	//? ??????? []. 

	vector<MyString> vectorMyString(5, "A");
	vectorMyString[0] = "B";
	vectorMyString.at(1) = "C";
	cout << "vectorMyString:\n";
	print_vector_info(vectorMyString);
		
	//vectorMyString[5] = "D";
	//vectorMyString[5] = "E";

	stop




	//?????? ???????????? - vDouble3, ??????? ???????? ?????? ?????????
	// [0,5) ??????? ???????????? ????? dMas. ?????????????? ?????? dMas 
	//????? ??????? ? ???????????????????!

	const size_t dMas_size = 6;
	double dMas[dMas_size] = { 0.0,1.1,2.2,3.3,4.4,5.5 };
	vector<double> vDouble3(&dMas[0], &dMas[5]);
	cout << "vDouble3:\n";
	print_vector_info(vDouble3);
	stop


	//?????? ???????????? - vDouble4, ??????? ???????? ?????? ?????????
	// [2,5) ??????? vDouble3.
	vector<double> vDouble4(vDouble3.begin() + 2, vDouble3.begin() + 5);
	cout << "vDouble4:\n";
	print_vector_info(vDouble4);
	stop


	//?????? ????????? ???? Point - vPoint1 ?) ? ????????? ???????? 3. ????? ???????????
	//????? ?????? ??? ??????? ?????????
	//b) vPoint2 ? ????????? ???????? 5 ? ?????????????????? ?????? ??????? ???????????? (1,1).
	vector<Point> vPoint1(3);
	vector<Point> vPoint2(5, Point(1, 1));

	stop

	//?????? ?????????? ?? Point - vpPoint ? ????????? ???????? 5
	//?????????: ??? ????????? ????????? ??? ????????? "?????????" ?? ??????? Point
	{
		vector<Point*> vpPoint(5);
		for (int i = 0; i < 5; i++)	
			vpPoint[i] = new Point(i, i);

	//?????????: ??? ?????? ?? ?????? ???????? ?????? ????? ??? ???????????
		//?) ????????????? ????? ????????? ???????
		//?) ??? ?????????? operator<< ??? Point*
		print_vector_info(vpPoint);

		for (int i = 0; i < 5; i++)
			delete vpPoint[i];

	}//????? ?????????????? ???????? ????? ??????????? ??? ?????? ????????


	///////////////////////////////////////////////////////////////////////
	//?????????????? ??????.
	//?????????, ?????? ?? ????? ??????????? ???? ?????????
		
		{
		size_t n = 10;
		vector<int> v(n);
		v.resize(n/2);
		if (v.capacity() == n) cout << "v.capacity()   equal " << n << endl;  //true? (??)
		else                   cout << "v.capacity() inequal " << n << endl;
		//print_vector_info(v);
		}
		
		{
		int n = 4;
		size_t m = 8;
		vector<int> v(n);
		v.reserve(m);
		if(v.capacity() == m) cout << "v.capacity()   equal " << m << endl;  //true? (??)
		else                   cout << "v.capacity() inequal " << m << endl;
		//print_vector_info(v);
		}
		
		{
		vector<int> v(3,5);
		v.resize(4,10); //????????? (??????????? 1 ??????? ?? ????????? 10)
		v.resize(5); //?????????	(??????????? 1 ??????? ?? ????????? 0)
	
		}

	//???????? ??? "??????" ??????? ? ??????????
	//?????? (?? ?????? ? ???? ?? ????) ????. 
	//? ?????? ??????? ?????????????? ?????? ??? 5 ?????????, ? ????? ?????????
	//??? ?????????? ? ??????? push_back.
	//?????? ?????? ?????? ????????? ?????????? ??????????? push_back.
	//
	//???????? ??????, ??????? ???????? ? ???????? ?????????

	vector<int> vtest1, vtest2;
	vtest1.reserve(5);
	for (int i = 0; i < 5; i++) vtest1.push_back(i);
	for (int i = 0; i < 5; i++) vtest2.push_back(i);

	print_vector_info(vtest1);
	print_vector_info(vtest2);



	



	//!!! shrink_to_fit - ?????????? ??????? ???????.
	//??? ?????? ??????? ?? ??????????? ??????? ????????? ????????? ???????
	//?? size.
	vtest2.shrink_to_fit();
	print_vector_info(vtest2);
	

	//???????? "??????????? ???????" - ??????? ????????
	//????? ?????????? ?????? int ar[] = {11,2,4,3,5};
	//???????? ?????? ???????? ????????? ???????:
	//?????? vv[0] - ???????? 11 ????????? ?? ????????? 11
	//vv[1] - ???????? 2,2
	//vv[2] - ???????? 4,4,4,4
	//...
	//???????????? ?????????? ?????? ??????????? ??????? ?? ???????

	int ar[] = { 11,2,4,3,5 };
	vector<vector<int>> matrix(sizeof(ar) / sizeof(int));
	for (int i = 0; i < sizeof(ar) / sizeof(int); i++) {
		matrix[i].reserve(ar[i]);
		for (int j = 0; j < ar[i]; j++) {
			matrix[i].push_back(ar[i]);
		}
	}
	cout << "I'm a matrix (2-x vector):\n";
	cout << matrix.size() << " " << matrix[1].size() << "\n";
	//for (size_t i = 0; i < matrix.size(); i++) {
	//	for (size_t j = 0; j < matrix[i].size(); j++) {
	//		printf("%02d ", matrix[i][j]);
	//	}
	//	cout << endl;
	//}
	//cout << matrix; ???? ?????????
	
	stop

	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	//??????? ???????? ?????????????????? insert(). (??????? ?? ????? ??????????? ???????)
	//? ?????? vChar2 ???????? ? ?????? ??????? ?????? ?????? ???
	//???????, ??? ? ??????? ?????? ??? ???.
	
	vector<char> vChar2 = {'A','B', 'C'};
	char ch1 = 'B', ch2 = 'D';

	//find(vChar2.begin(), vChar2.end(), ch1);

	if (!isExist(vChar2, ch1))
		vChar2.insert(vChar2.begin(), ch1);

	if (!isExist(vChar2, ch2))
		vChar2.insert(vChar2.begin(), ch2);
	
	//???????? ????? ?????? ????????? ??????? vChar2 ????? 'W'
	size_t cnt = 0;
	size_t vChar2Size = vChar2.size();
	for (size_t i = 0; i < vChar2Size; i++) {
		vChar2.insert(vChar2.begin() + cnt, 'W');
		cnt += 2;
	}


///////////////////////////////////////////////////////////////////
	//???????? ???????, ??????? ?????? ??????? ?????? ????????????? ??????????????????.
	//????????: ???? - "qwerrrrty12222r3", ????? - "qwety1r3"

	{
		vector<char> vChar3 = { 'q', 'w', 'e', 'r', 'r', 'r', 'r', 't', 'y', '1', '2', '2', '2', '2', 'r', '3' };
		deleteRetryElements(vChar3);
	}


	stop

	///////////////////////////////////////////////////////////////////

	//???????? ???????? ?????????????????? erase()
	//???????? ??????? ???????? ?? ?????? ??????? ???? ?????? 
	
	vector<char> vChar3 = { 'q', 'w', 'e', 'r', 'r', 'r', 'r', 't', 'y', '1', '2', '2', '2', '2', 'r', '3' };
	deleteEveryDubli(vChar3);

	

///////////////////////////////////////////////////////////////////
	//???????? ????? ?????? ????? ???????, ????? ??? ???????? ?????
	//??????? ????????? ?????? ?? ????????? ????? ????????, ?? ???????????
	//???? ?? ? ???????? ???????

	//reverse(vChar3.begin(), vChar3.end());
	vector<char> vChar4(vChar3.rbegin(), vChar3.rend());
	


///////////////////////////////////////////////////////////////////

	//??????? 1. ??????. ????????, ??????????? ??? ???????.
	//???????? ?????? ?????? ?? ????????? Point - ptList1 ? ?????????
	//??? ?????????? ? ??????? ??????? push_back(),
	//push_front, insert()
	list<Point> ptList1;
	ptList1.push_back(Point(0, 0));
	ptList1.push_front(Point(1, 1));
	ptList1.insert(ptList1.begin(), Point(2, 2));
	list<Point>::iterator it = ptList1.begin();
	advance(it, 1);
	//cout << *(advance(ptList1.begin(),3));
	cout << *it;
	

	//???????? ?????? ???????, ??????? ????? ???????? ????????
	//?????? ?????????? ?? ??????. ????????? ?????? ??????? ?? ???????????
	//vector ? list. ????????? - ???????? ?? ??????? ??? ??????????.
	//cout << typeid(ptList1);
	//ptList1.get_allocator
	print_container_info(ptList1);

	//???????? ????? ?? ??????? "???????????" - reverse()
	ptList1.reverse();

	//???????? ?????? ptList2 ?? ????????? Point ????? ???????, ????? ?? ???? 
	//?????? ??????? ????????? ???? Point, ?? ???????? ????????? ?????? ?????????????
	//?? ? ???????? ??????? 
	list<Point> ptList2(ptList1);
	ptList2.reverse();

	//???????????? ??????  ptList1 ? ptList2 - ??????? ?????? list - sort()
	//?? ???????????.
	//?????????: ??? ?????? ???? ??????????? ? ?????? Point ??? ????, ?????
	//???????? ?????????? (????????? > <)
	ptList1.sort();
	ptList2.sort();


	


	stop

	//?????????? ??????????????? ?????? - merge(). ??????????: ???
	//??? ???? ?????????? ? ?????? ???????.
	ptList1.merge(ptList2);
	
	stop

	//?????????? ???????? ?? ?????? - remove()
	//????????? ?? ?????? ??????? ? ???????????? ?????????.
	//?????????: ??? ?????? ???? ??????????? ? ?????? Point?

	ptList1.remove(Point(1,1));

	//?????????? ???????? ?? ??????, ???????????????? ????????? ???????:
	//????? ?? ????????? ???????????? - remove_if(). 
	
	ptList1.push_front(Point(-1,-1));
	//ptList1.remove_if();

	//?????????? ?? ?????? ?????? ????????????? ?????? - unique(). 
	ptList1.unique();
	stop

///////////////////////////////////////////////////////////////////
	//??????? 2.??????? ? ????? ??????? - ????????? deque

	//???????? ?????? deque ? ?????????? ???? Point. ? ???????
	//assign ????????? deque ??????? ????????? ???????. ? ???????
	//?????????????? ???? ? ?????????? ??????? ?????????????? ???????
	//???????? ???????? ????????? ?? ??????



	//???????? deque ? ?????????? ???? MyString. ????????? ??? ??????????
	//? ??????? push_back(), push_front(), insert()
	//? ??????? erase ??????? ?? deque ??? ????????, ? ??????? ???????
	//?????????? ? 'A' ??? 'a'




	return 0;
}