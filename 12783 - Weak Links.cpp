#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

vector<vector<int>> ve;
vector<pair<int, int>> bridge;
int* d, * parent, * low;
int dfsTime = 0;
int counter = 0;

void findBridge(int u) {
    d[u] = low[u] = ++dfsTime;
    for (auto v : ve[u]) {
        if (d[v] == 0) {
            parent[v] = u;
            findBridge(v);
            low[u] = min(low[u], low[v]);
            if (low[v] > d[u]) {        //bridge
                counter++;
                if (u > v) bridge.emplace_back(make_pair(v, u));
                else    bridge.emplace_back(make_pair(u, v));
            }
        }
        else if (v != parent[u]) {
            low[u] = min(low[u], d[v]);
        }
    }
}

int main()
{
    int n, m;
    while (cin >> n >> m && n && m) {
        ve.resize(n);
        d = new int[n];
        parent = new int[n];
        low = new int[n];
        memset(d, 0, sizeof(int) * n);
        memset(parent, -1, sizeof(int) * n);
        memset(low, 0, sizeof(int) * n);
        dfsTime = 0;
        counter = 0;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            ve[a].emplace_back(b);
            ve[b].emplace_back(a);
        }

        for (int u = 0; u < n; u++) {
            if (d[u] == 0) {
                findBridge(u);
            }
        }
        sort(bridge.begin(), bridge.end());
        cout << counter;
        if (counter) cout << " ";
        for (int i = 0; i < counter; i++) {
            cout << bridge[i].first << " " << bridge[i].second;
            if (i != counter - 1)    cout << " ";
        }
        cout << endl;
        for (int i = 0; i < ve.size(); i++)     if (!ve[i].empty())  ve[i].clear();        
        if (!ve.empty()) ve.clear();
        if (!bridge.empty()) bridge.clear();
    }
}
