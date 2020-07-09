#include<iostream>
using  namespace std;

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
	}
	T = new tNode;
	T->key = x;
	T->tLeft = T->tRight = NULL;
	return 0;
}
void InTheoMuc(Tree a, int key, int k, int& test)
{
	if (a == NULL)
		return;
	if (a->key == key && test == 0)
	{
		cout << k << " ";
		test = 1;
	}
	InTheoMuc(a->tLeft, key, k + 1, test);
	InTheoMuc(a->tRight, key, k + 1, test);
}

int main()
{
	Tree T = NULL;
	int x;
	cin >> x;
	while (x != 0)
	{
		InsertTree(T, x);
		cin >> x;
	}
	cin >> x;
	while (x != 0)
	{
		int k = 0;
		int test = 0;
		InTheoMuc(T, x, k, test);
		if (test == 0)
			cout << -1;
		cout << endl;
		cin >> x;
	}

}