#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> ve;
bool* unvisit;

void dfs(int u) {    
    for (int i = 0; i < ve[u].size(); i++) {                
        if (unvisit[ve[u][i]]) {
            unvisit[ve[u][i]] = false;
            dfs(ve[u][i]);
        }
    }
}

int main()
{
    int n;                //節點數量
    while (cin >> n && n) {
        unvisit = new bool[n + 1];
        ve.resize(n + 1);
        int nodeNum;
        
        while (cin >> nodeNum && nodeNum) {     //第一個元素為0時跳出
            int connectedNode;            
            while (cin >> connectedNode && connectedNode) {
                ve[nodeNum].emplace_back(connectedNode);
            }
            
        }
        //第一個圖輸入完
        int visitNum;
        cin >> visitNum;
        int visitNode;
        for (int i = 0; i < visitNum; i++) {
            cin >> visitNode;
            for (auto i = 0; i <= n; i++) {
                unvisit[i] = true;
            }            
            dfs(visitNode);
            //計算未被visit的node數
            int count = 0;
            for (int i = 1; i <= n; i++) {
                if (unvisit[i])  count++;
            }
            cout << count;
            for (int i = 1; i <= n; i++) 
                if (unvisit[i]) cout << " " << i;
            
            cout << endl;
        }
        //init
        for (int i = 0; i < ve.size(); i++) {
            if(!ve[i].empty())
                ve[i].clear();
        }
        if(!ve.empty())
            ve.clear();       
        delete[]unvisit;    
    }
    return 0;    
}
