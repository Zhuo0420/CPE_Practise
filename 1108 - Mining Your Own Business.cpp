#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
using namespace std;

vector<vector<int>> ve;
vector<int> d, parent, low;
vector<bool> cutPoint;
stack<pair<int, int>> edgeStack;
vector<unordered_set<int>> bcc;		//biconnected component
int dfsTime = 0;

void biCon(int u) {
	d[u] = low[u] = ++dfsTime;	
	int child = 0;
	for (int v : ve[u]) {
		if (!d[v]) {
			parent[v] = u;
			edgeStack.push({ u, v });
			child++;
			biCon(v);
			low[u] = min(low[u], low[v]);
			if (low[v] >= d[u]) {
				cutPoint[u] = true;
				unordered_set<int> US;
				int cu, cv;
				do {
					cu = edgeStack.top().first;
					cv = edgeStack.top().second;
					US.emplace(cu);
					US.emplace(cv);
					edgeStack.pop();
				} while (cu != u && cv != v);
				bcc.emplace_back(US);
			}
		}
		else if (d[v]<d[u] && parent[u] != v)	low[u] = min(low[u], d[v]);
	}	
	if (parent[u] == -1 && child == 1)
		cutPoint[u] = false;
}

int main()
{
	int N;
	int cases = 0;
	while (cin >> N && N) {
		ve.resize(N + 1);
		parent.assign(N + 1, -1);
		d.assign(N + 1, 0);
		low.assign(N + 1, 0);
		cutPoint.assign(N + 1, false);
		bcc.clear();
		dfsTime = 0;

		for (int i = 0, a, b; i < N; i++) {
			cin >> a >> b;
			a--, b--;
			ve[a].emplace_back(b);
			ve[b].emplace_back(a);
		}
		
		biCon(0);		

		long long int ans1 = 0, ans2 = 1;		//最少的逃生梯數量, 方案總數
		if (bcc.size() == 1) ans1 = 2, ans2 = bcc[0].size() * (bcc[0].size() - 1) / 2;	//C(bcc[0].size(), 2)
		else {
			for (auto& i : bcc) {
				int counter = 0;
				for (auto& j : i)	if (cutPoint[j])	counter++;
				if (counter == 1)	++ans1, ans2 *= i.size() - 1;		//此 component 只有一個 cutpoint連結，C(i.size(), 1);
			}
		}

		cout << "Case " << ++cases << ": " << ans1 << " " << ans2 << endl;

		for (int i = 0; i < ve.size(); i++) {
			if (!ve[i].empty())	ve[i].clear();
		}
		if (!ve.empty())	ve.clear();
	}
}
