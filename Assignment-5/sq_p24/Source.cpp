
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

struct node
{
	char data;
	node* pNext;
};
struct list
{
	node* pHead;
};
void CreateList(list& l)
{
	l.pHead = NULL;
}
node* CreateNode(int x)
{
	node* p = new node();
	p->data = x;
	p->pNext = NULL;
	return p;
}
void AddHead(list& l, node* p)
{
	if (l.pHead == NULL)
	{
		l.pHead = p;
	}
	else
	{
		p->pNext = l.pHead;
		l.pHead = p;
	}
}
bool isEmpty(list l)
{
	return l.pHead == nullptr;
}
int main()
{
	list l;
	CreateList(l);

	bool open = false;
	bool close = false;
	int dem = 0;

	char x;
	cin.get(x);

	while (x != '\n' && x != 0 && x != '\0') {
		if (x == '(') {
			AddHead(l, CreateNode(1));
		}
		if (x == ')') {
			if (isEmpty(l)) {
				open = true;
			}
			else {
				l.pHead = l.pHead->pNext;
				dem++;
			}
		}
		x = '\n';
		cin.get(x);
	}

	if (!isEmpty(l)) close = true;

	if (open && close) {
		cout << "Dat dau ngoac bi sai.";
	}
	else {
		if (open) {
			cout << "Thieu dau ngoac mo.";
		}
		if (close) {
			cout << "Thieu dau ngoac dong.";
		}
		if (!open && !close) {
			cout << "So cap dau ngoac tron la: " << dem;
		}
	}
	return 0;
}