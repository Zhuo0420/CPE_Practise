#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

vector<vector<int>> graph;			//1 => 右側有牆 2 => 下側有牆 3 => 右、下有牆
vector<vector<int>> path;
int h, w;
int s1, s2, g1, g2;

bool isWall(int y, int x, int way) {
	if (way == 1) {
		if (x > 0 && graph[y][x - 1] != 1 && graph[y][x - 1] != 3)	return false;
	}
	else if (way == 2) {
		if (y > 0 && graph[y - 1][x] != 2 && graph[y - 1][x] != 3)	return false;
	}
	else if (way == 3) {
		if (graph[y][x] != 1 && graph[y][x] != 3 && x + 1 < w)	return false;
	}
	else if (way == 4) {
		if (graph[y][x] != 2 && graph[y][x] != 3 && y + 1 < h)	return false;
	}
	return true;
}

void dfs(int y, int x) {	
	if (y != g1 || x != g2) {
		if (!isWall(y, x, 1) && !path[y][x - 1]) {			//向左走	
			path[y][x - 1] = path[y][x] + 1;
			dfs(y, x - 1);
		}
		else if (!isWall(y, x, 2) && !path[y - 1][x]) {		//上
			path[y - 1][x] = path[y][x] + 1;
			dfs(y - 1, x);
		}
		else if (!isWall(y, x, 3) && !path[y][x + 1]) {		//右
			path[y][x + 1] = path[y][x] + 1;
			dfs(y, x + 1);
		}
		else if (!isWall(y, x, 4) && !path[y + 1][x]) {		//下
			path[y + 1][x] = path[y][x] + 1;
			dfs(y + 1, x);
		}
		else {
			path[y][x] = 1000;			//回頭，設為1000，輸出時變成???
			if (!isWall(y, x, 1) && path[y][x-1] != 1000) {			//向左走					
				dfs(y, x - 1);
			}
			else if (!isWall(y, x, 2) && path[y - 1][x] != 1000) {		//上				
				dfs(y - 1, x);
			}
			else if (!isWall(y, x, 3) && path[y][x + 1] != 1000) {		//右				
				dfs(y, x + 1);
			}
			else if (!isWall(y, x, 4) && path[y + 1][x] != 1000) {		//下				
				dfs(y + 1, x);
			}
		}
	}
	else	return;	
}

void output() {
	for (int j = 0; j < h; j++) {
		if (j == 0) {
			for (int i = 0; i < w; i++) {
				cout << "+---";
				cout << (i == (w - 1) ? "+" : "");
			}
			cout << endl;
		}						
		for (int i = 0; i < w; i++) {
			if (i == 0)
				cout << "|";							
			if (path[j][i] == 1000)
				cout << "???";
			else if (path[j][i])
				cout << setw(3) << path[j][i];
			else
				cout << "   ";			
			if (i == w - 1 || graph[j][i] == 1 || graph[j][i] == 3)
				cout << "|";
			else
				cout << " ";
		}
		cout << endl;
		if (j != h - 1) {
			cout << "+";
			for (int i = 0; i < w; i++) {
				if (graph[j][i] == 2 || graph[j][i] == 3) 
					cout << "---+";				
				else 
					cout << "   +";				
			}
			cout << endl;
		}
		else if (j == h-1) {
			for (int i = 0; i < w; i++) {
				cout << "+---";
				cout << (i == (w - 1) ? "+" : "");
			}
			cout << endl << endl << endl;
		}		
	}
	
	
}

int main()
{	
	int cases = 0;
	while (cin >> h >> w >> s1 >> s2 >> g1 >> g2 && (h && w && s1 && s2 && g1 && g2)) {
		s1 -= 1; s2 -= 1; g1 -= 1; g2 -= 1;			//換成陣列的index
			
		graph.resize(h);
		path.resize(h);
		for (int i = 0; i < h; i++) {
			graph[i].resize(w);
			path[i].resize(w);
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> graph[i][j];
				path[i][j] = 0;
			}
		}
		path[s1][s2] = 1;
		dfs(s1, s2);
		cout << "Maze " << ++cases << endl << endl;
		output();

		for (int i = 0; i < h; i++) {
			if (!graph[i].empty())	graph[i].clear();
		}
		if (!graph.empty())	graph.clear();
		for (int i = 0; i < h; i++) {
			if (!path[i].empty())	path[i].clear();
		}
		if (!path.empty())	path.clear();
	}
}