#include<iostream>
using  namespace std;
struct tNode
{
	int key;
	tNode* tLeft;
	tNode* tRight;
};
typedef tNode* Tree;
tNode* CreateNode(int x)
{
	tNode* p = new tNode;
	p->key = x;
	p->tLeft = NULL;
	p->tRight = NULL;
	return p;
}
int InsertTree(Tree& T, int x)
{
	if (T)
	{
		if (T->key == x)
			return 0;
		if (T->key > x)
			return InsertTree(T->tLeft, x);
		if (T->key < x)
			return InsertTree(T->tRight, x);

	}
	T = new tNode;
	T->key = x;
	T->tLeft = T->tRight = NULL;
	return 1;
}
//Độ dài cây
int DoDaiCay(Tree T)
{
	if (T == NULL)
		return 0;
	int leLeft = DoDaiCay(T->tLeft);
	int leRight = DoDaiCay(T->tRight);
	if (leLeft > leRight)
		return leLeft + 1;
	else
		return leRight + 1;
}
//Duyệt cây theo mức
void InTheoMuc(Tree a, int i, int m, int& dem)
{
	if (a == NULL)
		return;
	if (i == m)
		dem++;
	InTheoMuc(a->tLeft, i + 1, m, dem);
	InTheoMuc(a->tRight, i + 1, m, dem);
}
void Xuat(Tree T)
{
	for (int i = 0; i < DoDaiCay(T); i++)
	{

		int dem = 0;
		InTheoMuc(T, 0, i, dem);
		cout << "So node muc " << i << " cua cay la: " << dem;
		cout << endl;
	}
}
int main()
{
	Tree T = NULL;
	int n;
	int x;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		InsertTree(T, x);
	}

	Xuat(T);
	return 0;
}