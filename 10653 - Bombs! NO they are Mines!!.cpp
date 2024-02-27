#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int nxt[4][2] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
vector<vector<int>> d;
int s1, s2, e1, e2;
int R, C;

int bfs() {
    queue<pair<int, int>> Q;        
    
    Q.emplace(make_pair(s1, s2));
    d[s1][s2] = 1;
    while (!Q.empty()) {
        int ux = Q.front().first;
        int uy = Q.front().second;
        Q.pop();
        for (int i = 0; i < 4; i++) {
            int vx = ux + nxt[i][0];
            int vy = uy + nxt[i][1];

            if (vx < R && vx >= 0 && vy < C && vy >= 0 && !d[vx][vy]) {
                d[vx][vy] = d[ux][uy] + 1;
                if (vx == e1 && vy == e2) return d[vx][vy] - 1;
                Q.emplace(make_pair(vx, vy));
            }
        }
    }
}

int main()
{    
    while (cin >> R >> C) {
        if (!R || !C)   continue;
        d.resize(R);
        for (int i = 0; i < R; i++) {
            d[i].resize(C, 0);
        }
        int N;
        cin >> N;
        int br, k, bc;
        while (N--) {
            cin >> br >> k;
            for (int i = 0; i < k; i++) {
                cin >> bc;
                d[br][bc] = 1;        //have bomb
            }
        }
        cin >> s1 >> s2 >> e1 >> e2;        
        cout << bfs() << endl;

        for (auto i : d) {
            if (!i.empty())  i.clear();
        }
        if (!d.empty())  d.clear();
    }        
    return 0;
}
