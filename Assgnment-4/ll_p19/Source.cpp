#include <iostream>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;



typedef struct Node
{
	int Data;
	struct Node* pNext;
};
typedef struct List
{
	Node* pHead;
	Node* pTail;
};
void CreateList(List& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
Node* GetNode(int n)
{
	Node* p = new Node;
	if (p == NULL)
		exit(-1);
	p->Data = n;
	p->pNext = NULL;
	return p;
}
void GetList(List& l, Node* p)
{
	if (l.pHead == NULL)
		l.pTail = l.pHead = p;
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void Nhap(List& l)
{
	int n;
	while (1)
	{
		cin >> n;
		if (n == 0)
			break;
		Node* p = GetNode(n);
		GetList(l, p);
	}
}
void xuat(List l)
{
	for (Node* i = l.pHead; i != NULL; i = i->pNext)
		cout << i->Data << " ";
}
void Search(List l, int n)
{
	List a, c;
	CreateList(a);
	CreateList(c);
	for (Node* i = l.pHead; i != NULL; i = i->pNext)
	{
		if (i->Data % n == 0)
		{
			Node* p = GetNode(i->Data);
			GetList(a, p);
		}
		else
		{
			Node* p = GetNode(i->Data);
			GetList(c, p);
		}
	}
	xuat(a);
	xuat(c);
}
int main()
{
	List l;
	CreateList(l);
	Nhap(l);
	int n;
	cin >> n;
	Search(l, n);
	return 0;
}