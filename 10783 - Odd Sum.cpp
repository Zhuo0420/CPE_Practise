#include <iostream>
using namespace std;

int main()
{
    int n, t = 1;
    cin >> n;
    while (n--) {
        int a, b;
        int ans = 0;
        cin >> a >> b;
        cout << "Case " << t << ": ";
        t++;
        if (a % 2 == 1) {
            for (int i = a; i <= b; i += 2) {
                ans += i;
            }
        }
        else {
            for (int i = a + 1; i <= b; i += 2) {
                ans += i;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
