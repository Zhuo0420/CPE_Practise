#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    int s;
    cin >> s;
    while (s) {
        int n, p;
        float w, L;
        float ans;
        cin >> n >> w >> p;
        L = 1 - w;
        if (L == 1) {
            cout << "0.0000" << endl;
        }
        else {
            ans = w * pow(L, p - 1) / (1 - pow(L, n));
            cout << fixed << setprecision(4) << ans << endl;
        }
        s--;
    }
    return 0;
}
