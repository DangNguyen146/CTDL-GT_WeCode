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
	}
	T = new tNode;
	T->key = x;
	T->tLeft = T->tRight = NULL;
	return 0;
}
//Độ dài cây
int DoDaiCay(Tree T)
{
	if (T == NULL)
		return 0;
	int leLeft = 1 + DoDaiCay(T->tLeft);
	int leRight = 1 + DoDaiCay(T->tRight);
	if (leLeft > leRight)
		return leLeft;
	else
		return leRight;
}
//Duyệt cây theo mức
void InTheoMuc(Tree a, int h, int k)
{
	if (a == NULL)
		return;
	if (h == k)
		cout << a->key << " ";
	InTheoMuc(a->tLeft, h, k + 1);
	InTheoMuc(a->tRight, h, k + 1);
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
	x = DoDaiCay(T);
	for (int i = 0; i < x; i++)
	{
		int k = 0;
		cout << "Deep " << i + 1 << ": ";
		InTheoMuc(T, i, k);
		cout << endl;
	}

}