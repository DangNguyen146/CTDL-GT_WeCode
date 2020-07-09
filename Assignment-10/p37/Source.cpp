#include<iostream>
#include<vector>
using namespace std;
struct TNode
{
	int Key;
	struct TNode* pLeft;
	struct TNode* pRight;
};

int insertNode(TNode* &T, int x)
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
void CreateTree(TNode* &T, vector<int> a)
{
	int n = a.size();
	for (int i = 0; i < n; i++)
	{
		insertNode(T, a.at(i));
	}
}
void LNR(TNode* T)
{
	if (T != NULL) {
		LNR(T->pLeft);
		cout << T->Key << " ";
		LNR(T->pRight);
	}
}
void LRN(TNode* T)
{
	if (T != NULL) {
		LRN(T->pLeft);
		LRN(T->pRight);
		cout << T->Key << " ";
	}
}
void RNL(TNode* T)
{
	if (T != NULL) {
		RNL(T->pRight);
		cout << T->Key << " ";
		RNL(T->pLeft);
	}
}
void RLN(TNode* T)
{
	if (T != NULL) {
		RLN(T->pRight);
		RLN(T->pLeft);
		cout << T->Key << " ";
	}
}
void NLR(TNode* T)
{
	if (T != NULL) {
		cout << T->Key << " ";
		NLR(T->pLeft);
		NLR(T->pRight);
	}
}
void NRL(TNode* T)
{
	if (T != NULL) {
		cout << T->Key << " ";
		NRL(T->pRight);
		NRL(T->pLeft);
	}
}

int main()
{
	TNode* T = NULL;
	vector<int> a;
	int temp;
	cin >> temp;
	while (temp != 0)
	{
			a.push_back(temp);
		cin >> temp;
	}
	CreateTree(T, a);
	cout << "LNR: ";
	LNR(T);
	cout << endl;
	cout << "LRN: ";
	LRN(T);
	cout << endl;
	cout << "RNL: ";
	RNL(T);
	cout << endl;
	cout << "RLN: ";
	RLN(T);
	cout << endl;
	cout << "NLR: ";
	NLR(T);
	cout << endl;
	cout << "NRL: ";
	NRL(T);
	cout << endl;
	return 0;

}