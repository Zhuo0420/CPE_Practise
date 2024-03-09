#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

vector<tuple <int, int, int >> road;
vector<int> parent;
vector<int> setRank;
int m, n;       //node, edge
int wSum;

bool cmp(tuple<int, int, int>e1, tuple<int, int, int> e2){
    return get<2>(e1) < get<2>(e2);
}

int findSet(int u) {
    if (u != parent[u]) {
        parent[u] = findSet(parent[u]);
    }
    return parent[u];
}

void link(int x, int y) {
    if (setRank[x] > setRank[y]) {
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
    parent.assign(m, 0);
    setRank.assign(m, 0);
    for (int i = 0; i < m; i++) {
        parent[i] = i;
    }

    wSum = 0;
    for (tuple<int, int, int> edge : road) {
        int x = findSet(get<0>(edge));
        int y = findSet(get<1>(edge));
        int w = get<2>(edge);

        if (x != y) {
            link(x, y);     
            wSum += w;
        }
    }        
}

int main()
{    
    while (cin >> m >> n && m != 0 && n != 0) {
        road.clear();
        int x, y, w;
        int oriSum = 0;
        for (int i = 0; i < n; i++) {
            cin >> x >> y >> w;
            road.emplace_back(make_tuple(x, y, w));
            oriSum += w;
        }
        sort(road.begin(), road.end(), cmp);
        kruskalMST();
        cout << oriSum - wSum << endl;
    }
    return 0;
}
