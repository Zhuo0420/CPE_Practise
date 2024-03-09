#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

vector<tuple<int, int, int>>edges;
vector<int>parent;
vector<int>setRank;

int n, m;       //node, edge

bool cmp(tuple<int, int, int>e1, tuple<int, int, int>e2) {
    return get<2>(e1) < get<2>(e2);
}

int findSet(int x) {
    if (x != parent[x]) {
        parent[x] = findSet(parent[x]);
    }
    return parent[x];
}

void link(int x, int y) {
    if (setRank[x] < setRank[y]) {
        parent[y] = x;
    }
    else {
        parent[x] = y;
        if (setRank[x] == setRank[y]) {
            setRank[y]++;
        }
    }
}

void kruskalMST() {
    parent.assign(n, 0);
    setRank.assign(n, 0);

    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    bool flag = 0;
    for (auto v : edges) {
        int x = findSet(get<0>(v));
        int y = findSet(get<1>(v));
        int w = get<2>(v);
        if (x != y) {
            link(x, y);            
        }
        else {
            if (!flag)  cout << w, flag = true;
            else  cout << " " << w;
        }
    }
    if (!flag)   cout << "forest";
}

int main()
{
    while (cin >> n >> m && n && m) {
        edges.clear();
        int u, v, w;
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> w;
            edges.emplace_back(make_tuple(u, v, w));
        }
        sort(edges.begin(), edges.end(), cmp);
        kruskalMST();
        cout << endl;
    }    
    return 0;
}
