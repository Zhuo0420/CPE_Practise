#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a, b;
	while (cin >> a >> b) {
		if (a == 0 && b == 0) {
			break;
		}
		int i;
		int count = 0;
		double tmp;
		for (i = a; i <= b; i++) {
			tmp = sqrt(i);
			int x;
			x = tmp;
			if (tmp - x == 0) {
				count++;
			}	
		}
		cout << count << endl;
	}
	return 0;
}
