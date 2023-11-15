#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;


int main() {
	int cases = 1;
	string str;
	while (cin >> str && str != "end") {
		cout << "Case " << cases++ << ": ";
		vector<char> v;
		v.emplace_back(str[0]);		//至少有一個
		for (int i = 1; i < str.length(); ++i) {
			if (str[i] > v.back()) {	//以裝載貨物編號大於將要裝載貨物編號，不可疊上去，新增一個stack
				v.emplace_back(str[i]);
			}
			else {		//str[i] <= st.top(), 表示str[i]可疊在stack上，不須加新的stack
				*lower_bound(v.begin(), v.end(), str[i]) = str[i];
			}
		}
		cout << v.size() << endl;
	}
}