#include <iostream>
using namespace std;
void nhap(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cin >> a[i];
}
void xuat(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}
void XapXep(int a[], int n)
{
	cout << "Mang truoc khi sap xep la: ";
	xuat(a, n);
	int max = 0;
	for (int i = 0; i < n - 1; i++)
	{
		cout << "i=" << i << ":" << endl;
		max = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] > a[max])
				max = j;
		}
		cout << "Max = a[" << max << "] = " << a[max] << endl;
		swap(a[i], a[max]);
		cout << "Mang sau khi sap xep " << i + 1 << " phan tu dau tien la: ";
		xuat(a, n);
	}
}
int main()
{
	int n;
	cin >> n;
	if (n == 0)
	{
		cout << "Mang rong.";
		return 0;
	}
	int* a;
	a = new int[n];
	nhap(a, n);
	XapXep(a, n);
	cout << "Mang sau khi sap xep la: ";
	xuat(a, n);

	return 0;
}