
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

int bisearch(int a[], int n, int x, int SearchFist) {
    int L = 0, R = n - 1, result = -1;
    int Mid;
    do {
        Mid = L + (R - L) / 2;
        if (x == a[Mid]) {
            result = Mid;
            if (SearchFist)
                R = Mid - 1;
            else
                L = Mid + 1;
        }
        else if (x < a[Mid])
            R = Mid - 1;
        else
            L = Mid + 1;

    } while (L <= R);
    return result;
}

int main()
{
    int* a, * arr;
    int n, t, count = 0, x = 0, y = 0;
    cin >> n;
    cin >> t;
    a = new int[n];
    arr = new int[t];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int j = 0; j < t; j++) {
        cin >> arr[j];
        int first = bisearch(a, n, arr[j], 1);
        int last = bisearch(a, n, arr[j], 0);
        int count = last - first + 1;
        if (first != -1)
            cout << count << " " << first + 1 << " " << last + 1 << endl;
        else
            cout << "-1" << endl;

    }


}