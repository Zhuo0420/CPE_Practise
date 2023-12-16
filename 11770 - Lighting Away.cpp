#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> ve;
vector<int> d, low, parent, lead, follow;
stack<int> nodeStack;
vector<bool> inStack;
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
        else if (inStack[v]) {
            low[u] = min(low[u], d[v]);
        }
    }
    if (low[u] == d[u]) {
        scc_cnt++;
        int w;
        do {
            w = nodeStack.top();
            nodeStack.pop();
            inStack[w] = false;
            lead[w] = u;
        } while (w != u);
    }
}

void isfollow(int u) {
    for (int v : ve[u]) {
        if (lead[v] != v)    follow[v]++;       //v 會被 u 燈開啟
        if (lead[v] != lead[u])   follow[lead[v]]++;        //如果可以從 u 強通道走道 v 強通道 ，就刪掉 v 強通道的開燈點
    }
}

int main()
{
    int cases;
    cin >> cases;
    for (int ca = 1; ca <= cases; ca++) {        
        int N, M;
        cin >> N >> M;
        ve.assign(N, vector<int>());
        d.assign(N, 0);
        low.assign(N, 0);
        parent.assign(N, -1);
        lead.assign(N, 0);
        follow.assign(N, 0);
        inStack.assign(N, false);
        dfsTime = 0;

        for (int i = 0, a, b; i < M; i++) {
            cin >> a >> b;
            a--, b--;
            ve[a].emplace_back(b);
        }
        for (int u = 0; u < N; u++) {
            if (!d[u])
                tarjan(u);
        }
        for (int u = 0; u < N; u++) {
            isfollow(u);
        }
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (!follow[i] && lead[i] == i)  ans++;     //i無法被其他燈開啟，且是一個SCC的root
        }
        cout << "Case " << ca << ": " << ans << endl;
    }
}
