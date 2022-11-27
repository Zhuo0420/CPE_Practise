/*
* For a positive integer n, let f(n) denote the
sum of the digits of n when represented in base
10. It is easy to see that the sequence of numbers n, f(n), f(f(n)), f(f(f(n))), . . . eventually
becomes a single digit number that repeats forever. Let this single digit be denoted g(n).
For example, consider n = 1234567892.
Then:
f(n) = 1+2+3+4+5+6+7+8+9+2 = 47
f(f(n)) = 4 + 7 = 11
f(f(f(n))) = 1 + 1 = 2
Therefore, g(1234567892) = 2.
Input
Each line of input contains a single positive integer n at most 2,000,000,000. Input is terminated
by n = 0 which should not be processed.
Output
For each such integer, you are to output a single
line containing g(n).

Sample Input
2
11
47
1234567892
0

Sample Output
2
2
2
2
*/
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int ToDigit(char a) {       //將 char 數字轉為 int 數字
    return a - '0';
}
int main()
{
    stringstream ss;
    int n, i;
    int sum = 0;
    string str;
    while (getline(cin,str),str!="0") {
        n = str.size();
        if (n == 1) {
            sum = ToDigit(str[0]);
        }
        while (n != 1) {
            sum = 0;
            for (i = 0; i < n; i++) {
                sum += ToDigit(str[i]);
            }
            ss << sum;
            ss >> str;
            ss.str("");
            ss.clear();         //清空ss
            n = str.size();
        }
        cout << sum << endl;
    }
    return 0;
}
