#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

vector<vector<int>> G;
vector<vector<int>> reG;
vector<int> eng;
vector<int>d;
unordered_set<int>  us;

void dfs(int u) {
    us.emplace(u);
    for (auto v : reG[u]) {
        if (!us.count(v))    dfs(v);
    }
}

void bellman(int n) {
    d[1] = 100;

    for (int i = 1; i < n; i++) {
        for (int u = 1; u <= n; u++) {
            for (auto v : G[u]) {
                if (d[u] && d[v] < d[u] + eng[v])    d[v] = d[u] + eng[v];     //d[u] == 0 => 中途死掉，後面的d值都將維持INT32_MIN
            }
        }
    }
//
    bool flag = false;
    for (int u = 1; u <= n; u++) {      //正數 cycle 一定為 winnable
        for (auto v : G[u]) {
            if (d[u] && d[v] < d[u] + eng[v]) {      //d[u]未死掉，且在正數cycle中
                if (us.count(v))  flag = true;
                d[v] = d[u] + eng[v];                                    
            }
        }
    }
    if(!flag)    flag = d[n];    
    cout << (flag ? "winnable" : "hopeless") << endl;
}

int main()
{
    int n;      //node
    while (cin >> n && n != -1) {

        n++;
        G.assign(n, vector<int>());
        reG.assign(n, vector<int>());
        eng.assign(n, 0);
        d.assign(n, 0);         //0 代表 node 未被走過或是在走過之後 energe 歸零
        us.clear();        

        int val, j, nxt;
        for (int i = 1; i < n; i++) {
            cin >> val >> j;
            eng[i] = val;
            for (int k = 0; k < j; k++) {
                cin >> nxt;
                G[i].emplace_back(nxt);
                reG[nxt].emplace_back(i);
            }
        }
        n--;

        dfs(n);
        bellman(n);
    }
}
