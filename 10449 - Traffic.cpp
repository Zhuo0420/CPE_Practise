#include <iostream>
#include <vector>
#include <unordered_set>
#include <math.h>
using namespace std;

vector<vector<pair<int, int>>> edge;
vector<int> busyness;
vector<int> d;
unordered_set<int> store;

void Bellman(int n) {
    d[0] = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int u = 0; u < n; u++) {
            for (auto v : edge[u]) {
                if (d[u] != INT32_MAX && d[v.first] > d[u] + v.second) {
                    d[v.first] = d[u] + v.second;
                }
            }
        }
    }
    for (int u = 0; u < n; u++) {
        for (auto v : edge[u]) {
            if (d[v.first] > d[u] + v.second) {
                d[v.first] = d[u] + v.second;
                store.emplace(v.first);
            }
        }
    }
}

int main()
{
    int n, w, r, u, v, q;
    int cases = 0;
    while (cin >> n) {
        store.clear();
        busyness.assign(n, 0);
        d.assign(n, INT32_MAX);
        for (int i = 0; i < n; i++) {
            cin >> w;
            busyness[i] = w;
        }
        
        cin >> r;
        edge.assign(n, vector<pair<int, int>>());
        for (int i = 0; i < r; i++) {
            cin >> u >> v;
            edge[u - 1].emplace_back(make_pair(v - 1, pow(busyness[v - 1] - busyness[u - 1], 3.0)));
        }

        cout << "Set #" << ++cases << endl;
        Bellman(n);
        cin >> q;
        int tmp;
        for (int i = 0; i < q; i++) {
            cin >> tmp;            
            if (store.count(tmp - 1) || d[tmp - 1] < 3 || d[tmp - 1] == INT32_MAX)   cout << "?" << endl;
            else    cout << d[tmp - 1] << endl;
        }
    }        
}