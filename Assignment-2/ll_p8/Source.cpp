#include<iostream>
using namespace std;
typedef struct node
{
	int Data;
	struct node* pNext;
};
typedef struct List
{
	node* pHead;
	node* pTail;
};
void CreateList(List& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
node* Getnode(int n)
{
	node* p = new node;
	if (p == NULL)
		exit(-1);
	p->Data = n;
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
		cout << p->Data << " ";
		p = p->pNext;
	}
}

int DeleteAfterQ(List& l, node* q)
{
	node* p;
	if (q != NULL)
	{
		p = q->pNext;
		if (p != NULL)
		{
			if (p == l.pTail)
				l.pTail = q;
			q->pNext = p->pNext;
			delete p;
		}
		return 1;
	}
	else
		return 0;
}
int RemoveX(List& l)
{
	node* p;
	for (node* i = l.pHead; i != NULL; i = i->pNext)
		for (node* j = i; j != NULL; j = j->pNext)
		{
			p = j->pNext;
			if (p == NULL)
			{
				p = j;
			}
			if (i->Data == p->Data)
			{

				if (p != NULL)
					DeleteAfterQ(l, j);
			}
		}
	return 1;
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

int main()
{
	List l;
	CreateList(l);
	nhap(l);
	ReverseList(l);
	if (l.pHead == NULL)
	{
		cout << "Danh sach rong.";
		return 0;
	}
	xuat(l);
	cout << endl;
	RemoveX(l);
	RemoveX(l);
	if (l.pHead == NULL)
	{
		cout << "Danh sach rong.";
		return 0;
	}
	xuat(l);
	return 0;
}