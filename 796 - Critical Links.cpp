#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> nodes;
int* d;
int* low;
int* parent;
int dfsTime = 0;
int counter = 0;
vector<pair<int, int>> bridges;

void findBridges(int u) {
    d[u] = low[u] = ++dfsTime;
    for (int v : nodes[u]) {
        if (d[v] == 0) {
            parent[v] = u;
            findBridges(v);
            low[u] = min(low[u], low[v]);
            if (low[v] > d[u]) {
                counter++;
                if (u < v)
                    bridges.emplace_back(make_pair(u, v));
                else
                    bridges.emplace_back(make_pair(v, u));
            }
        }
        else if (v != parent[u])
            low[u] = min(low[u], d[v]);
    }
}

int main()
{
    int node;
    while (cin >> node) {
        nodes.resize(node);
        d = new int[node]();
        low = new int[node]();
        parent = new int[node]();
        dfsTime = 0;
        counter = 0;
        int key;
        int val;
        int valNum;    
        char tmp;
        for (int i = 0; i < node; i++) {
            cin >> key >> tmp >> valNum >> tmp;                        
            for (int j = 0; j < valNum; j++) {
                cin >> val;
                nodes[key].emplace_back(val);
            }
        }
        for(int i=0;i<node;i++){
            if(d[i] == 0)
                findBridges(i);
        }
        sort(bridges.begin(), bridges.end());
        cout << counter << " critical links" << endl;
        for (int i = 0; i < counter; i++) {
            cout << bridges[i].first << " - " << bridges[i].second << endl;
        }
        cout << endl;
        delete[]d;
        delete[]parent;
        delete[]low;
        for (auto i : nodes) if (!i.empty()) i.clear();
        if (!nodes.empty())  nodes.clear();
        if (!bridges.empty()) bridges.clear();         
    }
}
