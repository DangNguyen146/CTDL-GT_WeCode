#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;


struct node
{
	int data;
	node* pNext;
};
struct stack
{
	node* pHead;
	node* pTail;
};
void CreateStack(stack& s)
{
	s.pHead = NULL;
	s.pTail = NULL;
}
node* GetNode(int n)
{
	node* p = new node;
	if (p == NULL)
		exit(-1);
	p->data = n;
	p->pNext = NULL;
	return p;
}
void Push(stack& s, node* p)
{
	if (s.pHead == NULL)
		s.pTail = s.pHead = p;
	else
	{
		p->pNext = s.pHead;
		s.pHead = p;
	}
}
void pop(stack& s)
{
	if (s.pHead != NULL)
	{
		node* p = new node;
		s.pHead = s.pHead->pNext;
	}
	else
	{
		cout << "Stack rong." << endl;
	}
}
void nhap(stack& s)
{
	int x;
	cin >> x;
	int n;
	while (1)
	{
		cin >> n;
		if (n == 0)
			break;
		if (n == x)
			pop(s);
		else
		{
			node* p = GetNode(n);
			Push(s, p);
		}
	}
}
void xuat(stack& s)
{
	cout << "Cac gia tri co trong stack la: ";
	node* p = s.pHead;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->pNext;
	}
}
int main()
{
	stack s;
	CreateStack(s);
	nhap(s);
	if (s.pHead == NULL)
		cout << "Stack rong.";
	else
		xuat(s);
	return 0;
}