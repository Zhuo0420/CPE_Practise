#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> G;
vector<vector<int>> rc;
vector<int>parent;
int m[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };
int s, t;
int x, y, p;
char c;

void init() {   
    for (int i = 0; i < rc.size(); i++) { rc[i].clear(); }
    rc.clear();
    rc.resize(t+1, vector<int>(t+1));    
    G.clear();
    G.resize(t+1);
}

void input() {
    int node = x * y;
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            int u = y * i + j + 1;
            cin >> c;
            if (c == '.') { 
                rc[u][u + node] = 1; 
                G[u].emplace_back(u + node); 
                G[u + node].emplace_back(u);//
            }
            else if (c == '@') { 
                rc[u][u + node] = INT32_MAX; 
                G[u].emplace_back(u + node); 
                G[u + node].emplace_back(u);//
            }
            else if (c == '*') {
                rc[u][u + node] = 1;
                rc[s][u] = 1;
                G[u].emplace_back(u + node);
                G[u + node].emplace_back(u);//
                G[s].emplace_back(u);
                G[u].emplace_back(s);//
            }
            else if (c == '#') {
                rc[u][u + node] = INT32_MAX;
                rc[u + node][t] = p;
                G[u].emplace_back(u + node);
                G[u + node].emplace_back(u);//
                G[u + node].emplace_back(t);
                G[t].emplace_back(u + node);//
            }
            for (int k = 0; k < 4; k++) {
                int nx = i + m[k][0];
                int ny = j + m[k][1];
                if (nx >= 0 && nx < x && ny >= 0 && ny < y) {
                    int v = y * nx + ny + 1;
                    rc[u + node][v] = INT32_MAX;
                    G[u + node].emplace_back(v);
                    G[v].emplace_back(u + node);
                }
            }
        }
    }

}

void bfs() {
    parent.assign(t+1, -1);    
    queue<int>Q;
    Q.emplace(s);
    parent[s] = s;
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        if (u == t)  return;
        for (auto v : G[u]) {
        //for(int v = 0; v <= t; v++){
            if (rc[u][v]>0 && parent[v]==-1) {
                parent[v] = u;
                Q.emplace(v);
            }
        }
    }
}

int edmondsKarp() {
    int mf = 0;
    while (1) {
        bfs();
        if (parent[t] == -1) return mf;
        int pmf = INT32_MAX;
        for (int v = t; v != s; v = parent[v]) {
            pmf = min(rc[parent[v]][v], pmf);            
        }
        mf += pmf;
        for (int v = t; v != s; v = parent[v]) {
            rc[parent[v]][v] -= pmf;
            rc[v][parent[v]] += pmf;
        }                
    }
    return 0;
}

int main()
{    
    while (cin >> x >> y >> p) {        
        s = 0;
        t = x * y * 2 + 1;
        init();
        input();
        cout << edmondsKarp() << endl;     
    }
}