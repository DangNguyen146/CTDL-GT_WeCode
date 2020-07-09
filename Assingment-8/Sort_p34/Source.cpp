#include<iostream>
#include<vector>
using namespace std;
struct LuuTru
{
	long long x;
	long long y;
};
void Xuat(vector<long long> a, long long n)
{
	for (long long i = 0; i < n; i++)
		cout << a.at(i) << " ";
	cout << endl;
}
void Shift(vector<long long>& a, vector<LuuTru>& b, long long l, long long r, int temp)
{
	long long i, j, x;
	i = l;
	j = 2 * i + 1;
	x = a.at(i);
	while (j <= r)
	{
		if (j < r)
			if (a[j] > a[j + 1])
				j++;
		if (a.at(j) >= x)
			return;
		else
		{
			if (temp == 0)
			{
				LuuTru temp;
				temp.x = i;
				temp.y = j;
				b.push_back(temp);
			}
			swap(a.at(i), a.at(j));
			i = j;
			j = 2 * i + 1;
		}
	}
}
void CreateHead(vector<long long>& a, vector<LuuTru>& b, int temp, long long n)
{
	long long l = n / 2 - 1;
	while (l >= 0)
	{
		Shift(a, b, l, n - 1, temp);
		l--;
	}
}
void HeapSort(vector<long long>& a, vector<LuuTru>& b, long long n)
{
	int temp = 0;
	CreateHead(a, b, temp, n);
	temp = 1;
	long long r = n - 1;
	while (r > 0)
	{
		swap(a.at(0), a.at(r));
		r--;
		if (r > 0)
			Shift(a, b, 0, r, temp);
	}
}
int main()
{
	vector<long long> a;
	long long n;
	cin >> n;
	long long x;
	for (long long i = 0; i < n; i++)
	{
		cin >> x;
		a.push_back(x);
	}
	cout << "Day truoc khi sap xep: ";
	Xuat(a, n);
	vector<LuuTru> b;
	HeapSort(a, b, n);
	cout << "Day sau khi sap xep: ";
	Xuat(a, n);
	cout << "Cac hoan vi duoc thuc hien trong heap: " << endl;
	for (long long i = 0; i < b.size(); i++)
		cout << b.at(i).x << " " << b.at(i).y << endl;
	return 0;
}