#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <map>
using namespace std;

vector<vector<int>> ve;
vector<int> d, low, parent;
stack<int> nodeStack;
vector<bool> inStack;
int dfsTime;
int scc_cnt;

void  tarjan(int u) {
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
    if (d[u] == low[u]) {       //SCC
        int w;
        scc_cnt++;        
        do {
            w = nodeStack.top();
            nodeStack.pop();            
            inStack[w] = false;
        } while (u != w);        
    }
}

int main()
{
    int P, T;
    while (cin >> P >> T && (P || T)) {
        cin.ignore();           // \n
        ve.assign(P, vector<int>());
        d.assign(P, 0);
        low.assign(P, 0);
        parent.assign(P, -1);
        inStack.assign(P, false);        
        dfsTime = 0;
        scc_cnt = 0;

        string tmpName;
        map<string, int>name;       //名字對應編號
        for (int i = 0; i < P; i++) {
            getline(cin, tmpName);
            name[tmpName] = i;
        }

        string n1, n2;
        for (int i = 0; i < T; i++) {
            getline(cin, n1);
            getline(cin, n2);
            ve[name[n1]].emplace_back(name[n2]);        //有向圖
        }

        for (int i = 0; i < P; i++) {
            if (!d[i])   {
                tarjan(i);                
            }
        }

        cout << scc_cnt << endl;
    }
}

