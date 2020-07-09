#include<iostream>

using namespace std;
struct TNode
{
	int Key;
	struct TNode* pLeft;
	struct TNode* pRight;
};
typedef TNode* Tree;

int insertNode(Tree &T, int x)
{
	if (T)
	{
		if (T->Key == x)
			return 0;
		if (T->Key > x)
			return insertNode(T->pLeft, x);
		else
			return insertNode(T->pRight, x);
	}
	T = new TNode;
	T->Key = x;
	T->pLeft = T->pRight = NULL;
	return 1;
}

TNode* SearchNode(Tree T, int x)
{
	if (T != NULL)
	{
		if (T->Key == x)
			return T;
		else
		{
			if (x > T->Key)
				return SearchNode(T->pRight, x);
			else
				return SearchNode(T->pLeft, x);
		}
	}
	return NULL;
}
int main()
{
	Tree T = NULL;
	int temp;
	while (1)
	{
		cin >> temp;
		if (temp == 0)
			break;
		insertNode(T, temp);
	}
	while (1)
	{
		cin >> temp;
		if (temp == 0)
			break;
		if (SearchNode(T, temp) != NULL)
			cout << "YES";
		else
			cout << "NO";
		cout << endl;
	}
	return 0;

}