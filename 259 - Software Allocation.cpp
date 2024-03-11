#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;


#define N 50

int userCnt = 0;    //總 user 記數
int f[N][N];        //flow network
int c[N][N];        //capacity
int S = 36;     //source
int T = 37;     //sink

int maxFlow(int n, int s, int t) {    
    static int d[N], parent[N];
    static bool mk[N];
    //d 紀錄 s 到 node 整條路徑上的最小剩餘容量    
    int mf = 0;

    //init
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            f[i][j] = 0;            
        }
    }
    
    while (1) {     
        //init
        for (int j = 0; j < N; j++) {
            mk[j] = 0;
            d[j] = 0;            
        }
        queue<int> Q;

        Q.emplace(s);
        d[s] = INT32_MAX;
        mk[s] = true;

        //bfs
        while (!Q.empty() && !mk[t]) {     //Q不為空且還未走到t點
            int u = Q.front();      Q.pop();
            for (int v = 0; v < n; v++) {           //s 所能到的 node (計算機編號)
                if (!mk[v] && f[u][v] < c[u][v]) {          //可流過 是一條path中的edge
                    mk[v] = true;
                    Q.emplace(v);
                    parent[v] = u;

                    if (d[u] < c[u][v] - f[u][v])      d[v] = d[u];     //d[u] 由 s 到 u 路徑上的最小剩餘量如果小於此 edge 的剩餘容量，s -> v 的最小剩餘容量也為 d[u]  
                    else        d[v] = c[u][v] - f[u][v];           //此 edge 的剩餘容量比較小，s 到 v 的最小剩餘容量改為此 edge 的剩餘容量
                }
            }
        }
        if (!mk[t])  break;         //到達終點，maxflow算完
        mf += d[t];         //跑完一次 bfs後的 d[t] = 某一條 path 的最小剩餘容量

        //找完所有路徑後，逆向找單條路徑
        int v;
        for (int u = t; u != s;) {      //反著走
            v = u;
            u = parent[u];
            f[u][v] += d[t];            //edge u->v 中的 flow 增加了 d[t]
            f[v][u] = -f[u][v];         //反向邊為原流量的負值
        }
    }
    return mf;
}

void parse(string input) {
    int u = input[0] - 'A';         //任務編號 (0 ~ 25)
    userCnt += (input[1] - '0');      //用戶數
    c[S][u] += (input[1] - '0');      //將用戶數量添加到源點S到應用程序的邊上
    for (int i = 3; i <= input.size() - 2; i++) {          // -2 是去掉 ; 及 \n
        c[u][input[i] - '0' + 26] = 1;        //編號 u 的任務可在 input[i] 計算機 (26 ~ 35)所運行，容量為 1
    }
}

int main()
{
    int n = 38;
    int mf = 0;    
    
    string input;
    while (getline(cin, input)) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                c[i][j] = 0;
            }
        }
        for (int i = 26; i <= 35; i++) {
            c[i][T] = 1;
        }
        userCnt = 0;        
        parse(input);
        while (getline(cin, input) && input != "") {
            parse(input);
        }
        mf = maxFlow(n, S, T);
        int v;
        if (mf != userCnt) cout << "!";
        else {
            for (int u = 26; u < 36; u++) {         //遍歷計算機
                for (v = 0; v < 26 && !f[v][u]; v++);          //查找 u 號計算機所連結的app，f[v][u]位為零時停下 => 針對 u 號計算機，有app分配

                //for跑完後 v>25 => u 號計算機沒有找到分配的任務
                if (v > 25)    cout << "_"; 
                else        cout << char(v + 'A');
            }
        }
        cout << endl;
    }
    return 0;
}
