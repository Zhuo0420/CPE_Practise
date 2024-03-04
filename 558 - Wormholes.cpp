#include <iostream>
#include <vector>
using namespace std;

vector<vector<pair<int, int>>>V;        //V[u] = {v, wight}
vector<int> d;
int n, m;           //node, edge

void BellMan() {            //鈴男
    vector<int> Q;
    d[0] = 0;

    for (int i = 1; i < n; i++) {
        for (int u = 0; u < V.size();u++) {      //u 對於所有 edge
            for (auto v : V[u]) {
                if (d[v.first] > d[u] + v.second)
                    d[v.first] = d[u] + v.second;
            }
        }
    }
    
    for (int u = 0; u < V.size(); u++) {
        for (auto v : V[u]) {
            if (d[v.first] > d[u] + v.second) { 
                cout << "possible" << endl; 
                return; 
            }
        }
    }
    cout << "not possible" << endl;
}


int main()
{
    int c;
    cin >> c;
    while (c--) {
        cin >> n >> m;
        V.assign(m, vector<pair<int, int>>());
        d.assign(n, INT32_MAX);
        int x, y, t;
        for (int i = 0; i < m; i++) {
            cin >> x >> y >> t;
            V[x].emplace_back(make_pair(y, t));
        }
        BellMan();
    }
}
