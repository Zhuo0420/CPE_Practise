#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<vector<int>> ve;
int d[101], parent[101], low[101], numChildren[101];

bool cutPoint[101];
int dfsTime = 0;

void findCutPoint(int u) {
    d[u] = low[u] = ++dfsTime;
    for (int v : ve[u]) {
        if (d[v] == 0) {
            numChildren[u]++;
            parent[v] = u;
            findCutPoint(v);
            low[u] = min(low[u], low[v]);
            if (parent[u] != -1) {
                if (low[v] >= d[u])
                    cutPoint[u] = true;                                    
            }
        }
        else if (parent[u] != v) {
            low[u] = min(low[u], d[v]);
        }
    }
    if (parent[u] == -1 && numChildren[u] > 1) {
        cutPoint[u] = true;
        
    }
}

int main()
{
    int N;      //number of nodes (1 ~ N)
    while (cin >> N && N) {
        ve.resize(101);    
        dfsTime = 0;        
        for (int i = 0; i < 101; i++) {
            cutPoint[i] = false;
            numChildren[i] = 0;
            d[i] = 0;
            parent[i] = -1;
            low[i] = 0;
        }

        string str;
        stringstream ss;
        while (getline(cin, str) && str != "0") {
			ss.clear();
			ss << str;
			int u, v;
			ss >> u;
            while (ss >> v) {
				ve[u].push_back(v);
				ve[v].push_back(u);
			}
		}
        
        for (int u = 1; u < N + 1; u++) {
            if (d[u] == 0)
                findCutPoint(u);
        }
        int counter = 0;
        for (int i = 0; i < 101; i++) {
            if (cutPoint[i]) counter++;
        }
        cout << counter << endl;
        for (int i = 0; i < ve.size(); i++) {
            if (!ve[i].empty())  ve[i].clear();
        }
        if (!ve.empty()) ve.clear();
    }
}
