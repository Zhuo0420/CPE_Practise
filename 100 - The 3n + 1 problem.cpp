#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long int a, b, counter, n = 0, ans=0;
    while (cin >> a >> b) {
        counter = 0;
        cout << a << " " << b << " ";
        if (a > b) {
            swap(a, b);
        }
        for (int i = a; i <= b; i++) {
            n = i;
            while (n != 1) {
                 if (n % 2 == 1) {
                      n = 3 * n + 1;
                 }
                 else {
                      n /= 2;
                 }
             counter++;
            }
            counter++;
            if (counter > ans) {
                swap(counter, ans);
            }
            counter = 0;
        }
        cout << ans << endl;
        ans = 0;
    }
    return 0;
}
