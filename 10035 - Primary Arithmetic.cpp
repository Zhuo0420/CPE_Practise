/*
Children are taught to add multi-digit numbers from right-to-left one digit at a time. Many find the
“carry” operation - in which a 1 is carried from one digit position to be added to the next - to be a
significant challenge. Your job is to count the number of carry operations for each of a set of addition
problems so that educators may assess their difficulty.
Input
Each line of input contains two unsigned integers less than 10 digits. The last line of input contains ‘0
0’.
Output
For each line of input except the last you should compute and print the number of carry operations
that would result from adding the two numbers, in the format shown below.

Sample Input
123 456
555 555
123 594
0 0

Sample Output
No carry operation.
3 carry operations.
1 carry operation.*/
#include <iostream>
using namespace std;

int main()
{
	long long int a, b, x, counter = 0;	
	while (cin >> a >> b && (a || b)) {
		counter = 0;
		int c = 0;
		while ( a!=0 || b != 0) {
			x = (a % 10 + b % 10 + c);
			c = 0;
			if (x >= 10) {
				counter++;
				c = 1;
			}
			else
				c = 0;
			a /= 10;
			b /= 10;
		}
		if (counter == 0) {
			cout << "No carry operation." << endl;
		}
		else if (counter == 1) {
			cout << "1 carry operation." << endl;
		}
		else
			cout << counter <<" carry operations." << endl;
	}
	return 0;
}
