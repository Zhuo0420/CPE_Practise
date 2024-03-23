#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int m, w;
int s, t;
vector<vector<int>> G;
vector<vector<int>> rc;
vector<int> d;
vector<int>parent;

void init() {
	s = 1, t;
	G.clear();
	rc.clear();
	G.resize(m * 2);
	rc.assign(m * 2, vector<int>(m * 2));
	d.resize(m * 2);

	parent.resize(m * 2);
}

void buildG() {	
	int node = m - 2;		//扣掉 source sink 的 node 數量
	t = m + node;
	int nd, ca;
	for (int i = 1; i <= node; i++) {      //node's capacity
		cin >> nd >> ca;
		G[nd].emplace_back(nd + node);
		G[nd + node].emplace_back(nd);
		rc[nd][nd + node] = rc[nd + node][nd] = ca;
	}

	int u, v;
	for (int i = 0; i < w; i++) {
		cin >> u >> v >> ca;
		if (u == m) u = t;
		if (v == m) v = t;
		int us = (u != s && u != t ? u + node : u);
		int vs = (v != s && v != t ? v + node : v);
		rc[us][v] = rc[vs][u] = ca;
		G[us].emplace_back(v);
		G[v].emplace_back(us);
		G[vs].emplace_back(u);
		G[u].emplace_back(vs);
	}
}

//void bfs() {
//	for (int i = 0; i < d.size(); i++) {
//		d[i] = INT32_MAX;
//	}
//	queue<int> Q;
//	Q.emplace(s);
//	d[s] = 1;
//	while (!Q.empty()) {
//		int u = Q.front();
//		Q.pop();
//		for (int v : G[u]) {
//			if (rc[u][v] > 0 && d[v] == INT32_MAX) {
//				d[v] = d[u] + 1;
//				Q.emplace(v);
//			}
//		}
//	}
//}
//
//int dfs(int u, int pmrc) {
//	if (u == t) return pmrc;
//	for (auto v : G[u]) {
//		if (rc[u][v] > 0 && d[v] == d[u] + 1) {
//			int mrc = dfs(v, min(rc[u][v], pmrc));
//			if (mrc > 0) {
//				rc[u][v] -= mrc;
//				rc[v][u] += mrc;
//				return mrc;
//			}
//		}
//	}
//	return 0;
//}
//
//int dinic() {
//	int mf = 0;
//	while (1) {
//		bfs();
//		if (d[t] == INT32_MAX)  return mf;
//		while (1) {
//			int mrc = dfs(s, INT32_MAX);
//			if (mrc == 0) break;
//			mf += mrc;
//		}
//	}
//}

void bfs()
{
	for (int i = 0; i < parent.size(); i++)	parent[i] = -1;
	parent[s] = s;
	queue< int > q;
	q.push(s);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();

		if (u == t)
			return;

		//for (int v = 0; v < m * 2; v++)
		for(auto v:G[u])
			if (rc[u][v] > 0 && parent[v] == -1)
			{
				parent[v] = u;
				q.push(v);
			}
	}
}

int edmondsKarp()
{
	int maxFlow = 0;
	while (true)
	{
		bfs();

		if (parent[t] == -1)
			return maxFlow;

		int minResCap = INT32_MAX;
		for (int v = t; v != s; v = parent[v])
			minResCap = min(minResCap, rc[parent[v]][v]);

		maxFlow += minResCap;
		for (int v = t; v != s; v = parent[v])
		{
			rc[parent[v]][v] -= minResCap;
			rc[v][parent[v]] += minResCap;
		}
	}
}



int main()
{
	while (cin >> m >> w && (m || w)) {
		init();
		buildG();
		//cout << dinic() << endl;
		cout << edmondsKarp() << endl;
	}
}
