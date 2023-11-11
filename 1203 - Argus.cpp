#include <iostream>
#include <queue>
#include <string>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> datas;		//經過時間 que編號 頻率

int main()
{
	string str;
	priority_queue<datas, vector<datas>, greater<datas>> que;
	int num, P, K;
	while (cin >> str && str != "#") {	
		cin >> num >> P;
		que.emplace(make_tuple(P, num, P));		
	}
	cin >> K;
	int t = 0;
	while (K--) {
		tie(t, num, P) = que.top();
		que.pop();
		que.emplace(make_tuple(P + t, num, P));
		cout << num << endl;
	}
}