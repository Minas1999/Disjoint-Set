// pr-1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
using namespace std;

class Node;
//set node
class Node1 {
public:
	Node*	head_;
	int		size_;
	Node*	tail_;
	Node1(Node* head, int size, Node* tail) :
		head_(head), size_(size), tail_(tail) {}
};
//regular node
class Node {
public:
	Node1*	toInit_;
	int		element_;
	Node*	next_;
	Node(Node1* toInit, int element, Node* next) :
		toInit_(toInit), element_(element), next_(next) {}
};

void
make_set(Node* x)
{
	//. . . should be implemented . . .
	Node1* temp = new Node1(x, 1, x);
	x->toInit_ = temp;
	x->next_ = 0;
}

Node*
find_set(Node* x)
{
	//. . . should be implemented . . .
	return x->toInit_->head_;
}

void
un_sets(Node* x, Node* y)
{
	//. . . should be implemented . . .
	Node1* temp = x->toInit_;
	Node1* temp2 = y->toInit_;

	if (temp->size_ < temp2->size_)
	{
		swap(temp, temp2);
	}

	temp->size_ += temp2->size_;
	temp->tail_->next_ = temp2->head_;
	temp->tail_ = temp2->tail_;

	Node* m = temp2->head_;

	while (m != 0)
	{
		m->toInit_ = temp;
		m = m->next_;
	}
		
	delete temp2;
				
}

void
print(Node** x, int number)
{
	for (int i = 1; i <= number; i++)
	{
		cout << "leader(x[" << i << "]) = ";
		cout << "x[" << (x[i]->toInit_->head_->element_) << ']' << endl;
	}
	cout << endl;
}

int main()
{
	Node* x[8]; //only x[1], x[2], ..., x[7] will be used

	for (int i = 1; i <= 7; i++)
	{
		x[i] = new Node(0, i, 0);
		make_set(x[i]);
	}

	un_sets(x[1], x[3]); un_sets(x[5], x[3]);
	un_sets(x[2], x[4]); un_sets(x[4], x[7]);

	print(x, 7);

	return 0;
}
