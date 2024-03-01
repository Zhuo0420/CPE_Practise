#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<pair<int, int>>> V;       //裝 edge V[u] = {v, w}
vector<int>d;
int S, T;       // start, end

void dilkstra(int S) {
    priority_queue<int> pq;    
    pq.emplace(S);
    d[S] = 0;

    while (!pq.empty()) {
        int u = pq.top();
        pq.pop();        
        for (auto v : V[u]) {
            if (v.first!=-1 && d[v.first] > d[u] + v.second) {
                d[v.first] = d[u] + v.second;
                pq.emplace(v.first);
            }
        }        
    }
    if (d[T] != INT16_MAX)   cout << d[T] << endl;
    else    cout << "unreachable" << endl;
}

int main()
{
    int N;
    cin >> N;
    int cases = 0;
    while (++cases && cases <= N) {
        int n, m;         //node, edge
        cin >> n >> m >> S >> T;        
        V.assign(n, vector<pair<int, int>>());
        d.assign(n, INT16_MAX);
        for (int i = 0; i < n; i++)     V[i].emplace_back(make_pair(-1, 0));
        for (int i = 0; i < m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            V[u].emplace_back(make_pair(v, w));
            V[v].emplace_back(make_pair(u, w));
        }
        cout << "Case #" << cases << ": ";
        dilkstra(S);
    }    
}
