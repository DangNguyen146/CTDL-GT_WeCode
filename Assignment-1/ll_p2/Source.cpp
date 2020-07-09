#include<iostream>
using namespace std;
typedef struct Node
{
	int Data;
	struct Node* pNext;
}NODE;
typedef struct List
{
	NODE* pHead;
	NODE* pTail;
}LIST;
void CreatList(LIST& l)
{
	l.pHead = NULL;
	l.pTail = NULL;
}
NODE* GetNode(int n)
{
	NODE* p = new NODE;
	if (p == NULL)
		exit(-1);
	p->Data = n;
	p->pNext = NULL;
	return p;
}
void GetList(LIST& l, NODE* p)
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
void NhapList(LIST& l)
{
	int dem = 0;
	while (1)
	{
		int n;
		cin >> n;
		if (n == 0)
			break;
		else
		{
			dem++;
			NODE* p = GetNode(n);
			GetList(l, p);
		}
	}
	if (dem == 0)
		cout << "Danh sach rong.";
}
void XuatList(LIST& l)
{
	NODE* p = l.pHead;
	if (p != NULL)
		cout << "Danh sach vua nhap la: ";
	while (p != NULL)
	{
		cout << p->Data << " ";
		p = p->pNext;
	}
}

int main()
{
	LIST l;
	CreatList(l);
	NhapList(l);
	XuatList(l);
	return 0;
}