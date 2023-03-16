#include <iostream>
#include <vector>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int N;
	int i = 0;
	int j = 0;
	int k = 0;
	cin >> N;
	int num;
	for (i = 0; i < N; i++) {
		vector <long long int> fib;
		vector<long long int> ans;
		cin >> num;
		cout << num << " = ";
		fib.push_back(1);
		fib.push_back(1);
		for (int k = 2; k < 39; k++) {
			fib.push_back(fib[k - 1] + fib[k - 2]);
		}
		bool flag = 0;
		for (j = 39; j >= 2; j--) {
			if (num >= fib[j - 1]) {
				num -= fib[j - 1];
				cout << '1';
				flag = 1;
			}
			else if (flag) {
				cout << '0';
			}
		}
		cout << " (fib)" << endl;
	}
	return 0;
}
