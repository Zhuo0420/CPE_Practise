#include <iostream>
using namespace std;

int main()
{
    long long int S, D;
    while (cin >> S >> D) {
        long long int tmp = S;
         long long int a = S;
        long long int counter = 0;
        while (D > tmp) {
            S++;
            tmp += S;
            counter++;
        }
        cout << counter + a << endl;
    }
    return 0;
}
