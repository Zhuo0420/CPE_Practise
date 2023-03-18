#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int i, j;
    while (n--) {
        int day;
        cin >> day;
        int* days = new int[day];
        for (i = 0; i < day; i++) {
            days[i] = 0;
        }
        int par;
        cin >> par;
        int* h = new int[par];
        for (i = 0; i < par; i++) {
            cin >> h[i];
        }
        int ct = 0;
        while (par--) {
            for (i = 0; i < day; i++) {
                if ((i + 1) % h[ct] == 0) {
                    days[i] = 1;
                }
            }
            ct++;
        }
        for (i = 0; i < day; i+=7) {
            if (i + 5 < day) {
                days[i + 5] = 0;
            }
            if (i + 6 < day) {
                days[i + 6] = 0;
            }
        }
        int ans = 0;
        for (i = 0; i < day; i++) {
            if (days[i] == 1) {
                ans++;
            }
        }
        cout << ans << endl;
    }
}
