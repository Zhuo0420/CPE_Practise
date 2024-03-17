#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M;       //node edge
int s, t;       //source sink
vector<vector<int>> graph;      //edge
vector<vector<int>> rc;         //residual capacity
vector<int> d;

void bfs() {
    queue<int> Q;
    for (int i = 1; i < N * 2 + 3; i++) {
        d[i] = INT32_MAX;
    }
    d[s] = 0;
    Q.emplace(s);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        for (auto v : graph[u]) {
            if (rc[u][v] > 0 && d[v] == INT32_MAX) {
                d[v] = d[u] + 1;
                Q.emplace(v);
            }
        }
    }
}

int dfs(int u, int pmrc) {
    if (u == t)
        return pmrc;
    for (auto v: graph[u]) {
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
        if (d[t] == INT32_MAX) return mf;
        while (1) {
            int mrc = dfs(s, INT32_MAX);
            if (mrc == 0) break;
            mf += mrc;
        }
    }
    return mf;
}

int main()
{    
    while (cin >> N) {       
        graph.clear();
        d.clear();
        rc.clear();
        graph.resize(N * 2 + 3);
        d.resize(N * 2 + 3);        
        rc.resize(N * 2 + 3);
        for (int i = 1; i < N * 2 + 3; i++) {
            rc[i].assign(N * 2 + 3, 0);
        }
        s = N * 2 + 1;
        t = N * 2 + 2;
        int tmpC;
        for (int i = 1; i <= N; i++) {            
            cin >> tmpC;
            graph[i].emplace_back(i+N);
            graph[i + N].emplace_back(i);     
            rc[i][i+N] = tmpC;          //residual capacity
        }
        cin >> M;
        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v >> tmpC;
            u += N;
            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
            rc[u][v] = tmpC;
        }
        int B, D;
        cin >> B >> D;
        int tmpS, tmpT;
        for (int i = 0; i < B; i++) {
            cin >> tmpS;
            graph[s].emplace_back(tmpS);
            rc[s][tmpS] = INT32_MAX;            
        }
        for (int i = 0; i < D; i++) {
            cin >> tmpT;
            graph[tmpT + N].emplace_back(t);
            rc[tmpT + N][t] = INT32_MAX;            
        }        
        cout << dinic() << endl;
    }
}
