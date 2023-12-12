#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<vector<int>> ve;
vector<int> d, parent, low, bridge;
vector<bool> cutPoint;
int dfsTime = 0;

void findBCC(int u) {
	d[u] = low[u] = ++dfsTime;
	for (int v : ve[u]) {
		if (!d[v]) {
			parent[v] = u;
			findBCC(v);
			low[u] = min(low[u], low[v]);		
			if (low[u] < low[v]) {				//u 底下沒有 edge 連到 u 的上面，u, v 為一條 bridge
				bridge.emplace_back(v);
				bridge.emplace_back(u);
			}			
		}
		else if (parent[u] != v) {
			low[u] = min(low[u], d[v]);		//是 strongly connected 所以 low 要求此 conponent 最上面的 root 的 d													
		}
	}
}

int main()
{
    int n, m;
    while (cin >> n >> m) {
		ve.resize(n);
		parent.assign(n, -1);
		d.assign(n, 0);
		low.assign(n, 0);
		bridge.clear();
		cutPoint.assign(n, false);	
		dfsTime = 0;

		for (int i = 0, a, b; i < m; i++) {
			cin >> a >> b;
			a--, b--;
			ve[a].emplace_back(b);
			ve[b].emplace_back(a);
		}

		int br0 = 0, br1 = 0;		//有零條及一條 bridge 的 component 數
		for (int u = 0; u < n; u++) {
			if (!d[u]) {
				size_t s = bridge.size();	//包含 u 的 BCC 的總 bridge 數
				findBCC(u);
				if (s == bridge.size()) {	//BCC 連結的 bridge 數，如果與 s 相同，表此 component 為 isolated ( 沒有 bridge )
					br0++;
				}
			}
		}

		map<int, int> ma;
		if (bridge.size() == 0 && br0 == 1)	cout << "0" << endl;		//沒有 bridge
		else {
			for (int u = 0; u < n; u++) {		
				ma[low[u]] += 0;
				for (auto& v : ve[u]) {
					if (low[v] != low[u]) {		// v, u 為兩個不同 component，ma[low[i]] + 1代表紀錄此 component 與外相連的 bridge數 + 1
						++ma[low[u]];
					}
				}
			}

			for (auto& de : ma) {
				if (de.second == 1) ++br1;
			}
			cout << br0 + (br1 + 1) / 2 << endl;
		}
		

		for (int i = 0; i < ve.size(); i++) {
			if (!ve[i].empty())	ve[i].clear();
		}
		if (!ve.empty())	ve.clear();
    }	
}
