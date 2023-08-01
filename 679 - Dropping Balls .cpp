#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int N;
	cin >> N;
	while (N--) {
		int D = 0, I = 0;
		cin >> D >> I;
		if (D == -1 || I == -1) {
			break;
		}
		int tmp = I;
		int index = 1;
		for (int i = 1; i < D; ++i) {
			if (tmp % 2 == 1) {			//left
				index = 2 * index;
				tmp = (tmp + 1) / 2;
			}
			else if (tmp % 2 == 0) {		//right	
				index = 2 * index + 1;
				tmp = tmp / 2;
			}
		}
		cout << index << endl;
	}
	int x;
	cin >> x;
	return 0;
}
