
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;



int binarySearch(int A[], int n, int x) {
	int l = 0, r = n - 1;
	int m;
	int temp = n;
	while (l <= r) {
		m = l + (r - l) / 2;
		if (x <= A[m])
		{
			temp = m;
			r = temp - 1;
		}
		else l = m + 1;
	}
	return temp;
}

int main()
{
	int* a, * b;
	int n, t;
	cin >> n >> t;
	a = new int[n];
	b = new int[t];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < t; i++)
	{
		cin >> b[i];
		cout << n - binarySearch(a, n, b[i]) << endl;
	}
	return 0;
}