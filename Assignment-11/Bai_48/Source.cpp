#include <iostream>
using namespace std;
typedef struct TNode {
	int key;
	TNode* pLeft;
	TNode* pRight;
};
typedef TNode* TREE;
void CreateTree(TREE& T) {
	T = NULL;
}
TNode* CreateNode(int x) {
	TNode* p;
	p = new TNode;
	if (p == NULL) {
		exit(1);
	}
	else {
		p->key = x;
		p->pLeft = NULL;
		p->pRight = NULL;
	}
	return p;
}
void InsertNode(TREE& T, int x) {
	if (T) {
		if (T->key == x) return;
		if (T->key > x) return InsertNode(T->pLeft, x);
		else return InsertNode(T->pRight, x);
	}
	T = CreateNode(x);
}
void Nhap(TREE& T) {
	int temp;
	while (1) {
		cin >> temp;
		if (temp == 0) break;
		InsertNode(T, temp);
	}
}
void TimBac(TREE& T, int x, int& count) {
	if (T == NULL) {
		return;
	}
	else {
		if (T->key == x) {
			if (T->pLeft != NULL) count++;
			if (T->pRight != NULL) count++;
			return;
		}
		else {
			TimBac(T->pLeft, x, count);
			TimBac(T->pRight, x, count);
		}
	}
}
int main() {
	TREE root;
	CreateTree(root);
	Nhap(root);
	int temp;
	cin >> temp;
	while (temp != 0) {
		int count = 0;
		TimBac(root, temp, count);
		cout << "Node " << temp << " co bac la " << count << "." << endl;
		cin >> temp;
	}
	return 0;
}