#include<iostream>

using namespace std;
struct TNode
{
	float Key;
	struct TNode* pLeft;
	struct TNode* pRight;
};
typedef TNode* Tree;

int insertNode(Tree& T, int x)
{
	if (T)
	{
		if (T->Key > x)
			return insertNode(T->pLeft, x);
		if(T->Key<x)
			return insertNode(T->pRight, x);
	}
	T = new TNode;
	T->Key = x;
	T->pLeft = T->pRight = NULL;
	return 1;
}
//
//TNode* SearchNode(Tree T, float x)
//{
//	if (T != NULL)
//	{
//		if (T->Key == x)
//			return T;
//		else
//		{
//			if (x > T->Key)
//				return SearchNode(T->pRight, x);
//			else
//				return SearchNode(T->pLeft, x);
//		}
//	}
//	return NULL;
//}
void RLN(Tree T)
{
	if (T != NULL) {
		RLN(T->pRight);
		RLN(T->pLeft);
		cout << T->Key << " ";
	}
}
//TNode* SearchNode(Tree T, int x)
//{
//	if (T != NULL)
//	{
//		if (T->Key == x)
//			return T;
//		else
//		{
//			if (x > T->Key)
//				return SearchNode(T->pRight, x);
//			else
//				return SearchNode(T->pLeft, x);
//		}
//	}
//	return NULL;
//}
int main()
{
	Tree T = NULL;
	//float tb=0;
	int n;
	while(1)
	{
		cin >> n;
		if (n == 0)
			break;
		//tb =tb+ temp;
		insertNode(T, n);
	}
	//tb /= 8;
	//if (SearchNode(T, tb) != NULL)
	//	cout << 1;
	//else
	//	cout << 0;
	//cout << endl;
	RLN(T);

	return 0;

}