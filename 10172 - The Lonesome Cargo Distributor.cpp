#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int main()
{
	int set;
	cin >> set;
	while (set--) {
		stack<int> carrier;     // 載貨的車
		vector<queue<int>> stations;    // 每個 station 有一個 queue
		int n, s, q;        //stations, capacity, max number of cargo
		cin >> n >> s >> q;
		for (int i = 0; i < n; i++) {       //i 號 station 有 qi 個大小的 queue 
			queue<int> tmp;
			int qi;         // 此 station 有幾個 cargo
			cin >> qi;
			for (int j = 0; j < qi; j++) {
				int cargo;
				cin >> cargo;
				tmp.emplace(cargo);         //cargo 編號從 1 開始
			}
			stations.emplace_back(tmp);     //stations i 號站有 qi 個 cargo
		}
		int time = 0, cur = 0;      // time 為總時間, cur 為現在在哪個 station (cur = 0 ~ n-1)
		while (1) {
			
			while (!carrier.empty()) {		//車上有貨
				int tmpC = carrier.top();
				if (tmpC == cur + 1) {		//卸貨
					carrier.pop();
					++time;
				}
				else if (stations[cur].size() < q) {		//車上的貨物放到 station，station還有空間
					carrier.pop();
					stations[cur].emplace(tmpC);
					++time;
				}
				else {		//車上的貨物放不下
					break;
				}
			}
			//卸完貨，裝貨
			while (carrier.size() < s && !stations[cur].empty()) {
				carrier.emplace(stations[cur].front());
				stations[cur].pop();
				++time;
			}
			bool f = 1;		//測試是否所有station都為空
			// 如果車上沒有貨物且現在的 station 也沒有貨物
			for (auto i : stations) {
				if (!i.empty() || !carrier.empty())	{
					f = 0;
					cur = (cur + 1) % n;
					time += 2;
					break;
				}
			}
			if (f)	break;
		}		
		cout << time << endl;		
	}
}
