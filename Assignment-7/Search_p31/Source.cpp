#include<iostream>
using namespace std;
struct PhanSo
{
	long long ts;
	long long ms;
	double thuong;
};
void nhap(PhanSo a[], long long n)
{
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].ts >> a[i].ms;
		a[i].thuong = double(a[i].ts) / a[i].ms;
	}
}
void xuat(PhanSo a[], long long n)
{
	for (int i = 0; i < n; i++)
		cout << a[i].ts << "/" << a[i].ms << " ";
	cout << endl;
}
void SapXep(PhanSo a[], long long n)
{
	long long min;
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		cout << "#STEP " << i + 1 << ":" << endl;
		for (int j = i + 1; j < n; j++)
		{
			if (a[j].thuong < a[min].thuong)
				min = j;
		}
		swap(a[i], a[min]);
		xuat(a, n);
	}
}
int TimKiemBinary(PhanSo a[], long long n, PhanSo b)
{
	long long l = 0, r = n - 1;
	long long m = 0;
	long long temp = -1;
	while (l <= r)
	{
		m = (l + r) / 2;
		cout << "[Left=" << l + 1 << ", Mid=" << m + 1 << ", Right=" << r + 1 << "]" << endl;
		if (a[m].thuong == b.thuong)
		{
			temp = m;
		}
		if (b.thuong <= a[m].thuong)
			r = m - 1;
		else
			l = m + 1;
	}
	return temp + 1;
}
int main()
{
	PhanSo* a;
	long long n;
	cin >> n;
	a = new PhanSo[n];
	nhap(a, n);
	PhanSo b;
	cin >> b.ts >> b.ms;
	b.thuong = double(b.ts) / b.ms;
	SapXep(a, n);
	long long m = TimKiemBinary(a, n, b);
	if (m == 0)
		cout << "Khong tim thay phan so bang X";
	else
		cout << "Tim thay phan so bang X tai vi tri be nhat la: " << m;

	return 0;
}