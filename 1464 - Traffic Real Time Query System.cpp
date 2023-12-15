#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> ve;
vector<vector<int>>  G;             //圓方樹
vector<pair<int, int>> edges;
vector<int> d, low, parent;
int dfsTime, bcc_cnt =  0;          //bcc ( 點雙連通分量 biconnected component ) 的數量的 counter = 圓方樹中方點數量
vector<bool> cutPoint, vis;              
vector <int> tin, tout, anc, dep;
stack<int> nodeStack;


void tarjan(int u) {          //先標記出cutPoint
    d[u] = low[u] = ++dfsTime;
    int child = 0;
    nodeStack.emplace(u);       //儲存遍歷過的node
    for (int v : ve[u]) {
        if (d[v] == 0) {
            parent[v] = u;
            child++;
            tarjan(v);
            low[u] = min(low[u], low[v]);
            if (low[v] >= d[u]) {
                cutPoint[u] = true;
                
                int w;
                do {
                    w = nodeStack.top();            //建立圓方樹
                    nodeStack.pop();
                    G[bcc_cnt].emplace_back(w);     //方點編號 bcc_cnt 與 node w 互相連結(雙向)
                    G[w].emplace_back(bcc_cnt);
                } while (v != w);
                G[bcc_cnt].emplace_back(u);         //cut point 也要存進去，但不pop掉
                G[u].emplace_back(bcc_cnt);
                bcc_cnt++;
            }
        }
        else if (parent[u] != v) {
            low[u] = min(low[u], d[v]);
        }
    }
    if (parent[u] == -1 && child > 1) {
        cutPoint[u] = true;
    }
}

void build(int u, int p) {          //標出圓方樹的 tin, tout, dep (從 1 開始標記)
    static int t = 0;    
    tin[u] = ++t;        
    dep[u] = dep[p] + 1, anc[u] = p;    
    vis[u] = true;
    for (int& i : G[u]) {
        if (i != p) {
            build(i, u);
        }
    }
    tout[u] = ++t;
}

bool isAnc(int a, int b) {
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

//求共同祖先
int LCA(int s, int t) {
    if (isAnc(s, t)) return s;
    if (isAnc(t, s)) return t;
    while (!isAnc(s, t)) s = anc[s];
    return s;
}

int Calc(int u, int v) {    
    return (dep[u] + dep[v] - 2 * dep[LCA(u, v)]) / 2 - 1;
}

int main()
{
    int n, m;       //node, edge
    while (cin >> n >> m && n && m) {
        ve.resize(n);
        G.assign(n * 2, vector<int>());
        edges.resize(m);
        d.assign(n, 0);
        low.assign(n, 0);
        parent.assign(n, -1);
        cutPoint.assign(n, false);
        
        dfsTime = 0;
        bcc_cnt = n;        //由 n 開始，與原node的編號做區別
        
        for (int i = 0, a, b; i < m; i++) {
            cin >> a >> b;
            a--, b--;
            ve[a].emplace_back(b);
            ve[b].emplace_back(a);
            edges[i] = { a, b };
        }

        for (int u = 0; u < n; u++) {
            if (!d[u])   tarjan(u);
        }
        //建立完圓方樹，可找樹中的LCA、level
        
        tin.assign(n * 2, 0);
        tout.assign(n * 2, 0);        
        dep.assign(n * 2, 0);
        anc.assign(n * 2, 0);
        vis.assign(n * 2, false);
                             
        for (int i = 0; i < n * 2; i++)
            if (!vis[i])     build(i, 0);
        //建立tin, tout, dep(level)

        int Q, edgeNum1, edgeNum2;
        cin >> Q;
        for (int i = 0; i < Q; i++) {
            int f1, f2, s1, s2;
            cin >> edgeNum1 >> edgeNum2;         //edge 編號
            edgeNum1--;
            edgeNum2--;
            f1 = edges[edgeNum1].first;
            f2 = edges[edgeNum1].second;
            s1 = edges[edgeNum2].first;
            s2 = edges[edgeNum2].second;

            int a = Calc(f1, s1), b = Calc(f1, s2), c = Calc(f2, s1), d = Calc(f2, s2);
            
            cout << max(max(a, b), max(c, d)) << endl;
        }

        for (int i = 0; i < ve.size(); i++) {
            if (!ve[i].empty())  ve[i].clear();
        }
        if (!ve.empty()) ve.clear();
        for (int i = 0; i < edges.size(); i++) {
            if (!edges.empty())  edges.clear();
        }
        if (!edges.empty())  edges.clear();
    }
}
