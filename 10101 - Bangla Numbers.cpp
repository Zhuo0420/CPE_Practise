/*
Bangla numbers normally use ’kuti’ (10000000), ’lakh’ (100000), ’hajar’ (1000), ’shata’ (100) while
expanding and converting to text. You are going to write a program to convert a given number to text
with them.
Input
The input file may contain several test cases. Each case will contain a non-negative number ≤
999999999999999.
Output
For each case of input, you have to output a line starting with the case number with four digits
adjustment followed by the converted text.

Sample Input
23764
45897458973958

Sample Output
1. 23 hajar 7 shata 64
2. 45 lakh 89 hajar 7 shata 45 kuti 89 lakh 73 hajar 9 shata 58*/
#include <iostream>
#include <iomanip>
using namespace std;

void spile(long long int n) {
    if (n >= 10000000) {
        spile(n / 10000000);
        cout << " kuti";
        n %= 10000000;
    }
    if (n >= 100000) {
        spile(n / 100000);
        cout << " lakh";
        n %= 100000;
    }
    if (n >= 1000) {
        spile(n / 1000);
        cout << " hajar";
        n %= 1000;
    }
    if (n >= 100) {
        spile(n / 100);
        cout << " shata";
        n %= 100;
    }
    if (n) {
        cout <<" " << n;
    }
}

int main()
{
    long long int n;
    int c = 1;
    while (cin >> n) {
        cout << setw(4) << c << ".";
        if (n) {
            spile(n);
        }
        else {
            cout << " 0";
        }
        cout << endl;
        c++;
    }
    return 0;
}
