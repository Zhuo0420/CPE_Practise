#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
	int n;
	cin >> n;
	while (n--) {
		int num;
		cin >> num;
		int ans1 = 0;
		int ans2 = 0;
		string str2;
		string str16;
		long long int tmp = num;
		bool flag = 0;
		int ct = 0;
		while (tmp > 0) {
			str2 = str2 + char((tmp % 2) + '0');
			tmp /= 2;
			ct++;
		}
		for (int i = 0; i < str2.length(); i++) {
			if (str2[i] == '1')		ans1++;
		}
		long long int sum = 0;
		tmp = num;
		ct = 1;
		while (tmp > 0) {
			sum += (tmp % 10) * pow(16, ct++);
			tmp /= 10;
		}
		ct = 0;
		tmp = sum;
		while (tmp > 0) {
			str16 = str16 + char((tmp % 2) + '0');
			tmp /= 2;
			ct++;
		}
		for (int i = 0; i < str16.length(); i++) {
			if (str16[i] == '1')	ans2++;
		}
		cout << ans1 << " " << ans2 << endl;
	}
}
