#include<iostream>
using namespace std;

#include <iostream>
using namespace std;
struct node {
    int info;
    node* pNext;
};
struct List {
    node* pHead;
    node* pTail;
};
void CreateList(List& l) {
    l.pHead = NULL;
    l.pTail = NULL;
}



node* Getnode(int n)
{
	node* p = new node;
	if (p == NULL)
		exit(-1);
	p->info = n;
	p->pNext = NULL;
	return p;
}
void GetList(List& l, node* p)
{
	if (l.pHead == NULL)
		l.pTail = l.pHead = p;
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

void xuat(List l)
{
	node* p = l.pHead;
	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->pNext;
	}
	cout << endl;
}
void SortIncrease(List& l)
{
	for (node* p = l.pHead; p != NULL; p = p->pNext)
		for (node* q = p->pNext; q != NULL; q = q->pNext)
			if (p->info > q->info)
				swap(p->info, q->info);
}
void hop(List& l1, List l2)
{
	node* p = l2.pHead;
	while (p != NULL)
	{
		GetList(l1, p);
		p = p->pNext;
	}
}
int main()
{
	List l1;
	List l2;
	CreateList(l1);
	CreateList(l2);
	nhap(l1);
	nhap(l2);
	if (l1.pHead == NULL && l2.pHead == NULL)
	{
		cout << "Danh sach l1 rong." << endl;
		cout << "Danh sach l2 rong." << endl;
		cout << "Khong tron duoc.";
		return 0;
	}
	else if (l1.pHead == NULL)
	{
		cout << "Danh sach l1 rong." << endl;
		cout << "Danh sach l2 la: ";
		xuat(l2);
		cout << "Khong tron duoc.";
	}
	else if (l2.pHead == NULL)
	{
		cout << "Danh sach l1 la: ";
		xuat(l1);
		cout << "Danh sach l2 rong." << endl;
		cout << "Khong tron duoc.";
	}
	else
	{
		cout << "Danh sach l1 la: ";
		xuat(l1);
		cout << "Danh sach l2 la: ";
		xuat(l2);
		cout << "Danh sach l1 sau khi sap xep la: ";
		SortIncrease(l1);
		xuat(l1);
		cout << "Danh sach l2 sau khi sap xep la: ";
		SortIncrease(l2);
		xuat(l2);
		cout << "Ket qua tron l1 voi l2 la: ";
		hop(l1, l2);
		SortIncrease(l1);
		xuat(l1);
	}
	return 0;
}