#include<iostream>

using namespace std;
struct TNode
{
	int Key;
	struct TNode* pLeft;
	struct TNode* pRight;
};
typedef TNode* Tree;

int insertNode(Tree& T, int x)
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

void LNR_re(TNode* T,int& temp)
{
	if (T != NULL) {
		LNR_re(T->pLeft,temp);
		if (T->pLeft == NULL && T->pRight == NULL)
		{
			temp++;
		}
		LNR_re(T->pRight,temp);
	}
}
void LNR(TNode* T)
{
	if (T != NULL) {
		LNR(T->pLeft);
		if (T->pLeft == NULL && T->pRight == NULL)
		{
			cout << T->Key << " ";
		}
		LNR(T->pRight);
	}
}
int main()
{
	Tree T = NULL;
	int n;
	cin >> n;
	int temp;
	for (float i = 0; i < n; i++)
	{
		cin >> temp;
		insertNode(T, temp);
	}
	temp = 0;
	LNR_re(T, temp);
	cout << temp<<endl;
	LNR(T);
	return 0;

}