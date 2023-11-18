#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int c;
	cin >> c;
	while (c--) {
		int l, m;
		queue<double>q[2];
		cin >> l >> m;
		for (int i = 0; i < m; i++) {
			double me;
			string side;
			cin >> me >> side;
			side == "left" ? q[0].emplace(me / 100) : q[1].emplace(me / 100);
		}
		int times = 0;
		bool side = 0;		//init left
		double c = l;		//剩餘容量
		while (!q[0].empty() || !q[1].empty()) {
			c = l;		//卸完貨，剩餘容量最大
			if (!q[side].empty()) {
				while (!q[side].empty() && (c - q[side].front()) >= 0) {
					c -= q[side].front();
					q[side].pop();					
				}
			}
			times++;
			side = !side;
		}
		cout << times << endl;
	}
}
