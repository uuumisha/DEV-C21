#include "inc\List.h"
#include "inc\Rect.h"
#include "inc\Circle.h"
#include <fstream>

List::List() : m_size(0) {
	Head.pNext = &Tail;
	Tail.pPrev = &Head;
}

List::~List() {
	while (Tail.pPrev != &Head) {
		delete Tail.pPrev;
	}
}

// ����������� �����������
List::List(const List& other) : m_size(other.m_size) {
	Head.pNext = &Tail;
	Tail.pPrev = &Head;

	Node* pThis = &Head;
	Node* pOther = other.Head.pNext;

	for (size_t i = 0; i < m_size; i++) {
		pThis = new Node(pThis, pOther->m_data);
		pOther = pOther->pNext;
	}
}

//move ����������� �����������
List::List(List&& other) : m_size(other.m_size) {
	if (other.m_size) {
		Head.pNext = other.Head.pNext;
		Tail.pPrev = other.Tail.pPrev;
		Head.pNext->pPrev = &Head;
		Tail.pPrev->pNext = &Tail;
		m_size = other.m_size;

		other.Head.pNext = &other.Tail;
		other.Tail.pPrev = &other.Head;
		other.m_size = 0;
	}
	else {
		Head.pNext = &Tail;
		Tail.pPrev = &Head;
	}
}

void List::AddToHead(const Shape& c) {
	new Node(&Head, &c);
	m_size++;
}

void List::AddToTail(const Shape& c) {
	new Node(Tail.pPrev, &c);
	m_size++;
}

bool List::RemoveOne(const Shape &c) {
	Node *pn = Head.pNext;
	while (pn != &Tail) {
		if (*(pn->m_data) == c) {
			m_size--;
			delete pn;
			return true;
		}
		pn = pn->pNext;
	}
	return false;
}

unsigned List::RemoveEveryOne(const Shape &c) {
	unsigned cnt = 0;
	Node* pn = Head.pNext;
	while (pn != &Tail) {
		Node* p = pn->pNext;
		if (*(pn->m_data) == c) {
			m_size--;
		
			delete pn;
			cnt++;
		}
		
			pn = p;
	}

	return cnt;
}

//void List::DoEmpty() {
//	Node *pn = Head.pNext;
//	while (pn != &Tail) {
//		delete pn;
//		pn = Head.pNext;
//	}
//	m_size = 0;
//}
void List::DoEmpty() {
	while (Head.pNext != &Tail) {
		delete Head.pNext;
	}
	m_size = 0;
}

// ������� �������� ������ node ��� list
void List::Sort(SORTFLAGS flag) {
	if (m_size) {
		bool val;
		Node *pn;
		Node *end = &Tail;
		for (size_t i = 0; i < m_size - 1; i++) {
			pn = Head.pNext;
			while (pn->pNext != end) {
				// ����� �������� ��� ����������
				switch (flag) {
				case AREA:			// ���������� �� ����������� ������� �������
					val = pn->m_data->GetArea() > pn->pNext->m_data->GetArea();
					break;
				case DISTANCE:		// ���������� �� ����������� �� ������ ���������
					val = pn->m_data->GetDistance() > pn->pNext->m_data->GetDistance();
					break;
				case FIGURECOLOR:	// ���������� �� ����� ������
					val = pn->m_data->GetColor() > pn->pNext->m_data->GetColor();
					break;
				default:
					val = pn->m_data->GetColor() > pn->pNext->m_data->GetColor();
				}

				if (val) {
					Shape* buff;
					buff = pn->m_data;
					pn->m_data = pn->pNext->m_data;
					pn->pNext->m_data = buff;
				}
				else
					pn = pn->pNext;
			}
			end = end->pPrev;
		}
	}
}

// �������� ������������
List& List::operator=(const List& other) {
	if (this != &other) {
		Node *po, *pt;
		size_t m;
		if (m_size < other.m_size)
			m = m_size;
		else
			m = other.m_size;

		po = other.Head.pNext;
		pt = Head.pNext;
		for (size_t i = 0; i < m; i++) {
			if (typeid(*(pt->m_data)) == typeid(*(po->m_data))) {
				*(pt->m_data) = *(po->m_data);
			}
			else {
				delete pt->m_data;
				pt->m_data = po->m_data->Clone();
			}
////
			//try {
			//	*(pt->m_data) = *(po->m_data);
			//}
			//catch (...) {
			//	delete pt->m_data;
			//	pt->m_data = po->m_data->Clone();
			//}

			////




			pt = pt->pNext;
			po = po->pNext;
		}

		if (m_size < other.m_size) {
			for (size_t i = 0; i < other.m_size - m_size; i++) {
				new Node(Tail.pPrev, po->m_data);
				po = po->pNext;
			}
		}
		else {
			for (size_t i = 0; i < m_size - other.m_size; i++) {
				delete Tail.pPrev;
			}
		}
	}

	m_size = other.m_size;
	return *this;
}

//move  �������� ������������
List& List::operator=(List&& other) {

	if (this != &other) {
		DoEmpty();
		Head.pNext = other.Head.pNext;
		Tail.pPrev = other.Tail.pPrev;
		Head.pNext->pPrev = &Head;
		Tail.pPrev->pNext = &Tail;
		m_size = other.m_size;

		other.Head.pNext = &other.Tail;
		other.Tail.pPrev = &other.Head;
		other.m_size = 0;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const List& list) {
	os << "I'm a list with " << list.m_size << " elements: " << std::endl;
	Node *pn = list.Head.pNext;
	while (pn != &list.Tail) {
		pn->m_data->Print(os);
		pn = pn->pNext;
	}
	return os;
}

// �������� ������ � ����
void List::WriteList() const {
	std::cout << "Enter Output File Name  - ";
	char name[80];
	std::cin >> name;
	std::ofstream fout(name);
	fout << *this;
	fout << "End";
	fout.close();
}

// ������� ������ �� �����
void List::ReadList() {
	std::cout << "Enter Input File Name  - ";
	char name[80] = "", str[80] = "";
	int size, radius;
	int x,y;
	char ch;


	std::cin >> name;
	std::ifstream fin(name);
	Node* p = &Head;

	if (!fin.is_open()) {
		std::cout << "Unable to open file" << std::endl;
		return;
	}

	// ��������� ������ ������
	while (strcmp("with", str)) {
		fin >> str;
	}
	fin >> size;

	if (size) {
		while (true) {
			str[0] = 0;
			// ��������� � ����������� ���������� ��� �������������
			while (strcmp("radius", str) && strcmp("vertexes:", str))
				fin >> str;

			// ��������� ��������� ����������
			if (!strcmp("radius", str)) {
				fin >> radius;

				ch = 0;
				while (fin.get() != '(');
				fin >> x;
				fin.get();
				fin.get();
				fin >> y;

				while (fin.get() != '=');
				fin.get();
				fin >> str;

				AddToTail(Circle(x, y, radius, StrToColor(str)));
				fin >> str;
				if (!strcmp(str, "End"))
					break;
			}
			else {
				// ��������� ��������� ��������������
				int left, right, top, bottom;

				while (fin.get() != '(');
				fin >> left;
				fin.get();
				fin.get();
				fin >> top;

				while (fin.get() != '(');
				fin >> right;
				fin.get();
				fin.get();
				fin >> bottom;

				while (fin.get() != '=');
				fin.get();
				fin >> str;

				AddToTail(Rect(left,right,top,bottom, StrToColor(str)));

				fin >> str;
				if (!strcmp(str, "End"))
					break;
			}
		}
	}
	
	return;
}