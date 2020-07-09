#include <iostream>
using namespace std;
struct node
{
	int info;
	node* pNext;
};
struct List
{
	node* pHead;
	node* pTail;
};
void CreateList(List& l);
node* CreateNode(int x);
void AddTail(List& l, node* p);
void enqueue(List& l, int x);
void dequeue(List& l);
bool isEmpty(List l);
int main()
{
	List q;
	CreateList(q);
	long long x;
	cin >> x;
