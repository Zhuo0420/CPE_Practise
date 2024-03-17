#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <sstream>
using namespace std;

map<string, int> cId, pId, rId;       //club id, party id, resident id                
map <int, string> cName, pName, rName;
vector<vector<int>> G;
vector<vector<int>> rc;
vector<int> parent;
int cnt = 0;
int s, t;
int mf;

void init() {
    mf = 0;
    cnt = 0;
    rc.clear();
    G.clear();
    rId.clear();
    pId.clear();
    cId.clear();
    rName.clear();
    pName.clear();
    cName.clear();
    G.assign(10000, vector<int>());
    rc.assign(10000, vector<int>(10000, -1));
}

void parse(string input) {
    stringstream ss(input);
    string r, p, c;         //resident, party, club
    ss >> r >> p;
    rId[r] = cnt;
    rName[cnt++] = r;
    if (pId.find(p) == pId.end()) {
        pId[p] = cnt;
		pName[cnt++] = p;
    }
    
    //resident to party
    G[rId[r]].emplace_back(pId[p]);
    G[pId[p]].emplace_back(rId[r]);
    rc[rId[r]][pId[p]] = 1;
    rc[pId[p]][rId[r]] = 0;

    while (ss >> c) {
        if (cId.find(c) == cId.end()) {
            cId[c] = cnt;
            cName[cnt++] = c;
        }

        //club to resident
        G[cId[c]].emplace_back(rId[r]);
        G[rId[r]].emplace_back(cId[c]);
        rc[cId[c]][rId[r]] = 1;
        rc[rId[r]][cId[c]] = 0;
    }
}

void bfs() {
    queue<int> Q;
    parent.assign(cnt + 1, -1);
    parent[s] = s;
    Q.push(s);
    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        if(u == t) return;

        for (auto v: G[u]) {
            if (rc[u][v] > 0 && parent[v] == -1) {
                parent[v] = u;
                Q.push(v);
            }
        }
    }
}

void edmondsKarp() {
    while (1) {
        bfs();
        if(parent[t] == -1) break;

        int mrs = INT32_MAX;        //min residual capacity
        for (int v = t; v != s; v = parent[v]) {
            mrs = min(mrs, rc[parent[v]][v]);
        }
        mf += mrs;
        for (int v = t; v != s; v = parent[v]) {
            rc[parent[v]][v] -= mrs;
            rc[v][parent[v]] += mrs;
        }
    }
}

int main()
{
    int T;
    string input;       //name, parity, n*club
    cin >> T;
    cin.ignore();   //\n
    cin.ignore();   //blank line
    while (T--) {
        init();
        s = 0;      //super source
        cnt++;          //from 1 to n
        while (getline(cin, input) && input != "") {            
            parse(input);
        }
        t = cnt;      //super sink

        //source to club
        for (auto c : cId) {
			G[0].emplace_back(c.second);
			G[c.second].emplace_back(0);
			rc[0][c.second] = 1;
			rc[c.second][0] = 0;
		}

        //party to sink
        for (auto p : pId) {
            G[p.second].emplace_back(t);
            G[t].emplace_back(p.second);
            rc[p.second][t] = (cId.size() + 1) / 2 - 1;
            rc[t][p.second] = 0;
        }
        edmondsKarp();
        //bool flag = true;
        if (mf >= cId.size()) {
            for (auto r : rId) { 
                for (auto c : cId) {
                    if (rc[c.second][r.second] == 0) {
					    cout << rName[r.second] << " " << cName[c.second] << endl;
                        //flag = false;	
                        break;
				    }                
			    }
            }
        }        
        else  cout << "Impossible." << endl;
        if(T) cout << endl;
    }
}
