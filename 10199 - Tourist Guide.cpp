#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
using namespace std;

map<string, int> mp;
string numToStr[105];

vector<int> edge[105];
int dfsTime, dfn[105], low[105];
set<string> ans;

void dfs(int cur, int parent) {
    int child = 0;    
    dfn[cur] = low[cur] = ++dfsTime;
    for (int v : edge[cur]) {
        if (!dfn[v]) {
            ++child;
            dfs(v, cur);        //找child的low
            low[cur] = min(low[cur], low[v]);       //與自己的d比，找出cur的low
            if ((parent == -1 && child > 1) || parent != -1 && low[v] >= dfn[cur])
                ans.insert(numToStr[cur]);
        }
        else if (v != parent)
            low[cur] = min(low[cur], dfn[v]);
    }
}


int main()
{
    int N;              //node 數
    int cases = 0;
    while (cin >> N && N) {
        //init
        if (!mp.empty()) mp.clear();        
        if (!ans.empty())    ans.clear();
        for (int i = 1; i <= N; i++) {
            if (!edge[i].empty())    edge[i].clear();
            low[i] = dfn[i] = 0;
        }        
        dfsTime = 0;


        //input
        string n1, n2;
        for (int i = 1; i <= N; i++) {
            cin >> n1;
            mp[n1] = i;
            numToStr[i] = n1;
        }
        int R;                
        cin >> R;
        for (int i = 0; i < R; i++) {
            cin >> n1 >> n2;
            edge[mp[n1]].emplace_back(mp[n2]);
            edge[mp[n2]].emplace_back(mp[n1]);                        
        }

        //find cut point
        for (int i = 1; i <= N; i++)
            if (!dfn[i])    dfs(i, -1);
                
        if (cases)   cout << endl;
        cout << "City map #" << ++cases << ": " << ans.size() << " camera(s) found" << endl;
        for (auto it = ans.begin(); it != ans.end(); ++it)
            cout << *it << endl;
        
    }
    
}
