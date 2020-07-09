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

int DeleteAfterQ(List& l, node* p, node* q)
{
	if (p == l.pHead)
	{
		l.pHead = l.pHead->pNext;
		if (l.pHead == NULL)
			l.pTail = NULL;
	}
	else
	{
		if (p != NULL)
			if (p == l.pTail)
				l.pTail = q;
		q->pNext = p->pNext;
	}
	delete p;
	return 1;

}
int RemoveX(List& l, int x)
{
	node* q = NULL;
	int dem = 0;
	for (node* p = l.pHead; p != NULL;)
	{
		if (p->Data == x)
		{
			node* temp = p->pNext;
			DeleteAfterQ(l, p, q);
			p = temp;
			dem++;
		}
		else
		{
			q = p;
			p = p->pNext;
		}
	}
	return dem;
}

int main()
{
	List l;
	CreateList(l);
	nhap(l);
	int n;
	cin >> n;
	if (l.pHead == NULL)
	{
		cout << "Danh sach rong.";
		return 0;
	}
	if (RemoveX(l, n) == 0) cout << "Khong tim thay " << n << " trong danh sach:" << endl;
	if (l.pHead == NULL)
	{
		cout << "Danh sach rong.";
		return 0;
	}
	xuat(l);
	return 0;
}