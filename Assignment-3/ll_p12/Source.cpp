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
void Nhap(List& l)
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
int KiemTra(List l)
{
	int dem = 0;
	int temptru = 0, tempcong = 0;
	for (node* p = l.pHead; p != NULL; p = p->pNext)
	{
		if (p->pNext == NULL)
			break;
		dem++;
		if (p->pNext->info >= p->info)
			tempcong++;
		if (p->pNext->info <= p->info)
			temptru++;
	}
	if (tempcong == dem && temptru == dem)
		return 2;
	else if (tempcong == dem)
		return 1;
	else if (temptru == dem)
		return -1;
	else
		return 0;
}
void Xuat(List l)
{
	cout << "Danh sach vua nhap la: ";
	node* p = l.pHead;
	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->pNext;
	}
	int test = KiemTra(l);
	cout << endl;
	if (test == 1)
		cout << "Danh sach tang.";
	else if (test == -1)
		cout << "Danh sach giam.";
	else
		cout << "Danh sach khong tang cung khong giam.";
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
		Xuat(l);
	}
	return 0;
}