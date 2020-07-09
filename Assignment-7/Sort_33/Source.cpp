#include <iostream>
using namespace std;

void Nhap(int a[], int& n)
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}
void Xuat(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
int main()
{
    int a[5000];
    int n;
    Nhap(a, n);
    if (n == 0)
    {
        cout << "Mang rong.";
    }
    else
    {
        cout << "Mang truoc khi sap xep la: ";
        Xuat(a, n);
        int pos;
        int x;
        for (int i = 1; i < n; i++)
        {
            x = a[i];
            pos = i - 1;
            while ((pos >= 0) && (a[pos] < x))
            {
                a[pos + 1] = a[pos];
                pos--;
            }
            a[pos + 1] = x;
            cout << endl << endl << "Vi tri chen cua a[" << i << "] la " << pos + 1;
            cout << endl << endl;
            Xuat(a, n);
        }
        cout << endl << endl << "Mang sau khi sap xep la: ";
        Xuat(a, n);
    }
    return 0;
}