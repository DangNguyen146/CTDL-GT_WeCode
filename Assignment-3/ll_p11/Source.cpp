#include<iostream>
using namespace std;
typedef struct Node
{
	int Data;
	int cout = 1;
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
		p->pNext = l.pHead;
		l.pHead = p;
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
int DeleteAfter(List& l, Node* p, Node* q)
{
	if (p != NULL)
		if (p == l.pTail)
			l.pTail = q;
	q->pNext = p->pNext;
	delete p;
	return 1;

}
void Search(List l)
{
	int dem = 1;
	for (Node* i = l.pHead; i != NULL; i = i->pNext)
	{
		Node* q = i;
		for (Node* j = i->pNext; j != NULL;)
		{
			if (i->Data == j->Data)
			{
				Node* temp = j->pNext;
				i->cout++;
				DeleteAfter(l, j, q);
				j = temp;
			}
			else
			{
				q = j;
				j = j->pNext;
			}
		}
		if (i->cout > dem)
			dem = i->cout;
	}
	Node* p = l.pHead;
	while (p != NULL)
	{
		if (p->cout == dem)
			cout << p->Data << ": " << dem << endl;
		p = p->pNext;
	}
}
int main()
{
	List l;
	CreateList(l);
	Nhap(l);
	if (l.pHead == NULL)
	{
		cout << "Danh sach rong.";
	}
	else
	{
		for (Node* p = l.pHead; p != NULL; p = p->pNext)
		{
			cout << p->Data << " ";
		}
		cout << endl;
		Search(l);
	}
	return 0;
}