#include <iostream>
#include <vector>
using namespace std;

vector< int > ve;
vector<bool> isVisited;
int visitedNode = 0;

void dfs(int x) {
    visitedNode++;
    isVisited[x] = true;
    if (!isVisited[ve[x]])  dfs(ve[x]);    
}

int main()
{    
    int cases;
    cin >> cases;
    for (int ca = 0; ca < cases; ca++) {        
        int num;        
        cin >> num;
        ve.assign(num, -1);
        isVisited.assign(num, false);
        int i1, i2;
        for (int i = 0; i < num; i++) {                        
            cin >> i1 >> i2;            
            ve[i1-1] = i2-1;
        }
        int tmpAns = 0, maxPath = 0;
        for (int i = 0; i < num; i++) {               
            if (isVisited[i])    continue;            //已被 visited 過，再跑一次 dfs 結果會 <= 上一次使用其他點當頭並經過此點的總人數
            isVisited.assign(num, false);
            dfs(i);                        
            if (maxPath < visitedNode)   tmpAns = i, maxPath = visitedNode;
            visitedNode = 0;
        }
        cout << "Case " << ca + 1 << ": " << ++tmpAns << endl;                
    }
    return 0;
}
