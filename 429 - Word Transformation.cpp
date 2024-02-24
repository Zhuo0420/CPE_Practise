#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <sstream>
using namespace std;

map <string, vector<string>> graph;


int bfs(string s1, string s2) {
    queue<string>Q;
    map<string, int> d;
    map<string, bool> vis;    

    Q.emplace(s1); 
    vis[s1] = true;
    d[s1] = 0;

    while (!Q.empty()) {
        string u = Q.front();
        Q.pop();
        if (u == s2) break;
        for (auto v : graph[u]) {            
            if (!vis[v]) {
                Q.emplace(v);
                d[v] = d[u] + 1;
                vis[v] = true;
            }           
        }
    }
    return d[s2];

}

int main()
{
            
    vector<string> V;
    string str, s1, s2;         //輸入字串，尋找字串，目標字串

    int N;
    cin >> N;
    cin.ignore();           //\n
    getline(cin, str);      //blank line

    while (N--) {
        graph.clear();
        V.clear();

        while (getline(cin, str) && str!="*") {
            for (auto i : V) {
                int dis = 0;
                for (int j = 0; j < min(str.size(), i.size()); j++) {
                    if (str[j] != i[j])    dis++;
                }
                if (dis <= 1) {
                    graph[str].emplace_back(i);
                    graph[i].emplace_back(str);
                }
            }
            V.emplace_back(str);
        }

        //search
        while (getline(cin, str) && str != "") {
            stringstream ss(str);
            ss >> s1 >> s2;     //from, target
            cout << s1 << " " << s2 << " " << bfs(s1, s2) << endl;
        }
        
        if (N)cout << endl;
        
    }    


}

