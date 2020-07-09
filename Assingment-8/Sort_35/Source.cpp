#include<iostream>
#include<vector>
using namespace std;
struct PhanTu
{
	long long x;
	long long y;
};
void xuat(vector<long long> a, long long n)
{
	for (long long i = 0; i < n; i++)
		cout << a.at(i) << " ";
	cout << endl;
}

void QuickSort(vector<long long>& a, vector<PhanTu>& b, long long l, long long r)
{
	long long x, i, j;
	i = l;
	j = r;
	x = a[(l + r) / 2];
	while (i <= j)
	{
		while (a[i] > x)
			i++;
		while (a[j] < x)
			j--;
		if (i < j)
		{
			PhanTu Index;
			Index.x = i + 1;
			Index.y = j + 1;
			b.push_back(Index);
		}
		if (i <= j)
		{
			swap(a.at(i), a.at(j));
			i++; j--;
		}
	}
	if (j > l)
		QuickSort(a, b, l, j);
	if (i < r)
		QuickSort(a, b, i, r);
}
int main()
{
	long long n;
	cin >> n;
	vector<long long> a;
	long long x;
	for (long long i = 0; i < n; i++)
	{
		cin >> x;
		a.push_back(x);
	}
	cout << "Day truoc khi sap xep: ";
	xuat(a, n);
	vector<PhanTu> b;
	long long temp = 0;
	QuickSort(a, b, 0, n - 1);
	cout << "Day sau khi sap xep: ";
	xuat(a, n);
	cout << "Cac hoan vi duoc thuc hien trong Quick Sort:" << endl;
	for (long long i = 0; i < b.size(); i++)
		cout << b.at(i).x << " " << b.at(i).y << endl;
	return 0;
}