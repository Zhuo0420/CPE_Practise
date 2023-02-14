#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--) {
        long long int s, d;
        cin >> s >> d;
        if (d > s || (s-d)%2==1) {
            cout << "impossible" << endl;
        }
        else {
            long long int tmp;
            tmp = (s - d) / 2;
            cout << tmp + d << " " << tmp << endl;
        }
    }
    return 0;
}
