#include<iostream>
using namespace std;
struct tNode
{
	int key;
	tNode* tLeft;
	tNode* tRight;
};
typedef tNode* Tree;
int InsertTree(Tree& T, int x)
{
	if (T)
	{
		if (T->key > x)
			return InsertTree(T->tLeft, x);
		if (T->key < x)
			return InsertTree(T->tRight, x);
		if (T->key == x)
			return 0;
	}
	T = new tNode;
	T->key = x;
	T->tLeft = T->tRight = NULL;
	return 0;
}
int DemSoNut(Tree T)
{
	if (T == NULL)
		return 0;
	if ((T->tLeft == NULL && T->tRight != NULL) || (T->tLeft != NULL && T->tRight == NULL))
		return 1 + DemSoNut(T->tLeft) + DemSoNut(T->tRight);
	else
		return 0 + DemSoNut(T->tLeft) + DemSoNut(T->tRight);
	return 0;
}
int main()
{
	Tree T = NULL;
	int n;
	cin >> n;
	int x;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		InsertTree(T, x);
	}
	cout << "So node bac 1 cua cay la: " << DemSoNut(T);
	return 0;
}