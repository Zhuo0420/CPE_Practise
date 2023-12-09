#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> ve;
vector<int> d, parent, low;
vector<int> cutPoint;
vector<int> numChildren;
int dfsTime = 0;

void findCutPoint(int u) {
    d[u] = low[u] = ++dfsTime;
    for (int v : ve[u]) {
        if (d[v] == 0) {
            parent[v] = u;
            numChildren[u]++;
            findCutPoint(v);
            low[u] = min(low[u], low[v]);
            if (parent[u] != -1) {
                if (low[v] >= d[u]) cutPoint[u]++;
            }
        }
        else if (parent[u] != v) {      //backEdge
            low[u] = min(low[u], d[v]);
        }
    }
    if (parent[u] == -1 && numChildren[u] > 1) {
        cutPoint[u]++;
    }
}

int main()
{
    int n, m;       //火車數 (0 ~ n-1)，目標數
    while (cin >> n >> m && n && m) {
        //init  
        ve.resize(n);
        d.assign(n, 0);
        low.assign(n, 0);
        parent.assign(n, -1);
        numChildren.assign(n, 0);
        cutPoint.assign(n, 1);
        int a, b;
        while (cin >> a >> b && a != -1 && b != -1) {            
            ve[a].emplace_back(b);
            ve[b].emplace_back(a);
        }
        //dfs
        for (int u = 0; u < n; u++) {
            if (!d[u])   findCutPoint(u);
        }
        for (int i = 0; i < m; i++) {
            int maxNum = 0;
            int maxIndex = 0;
            for (int j = 0; j < n; j++) {
                if (cutPoint[j]) {
                    if (cutPoint[j] > maxNum) {
                        maxNum = cutPoint[j];
                        maxIndex = j;
                    }
                }
            }
            cout << maxIndex << " " << maxNum << endl;
            cutPoint[maxIndex] = 0;
        }
        cout << endl;
        for (int i = 0; i < ve.size(); i++) {
            if (!ve.empty()) ve[i].clear();
        }
        if (!ve.empty()) ve.clear();
    }    
}
