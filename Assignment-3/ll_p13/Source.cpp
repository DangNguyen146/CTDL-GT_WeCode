
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
void SortIncrease(List& l);

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
}
void SortIncrease(List& l)
{
	for (node* p = l.pHead; p != NULL; p = p->pNext)
		for (node* q = p->pNext; q != NULL; q = q->pNext)
			if (p->info > q->info)
				swap(p->info, q->info);
}

int main()
{
	List l;
	CreateList(l);
	nhap(l);
	if (l.pHead == NULL) cout << "Danh sach rong.";
	else {
		cout << "Danh sach vua nhap la: ";
		xuat(l);
		SortIncrease(l);
		cout << endl << "Danh sach sau khi sap xep la: ";
		xuat(l);
	}
	return 0;
}