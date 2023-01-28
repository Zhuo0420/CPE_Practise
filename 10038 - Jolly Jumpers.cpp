#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	while (cin>>n) {
		int i;
		int arr[3000];
		int s[3000];
		cin >> arr[0];
		for (i = 1; i < n; i++) {
			cin >> arr[i];
			s[i - 1] = abs(arr[i - 1] - arr[i]);
		}
		sort(s, s + (n - 1));
		bool f = 1;
		for (i = 0; i < n - 1; i++) {
			if (s[i] != i + 1) {
				f = 0;
				break;
			}
		}
		if (f) {
			cout << "Jolly" << endl;
		}
		else cout << "Not jolly" << endl;
	}
	return 0;
}
