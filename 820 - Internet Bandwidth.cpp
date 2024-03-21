#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int C = 1001;
vector<vector<int>>G;
int rc[C][C];
int d[C];
int cases = 0;
int n, s, t;

void init() {
    G.clear();    
    G.resize(n + 1, vector<int>());
    for (int i = 0; i < C; i++) {        
        for (int j = 0; j < C; j++) {
            rc[i][j] = 0;
        }
    }
}

void bfs() {
    for (int i = 0; i <= n; i++) {
        d[i] = INT32_MAX;
    }
    d[s] = 0;
    queue<int> Q;
    Q.emplace(s);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (auto v : G[u]) {
            if (rc[u][v] != 0 && d[v] == INT32_MAX) {
                d[v] = d[u] + 1;
                Q.emplace(v);
            }
        }
    }
}

int dfs(int u, int pmrc) {
    if (u == t)  return pmrc;
    for (auto v : G[u]) {
        if (rc[u][v] > 0 && d[v] == d[u] + 1) {
            int mrc = dfs(v, min(pmrc, rc[u][v]));

            if (mrc > 0) {
                rc[u][v] -= mrc;
                rc[v][u] += mrc;
                return mrc;
            }
        }
    }
    return 0;
}

int dinic() {
    int mf = 0;
    while (1) {
        bfs();
        if (d[t] == INT32_MAX)  return mf;
        while (1) {
            int mrc = dfs(s, INT32_MAX);
            if (mrc == 0)    
                break;
            mf += mrc;
        }      
    }
}

int main()
{    
    while (cin >> n && n) {
        int e;
        cin >> s >> t >> e;
        init();
        for (int i = 0; i < e; i++) {
            int u, v, ca;
            cin >> u >> v >> ca;
            G[u].emplace_back(v);
            G[v].emplace_back(u);
            rc[u][v] += ca;
            rc[v][u] += ca;            
        }        
        cout << "Network " << ++cases << endl;
        cout << "The bandwidth is " << dinic() << "." << endl;
        cout << endl;
    }
}
