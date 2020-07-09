#include <iostream>
#include <string.h>
using namespace std;

struct node
{
	int data;
	node* pNext;
};
struct list
{
	node* pHead;
	node* pTail;
};
void CreateList(list& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
node* GetNode(int n)
{
	node* p = new node;
	p->data = n;
	p->pNext = NULL;
	return p;
}
void push(list& l, node* p)
{
	if (l.pHead == NULL)
		l.pHead = p;
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
void nhap(list& l, list q, int b)
{
	int temp = 0;
	node* p = q.pHead;
	while (p != NULL)
	{
		temp = temp + (p->data) * b;
		if (p->pNext == NULL)
		{
			push(l, GetNode(temp));
		}
		else if (temp > 9)
		{
			push(l, GetNode(temp % 10));
			temp = temp / 10;
		}
		else
		{
			push(l, GetNode(temp));
			temp = 0;
		}
		p = p->pNext;
	}
}
void xuat(list l)
{
	node* p = l.pHead;
	while (p != NULL)
	{
		cout << p->data;
		p = p->pNext;
	}
}
int main()
{
	list l, q;
	CreateList(l);
	CreateList(q);
	string a;
	cin >> a;
	int b;
	cin >> b;
	for (int i = 0; i < a.length(); i++)
	{
		int x = (int)a[i] - 48;
		push(q, GetNode(x));
	}

	if (b == 0)
	{
		cout << 0;
		return 0;
	}
	else
	{
		nhap(l, q, b);
		xuat(l);
	}
	return 0;
}