#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
typedef tuple<int, int, int> tp;

vector<vector<int>> map;
vector<vector<int>>d;
vector<vector<bool>>vis;

int nxt[4][2] = { {1, 0},  {-1, 0}, {0, -1}, {0, 1} };
int R, C;
priority_queue<tp, vector<tp>, greater<tp>> pq;

void Dijkstra() {
    d[0][0] = map[0][0];
    pq.emplace(make_tuple( map[0][0], 0, 0));

    while (!pq.empty()) {
        tp tmp = pq.top();
        int val = get<0>(tmp);
        int x = get<1>(tmp);
        int y = get<2>(tmp);
        pq.pop();
        vis[x][y] = true;

        for (int i = 0; i < 4; i++) {
            int vx = x + nxt[i][0];
            int vy = y + nxt[i][1];

            if (vx >= 0 && vx < R && vy >= 0 && vy < C && !vis[vx][vy]) {
                int tmpVal = val + map[vx][vy];
                if (tmpVal < d[vx][vy]) {
                    d[vx][vy] = tmpVal;
                    pq.emplace(make_tuple(tmpVal, vx, vy));
                }                
            }
        }
    }
    cout << d[R - 1][C - 1] << endl;
}

int main()
{
    int num;
    cin >> num;
    while (num--) {
        cin >> R >> C;
        map.resize(R);
        vis.resize(R);
        d.resize(R);
        for (int i = 0; i < R; i++) {
            map[i].resize(C);
            vis[i].resize(C);
            d[i].resize(C);
            for (int j = 0; j < C; j++) {
                vis[i][j] = false;
                d[i][j] = INT16_MAX;
            }
        }        
        
        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> map[i][j];
            }
        }
        Dijkstra();        
    }
}
