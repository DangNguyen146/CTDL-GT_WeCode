#include<iostream>
using namespace std;
struct Node
{
	double info;
	Node* Left;
	Node* Right;
};
typedef Node* Tree;
int insertNode(Tree& T, double x)
{
	if (T)
	{
		if (T->info == x)
			return 0;
		if (T->info > x)
			return insertNode(T->Left, x);
		else return insertNode(T->Right, x);
	}
	T = new Node;
	T->info = x;
	T->Left = NULL;
	T->Right = NULL;
	return 1;
}
void Input(Tree& T, int n)
{
	for (int i = 0; i < n; i++)
	{
		double x;
		cin >> x;
		insertNode(T, x);
	}
}
int Height(Tree T)
{
	if (T == NULL) return 0;
	else
	{
		int a = Height(T->Left);
		int b = Height(T->Right);
		if (a > b) return a + 1;
		else return b + 1;
	}
}
int main()
{
	Tree T;
	T = NULL;
	int n;
	cin >> n;
	Input(T, n);
	cout << "Chieu cao cua cay la: " << Height(T);
	return 0;
}