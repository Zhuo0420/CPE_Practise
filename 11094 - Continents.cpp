#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> mp;
vector<vector<bool>> visited;
int  H, W;
int  tmpMaxSize = 0;

void dfs(char c, int y, int x) {
    if (mp[y][x] == c && !visited[y][x])  visited[y][x] = true, tmpMaxSize++;
    else    return;
    if (y - 1 >= 0 && !visited[y - 1][x])  dfs(c, y - 1, x);
    //else if (!visited[H - 1][x])dfs(c, H - 1, x);           //y-1<0
    if (y + 1 < H && !visited[y + 1][x])  dfs(c, y + 1, x);
    //else if (!visited[0][x]) dfs(c, 0, x);
    if (x - 1 >= 0 && !visited[y][x - 1])  dfs(c, y, x - 1);
    else if (x - 1 < 0 && !visited[y][W - 1])dfs(c, y, W - 1);           //x-1<0
    if (x + 1 < W && !visited[y][x + 1])  dfs(c, y, x + 1);
    else if (x + 1 == W && !visited[y][0])dfs(c, y, 0);
}

int main()
{        
    while (cin >> H >> W && H+W) {
        mp.resize(H);
        visited.resize(H);
        //input
        for (int i = 0; i < H; i++) {
            visited[i].assign(W, false);
            for (int j = 0; j < W; j++) {
                char tmp;
                cin >> tmp;
                mp[i].emplace_back(tmp);
            }
        }
        int curY, curX;
        cin >> curY >> curX;
        char land_mark = mp[curY][curX];
        dfs(land_mark, curY, curX);
        int ans = 0;
        tmpMaxSize = 0;
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (mp[i][j] == land_mark && !visited[i][j]) {
                    tmpMaxSize = 0;
                    dfs(land_mark, i, j);
                    if (tmpMaxSize > ans)    ans = tmpMaxSize;                    
                }
            }
        }
        cout << ans << endl;
        for (int i = 0; i < mp.size(); i++)
            if (!mp[i].empty())  mp[i].clear();
        if (!mp.empty()) mp.clear();
        for (int i = 0; i < visited.size(); i++)
            if (!visited[i].empty())  visited[i].clear();
        if (!visited.empty()) visited.clear();
    }
    
    return 0;
}