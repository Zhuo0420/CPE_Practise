#include <iostream>
using namespace std;

int main()
{
	int v = 0;
	int t = 0;
	while (cin >> v >> t) {
		int ans = 0;
		ans = 2 * v * t;
		cout << ans << endl;
	}
	return 0;
}
