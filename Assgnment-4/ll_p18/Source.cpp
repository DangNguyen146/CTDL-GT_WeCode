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
bool snt(int n)
{
	if (n < 2)
		return false;
	if (n == 2)
		return true;
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0)
			return false;
	return true;
}
void Search(List l)
{
	int i = 1;
	Node* p = l.pHead;
	for (p; p != NULL; p = p->pNext)
	{
		if (i % 2 == 0 && snt(p->Data) == true)
			cout << p->Data << " ";
		i++;
	}
}
int main()
{
	List l;
	CreateList(l);
	Nhap(l);
	Search(l);
	return 0;
}