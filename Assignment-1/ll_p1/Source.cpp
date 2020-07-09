#include<iostream>
using namespace std;

typedef struct Check
{
	int count;
	bool Ch;
}CHECK;

typedef struct Node
{
	int Info;
	struct Node* PNext;
}NODE;

typedef struct List
{
	NODE* PHead;
	NODE* PTail;
}LIST;

void CreateList(LIST& L)
{
	L.PHead = NULL;
	L.PTail = NULL;
}

bool IsEmpty(LIST L)
{
	if (L.PHead == NULL) return 1;
	else return 0;
}

NODE* GetNode(int x)
{
	NODE* PNew = new NODE;
	if (PNew == NULL)
	{
		exit(1);
	}
	else
	{
		PNew->Info = x;
		PNew->PNext = NULL;
	}
	return PNew;
}

void AddList(LIST& L, Node* P)
{
	if (IsEmpty(L) == 1)
	{
		L.PHead = P;
		L.PTail = L.PHead;
	}
	else
	{
		L.PTail->PNext = P;
		L.PTail = P;
	}
}

int FindMax(int a, int b)
{
	return(a > b) ? a : b;
}

void ReadTheData(LIST& L,int &Max)
{
	CreateList(L);
	while (1)
	{
		int x;
		cin >> x;
		if (x == 0) break;
		Max = FindMax(Max, x);
		NODE* PNew = GetNode(x);
		AddList(L, PNew);
	}
}

void PrintTheReSult(LIST L,int Max,CHECK Ch[])
{
	NODE* Pout = L.PHead;
	for (int i = 0; i <= Max; i++)
	{
		Ch[i].count = 0;
		Ch[i].Ch = 0;
	}

	if (IsEmpty(L)) cout << "Danh sach rong.";
	else
	{
		cout << "Danh sach vua nhap la: ";
		while (Pout != NULL)
		{
			Ch[Pout->Info].count ++;
			cout << Pout->Info << " ";
			Pout = Pout->PNext;
		}
		cout << endl << "So lan xuat hien cua tung phan tu trong danh sach la: " << endl;
		NODE* P = L.PHead;
		while (P != NULL)
		{
			if (Ch[P->Info].Ch == 0) {
				cout << P->Info << ": " << Ch[P->Info].count << endl;
				Ch[P->Info].Ch = 1;
			}
			P = P->PNext;
		}
	}
}

int main()
{
	LIST L;
	CHECK Ch[10000];
	int Max = -100000;

	ReadTheData(L, Max);
	PrintTheReSult(L,Max,Ch);

	return 0;
}