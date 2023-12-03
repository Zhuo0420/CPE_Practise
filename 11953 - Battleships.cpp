#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> graph;
vector<vector<bool>> visited;
int n;
bool ship;

void dfs(int y, int x) {    
    visited[y][x] = true;    
    if(graph[y][x] == 'x')  ship = true;
    //if (y - 1 >= 0 && !visited[y - 1][x] && (graph[y - 1][x] == 'x' || graph[y - 1][x] == '@')) dfs(y - 1, x);
    if (y + 1 < n && !visited[y + 1][x] && (graph[y + 1][x] == 'x' || graph[y + 1][x] == '@')) dfs(y + 1, x);
    //if (x - 1 >= 0 && !visited[y][x - 1] && (graph[y][x - 1] == 'x' || graph[y][x - 1] == '@')) dfs(y, x - 1);
    if (x + 1 < n && !visited[y][x + 1] && (graph[y][x + 1] == 'x' || graph[y][x + 1] == '@')) dfs(y, x + 1);
    return;
}

int main()
{
    int cases = 0;
    cin >> cases;
    for (int ca = 1; ca <= cases; ca++) {        
        int ans = 0;
        cin >> n;
        graph.resize(n);
        visited.resize(n);
        for (int i = 0; i < n; i++) {
            visited[i].assign(n, false); 
            for (int j = 0; j < n; j++) {
                char input;
                cin >> input;
                graph[i].emplace_back(input);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((graph[i][j] == 'x' || graph[i][j] == '@') && !visited[i][j]) {
                    ship = 0;
                    dfs(i, j);
                    if(ship)
                        ans++;                    
                }
                visited[i][j] = true;
            }
        }
        cout << "Case " << ca << ": " << ans << endl;
        for (auto i : graph) if (!i.empty()) i.clear();
        if (!graph.empty())  graph.clear();
    }
}
