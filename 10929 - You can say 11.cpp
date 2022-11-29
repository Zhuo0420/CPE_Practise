/*
Your job is, given a positive number N, determine if it is a multiple of eleven.
Input
The input is a file such that each line contains a positive number. A line containing the number ‘0’ is
the end of the input. The given numbers can contain up to 1000 digits.
Output
The output of the program shall indicate, for each input number, if it is a multiple of eleven or not.

Sample Input
112233
30800
2937
323455693
5038297
112234
0

Sample Output
112233 is a multiple of 11.
30800 is a multiple of 11.
2937 is a multiple of 11.
323455693 is a multiple of 11.
5038297 is a multiple of 11.
112234 is not a multiple of 11.*/
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
    int i,x=0 ,y=0;
    char a[1001];
    while (cin>>a) {
        if (strlen(a) == 1 && a[0] == '0')   break;
        x = 0;
        y = 0;
        for (i = 0; i < strlen(a); i += 2) {
            x += a[i]-'0';
        }
        for (i = 1; i < strlen(a); i += 2) {
            y += a[i] - '0';
        }
        if (abs(x - y) % 11 == 0) {
            cout << a << " is a multiple of 11.\n";
        }
        else {
            cout << a << " is not a multiple of 11.\n";
        }
    }
    return 0;
}
