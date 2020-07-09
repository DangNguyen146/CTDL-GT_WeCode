#include <iostream>
using namespace std;

struct node
{
	long long tuso;
	long long mauso;
	node* pNext;
};
struct List
{
	node* pHead;
	node* pTail;
};
node* GetNode(long long x, long long y)
{
	node* p = new node;
	p->tuso = x;
	p->mauso = y;
	p->pNext = NULL;
	return p;
}
void GetList(List& l, node* p)
{
	if (l.pHead == NULL)
		l.pHead = l.pTail = p;
	else
	{
		l.pTail->pNext = p;
		l.pTail = p;
	}
}
void nhap(List& l)
{
	long long x, y;
	while (1)
	{
		cin >> x >> y;
		if (y == 0)
			break;
		GetList(l, GetNode(x, y));
	}
}
void xuat(List l, bool& test, long long x, long long y)
{
	double q;
	q = double(x) / y;
	cout << "Danh sach vua nhap la: ";
	node* p = l.pHead;
	while (p != NULL)
	{
		if (double(p->tuso) / p->mauso == q)
			test = false;
		cout << p->tuso << "/" << p->mauso << " ";
		p = p->pNext;
	}
	cout << endl;
}
void Search(List l, bool test, long long x, long long y)
{
	double q;
	q = double(x) / y;
	node* p = l.pHead;
	if (test == false)
	{
		cout << "Cac phan so bang " << x << "/" << y << " co trong danh sach la: ";
		while (p != NULL)
		{
			if (double(p->tuso) / p->mauso == q)
			{
				cout << p->tuso << "/" << p->mauso << " ";
			}
			p = p->pNext;
		}
	}
	else
		cout << "Khong co phan so nao bang " << x << "/" << y << " trong danh sach.";
}
int main()
{
	List l;
	l.pHead = l.pTail = NULL;
	nhap(l);
	if (l.pHead != NULL)
	{
		long long x, y;
		cin >> x >> y;
		bool test = true;
		xuat(l, test, x, y);
		Search(l, test, x, y);
		return 0;
	}
	cout << "Danh sach rong.";

	return 0;
}