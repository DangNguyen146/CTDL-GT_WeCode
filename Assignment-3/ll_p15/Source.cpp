#include<iostream>
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
		if (p->pNext->info == p->info)
			dem--;
		if (p->pNext->info > p->info)
			tempcong++;
		if (p->pNext->info < p->info)
			temptru++;
	}

	if (tempcong == dem && dem > 1)
		return 1;
	else
		return 0;
}
void AddHead(List& l, node* p)
{
	p->pNext = l.pHead;
	l.pHead = p;
}
void InserAfterQ(List& l, node* p, node* q)
{
	p->pNext = q->pNext;
	q->pNext = p;
	if (l.pTail == q)
		l.pTail = p;
}
void Insert(List& l, node* p)
{
	cout << "Danh sach sau khi chen so " << p->info << " la: ";
	if (p->info <= l.pHead->info)
		AddHead(l, p);

	else
	{
		for (node* i = l.pHead; i != NULL; i = i->pNext)
		{
			if (i->pNext == l.pTail && p->info > l.pTail->info)
			{
				InserAfterQ(l, p, i->pNext);
				break;
			}
			else if ((p->info >= i->info) && (p->info <= (i->pNext)->info))
			{
				InserAfterQ(l, p, i);
				break;
			}
		}
	}
	p = l.pHead;
	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->pNext;
	}
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
	node* q = new node;
	cin >> q->info;
	q->pNext = NULL;
	if (test == 1)
	{
		cout << endl;
		Insert(l, q);
	}
	else
	{
		cout << endl;
		cout << "Danh sach khong tang.";
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
		Xuat(l);
	}
	return 0;
}