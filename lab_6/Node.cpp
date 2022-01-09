#include "inc\Node.h"

Node::Node() {
	pNext = nullptr;
	pPrev = nullptr;
	m_data = nullptr;
}

Node::Node(Node* n, const Shape* pc) {
	pPrev = n;
	pNext = n->pNext;
	n->pNext = this; 
	pNext->pPrev = this;

	m_data = pc->Clone();
}

Node::~Node() {
	if (pPrev) {
		pPrev->pNext = this->pNext;
	}

	if (pNext) {
		pNext->pPrev = this->pPrev;
	}
	delete m_data;
}

