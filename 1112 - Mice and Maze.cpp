#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pr;        

vector<vector<pr>> edge;            //edge[u].first = v, edge[u].second = weight
vector<int> d;

int N, E, T;    //number of cells, number of exit cell, timer

void Dijkstra(int s) {
    priority_queue<pr, vector<pr>, greater<pr>> pq;     //cell u number, weight
    d[s] = 0;
    pq.emplace(make_pair(s, 0));

    while (!pq.empty()) {        
        pr u = pq.top();
        pq.pop();
        for (auto v : edge[u.first]) {      
            if (d[v.first] > d[u.first] + v.second) {
                d[v.first] = d[u.first] + v.second;
                pq.emplace(make_pair(v.first, d[v.first]));
            }
            
        }
    }
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--) {
        int M;
        cin >> N >> E >> T >> M;   

        edge.resize(N);
        d.assign(N, INT32_MAX);
        int a, b, time;

        for (int i = 0; i < M; i++) {
            cin >> a >> b >> time;
            edge[b-1].emplace_back( make_pair(a-1, time));
        }
        Dijkstra(E-1);
        int cnt = 0;
        for (int i = 0; i < N; i++) {
            if (d[i] <= T) cnt++;
        }
        cout << cnt << endl;
        if (cases)   cout << endl;

        for (int i = 0; i < N; i++) edge[i].clear();        
        edge.clear();
        d.clear();
    }
}
