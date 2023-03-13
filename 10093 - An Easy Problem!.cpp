#include <iostream>
#include <string>
using namespace std;
int main()
{
	string str;
	while (getline(cin, str)) {
		int sum = 0;
		int max = -1;
		int ans = -1;
		for (int i = 0; i < str.length(); i++) {
			int tmp;
			if (str[i] >= '0' && str[i] <= '9') {
				tmp = str[i] - '0';
			}
			else if (str[i] >= 'A' && str[i] <= 'Z') {
				tmp = str[i] - 'A' + 10;
			}
			else if (str[i] >= 'a' && str[i] <= 'z') {
				tmp = str[i] - 'a' + 36;
			}
			else continue;
			if (tmp > max) {
				max = tmp;
			}
			sum += tmp;
		}
		if (!max) {
			max = 1;
		}
		for (int i = max; i < 62; i++) {
			if (!(sum % i)) {
				ans = i + 1;
				break;
			}
		}
		if (ans == -1) {
			cout << "such number is impossible!" << endl;
		}
		else {
			cout << ans << endl;
		}
	}
	return 0;
}
