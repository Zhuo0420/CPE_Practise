#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>>V;
vector<int> d, parent;

void bfs(int s) {
    queue<int> Q;
    size_t num = V.size();
    d.resize(num);
    parent.resize(num);
    for (int i = 0; i < num; i++) {
        d[i] = INT16_MAX;
        parent[i] = -1;
    }    

    d[s] = 0;
    Q.emplace(s);

    while (!Q.empty()) {       
        int u = Q.front();
        Q.pop();

        for (auto v : V[u]) {
            if (d[v] == INT16_MAX) {
                d[v] = d[u] + 1;
                parent[v] = u;
                Q.emplace(v);
            }
        }        
    }
}

int main()
{    
    int E;  //number of employees
    cin >> E;
    V.resize(E);

    int n;
    for (int i = 0; i < E; i++) {
        cin >> n;
        int tmp;
        for (int j = 0; j < n; j++) {            
            cin >> tmp;
            V.at(i).emplace_back(tmp);
        }
    }

    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int s, M = 0, D = 0;        
        cin >> s;
        bfs(s);        
        vector<int> days(V.size() + 1, 0);
        for (int j = 0; j < V.size(); j++)
            if(d[j]!=INT16_MAX && d[j]!=0)
                days[d[j]]++;
        M = *max_element(days.begin(), days.end());
        for (int j = 0; j < days.size(); j++)
            if (days[j] == M) { D = j; break; }
        cout << M;
        if (M) cout << " " << D << endl;
        else cout << endl;

        if (!d.empty())  d.clear();
        if (!parent.empty())  parent.clear();
    }
    if (!V.empty())  V.clear();
}