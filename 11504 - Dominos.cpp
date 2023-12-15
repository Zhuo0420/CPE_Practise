#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> ve;
vector<int> d, low, parent, com;
vector<bool> inStack;
stack<int> nodeStack;
int dfsTime;
int scc_cnt;

void tarjan(int u) {
    d[u] = low[u] = ++dfsTime;
    nodeStack.emplace(u);
    inStack[u] = true;
    for (int v : ve[u]) {
        if (!d[v]) {
            parent[v] = u;
            tarjan(v);
            low[u] = min(low[u], low[v]);           
            
        }
        else if(inStack[v]) {                   //v 已被推入stack過 (被遍歷過後還未被歸納成SCC的點)  tree/back/forward/cross edge
            low[u] = min(low[u], d[v]);         //backEdge 的 d or low (low[u], low[v])
        }
    }
    if (low[u] == d[u]) {           //找SCC一定要使用low[u] == d[u]                
        int w;
        do {
            w = nodeStack.top();
            nodeStack.pop();
            com[w] = scc_cnt;           //紀錄每個點屬於編號scc_cnt的牆連通向量
            inStack[w] = false;
        } while (w != u);
        scc_cnt++;
    }
}

int main()
{
    int cases;
    cin >> cases;
    while (cases--) {
        int n, m;       //node, edge
        cin >> n >> m;
        ve.assign(n, vector<int>());
        d.assign(n, 0);
        low.assign(n, 0);
        parent.assign(n, -1);
        com.assign(n, 0);        
        inStack.assign(n, false);
        dfsTime = 0;
        scc_cnt = 0;

        for (int i = 0, a, b; i < m; i++) {
            cin >> a >> b;
            a--, b--;
            ve[a].emplace_back(b);
        }

        for (int u = 0; u < n; u++) {
            if (!d[u])   {
                tarjan(u);
                //int w;
                //if (!nodeStack.empty()) {
                //    do {
                //        w = nodeStack.top();
                //        nodeStack.pop();
                //        com[w] = scc_cnt;           //紀錄每個點屬於編號scc_cnt的強連通向量
                //    } while (w != u);
                //    scc_cnt++;
                //}
            }
        }


        int ans = 0;
        vector<int> conxt(scc_cnt);         //每個強連通向量的出度

        for (int i = 0; i < n; i++) {           //找點 i 所連結的點 j 是否屬於同一強連通向量
            for (auto& j : ve[i]) {
                if (com[i] != com[j])  ++conxt[com[j]];         //如不同，指兩個強連通向量被連在一起，編號 j 的點的強連通分量編號的出度+1
            }
        }
        for (auto& i : conxt)  if (!i)  ans++;
        if (!ans)    
            ans++;
        cout << ans << endl;
    }
}
