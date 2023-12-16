#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<vector<int>> ve;
int* d, * parent, * low, * flag;
int dfsTime = 0;

int findset(int u) {
	if(!flag[u] || flag[u] == u)	return u;		//一個 component 的 root
	else	return flag[u] = findset(flag[u]);
}

void unionset(int a, int b) {
	a = findset(a); b = findset(b);
	if(a < b)	flag[a] = b;
	else	flag[b] = a;
}

void dfs(int u) {
	d[u] = low[u] = ++dfsTime;
	for (int v : ve[u]) {
		if(d[v] == 0) {
			parent[v] = u;
			dfs(v);
			low[u] = min(low[v], low[u]);
			if (low[v] > d[u])	unionset(u, v);		//bridge
		}
		else if (parent[u] != v) {
			low[u] = min(low[u], d[v]);
		}
	}
}

int main()
{
	int R, C, Q;		//房間數，走廊數，挑戰數
	while (cin >> R >> C >> Q && R && C && Q) {
		//init
		d = new int[R];
		parent = new int[R];
		low = new int[R];
		flag = new int[R];
		memset(d, 0, sizeof(int) * R);
		memset(parent, -1, sizeof(int) * R);
		memset(low, 0, sizeof(int) * R);
		memset(flag, 0, sizeof(int) * R);
		dfsTime = 0;
		ve.resize(R);		
		for (int i = 0; i < C; i++) {
			int a, b;
			cin >> a >> b;
			a--; b--;
			ve[a].emplace_back(b);
			ve[b].emplace_back(a);
		}
		
		//dfs
		for (int i = 0; i < R; i++) {
			if (d[i] == 0)	dfs(i);
		}
		for (int i = 0; i < Q; i++) {
			int a, b;
			cin >> a >> b;
			a--; b--;
			if (findset(a) == findset(b))	cout << "Y" << endl;    //a, b 兩點的路徑皆為 bridge 組成
			else	cout << "N" << endl;
		}
		cout << "-" << endl;
		for(auto &i : ve)	if(!i.empty())	i.clear();
		if (!ve.empty())	ve.clear();
	}
}
