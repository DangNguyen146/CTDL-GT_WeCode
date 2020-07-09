#include<iostream>
using namespace std;
struct node
{
	int info;
	node* pNext;
};
struct List
{
	node* pHead;
	node* pTail;
};
node* Getnode(int n)
{
	node* p = new node;
	if (p == NULL)
		exit(-1);
	p->info = n;
	p->pNext = NULL;
	return p;
}
void GetList(List& l, node* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = p;
		l.pTail = l.pHead;
	}
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void nhap(List& l)
{
	int n;
	while (1)
	{
		cin >> n;
		if (n == 0)
			break;
		node* p = Getnode(n);
		GetList(l, p);
	}
}
void xuat(List& l)
{
	node* p = l.pHead;
	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->pNext;
	}
}

void ReverseList(List& l)
{
	node* p = l.pHead;
	node* current = NULL;
	node* previous = NULL;

	while (p != NULL) {
		current = p;
		p = p->pNext;
		current->pNext = previous;
		previous = current;
	}
	p = current;
	l.pHead = l.pTail;
}