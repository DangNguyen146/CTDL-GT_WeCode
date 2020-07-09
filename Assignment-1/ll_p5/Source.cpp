#include<iostream>
using namespace std;
typedef struct Node
{
	int info;
	struct Node* pNext;
}NODE;
typedef struct List
{
	NODE* pHead;
	NODE* pTail;
}LIST;
void CreateList(List& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
void NhapList(List& l)
{

	while (1)
	{
		int n;
		cin >> n;
		if (n == 0)
			break;
		else
		{
			Node* p = new Node;
			if (p == NULL)
				exit(-1);
			p->info = n;
			p->pNext = NULL;

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
	}
}
int DemSoPhanTu(List l)
{
	Node* p;
	int dem = 0;
	for (p = l.pHead; p != NULL; p = p->pNext)
	{
		dem++;
	}
	return dem;
}
void XuatList(List l)
{
	Node* p = l.pHead;
	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->pNext;
	}
}
void Split(List l, List& l1, List& l2)
{
	Node* p;
	for (p = l.pHead; p != NULL; p = p->pNext)
	{
		if (p->info % 2 == 0)
		{
			Node* p2 = new Node;
			if (p2 == NULL)
				exit(-1);
			p2->info = p->info;
			p2->pNext = NULL;
			if (l1.pHead == NULL)
			{
				l1.pHead = p2;
				l1.pTail = l1.pHead;
			}
			else
			{
				Node* e = l1.pHead;
				while (e != NULL)
				{
					if (e->info == p2->info) {
						goto xy;
					}
					e = e->pNext;
				}
				l1.pTail->pNext = p2;
				l1.pTail = p2;
			}

		}
		if (p->info % 2 != 0)
		{
			Node* p3 = new Node;
			if (p3 == NULL)
				exit(-1);
			p3->info = p->info;
			p3->pNext = NULL;
			if (l2.pHead == NULL)
			{
				l2.pHead = p3;
				l2.pTail = l2.pHead;
			}
			else
			{
				Node* e = l2.pHead;
				while (e != NULL)
				{
					if (e->info == p3->info) {
						goto xy;
					}
					e = e->pNext;
				}
				l2.pTail->pNext = p3;
				l2.pTail = p3;
			}

		}
	xy:
		{

		}
	}
}