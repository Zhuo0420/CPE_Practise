#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n;
    int i, j;
    while (cin >> n) {
        int* v = new int[n];
        for (i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v, v + n);
        int mid1 = v[(n - 1) / 2];
        int mid2 = v[n / 2];
        int ct = 0;
        for (i = 0; i < n; i++) {
            if (v[i] == mid1 || v[i] == mid2)    ct++;
        }
        cout << mid1 << " " << ct << " " << mid2 - mid1 + 1 << endl;
    }
}
