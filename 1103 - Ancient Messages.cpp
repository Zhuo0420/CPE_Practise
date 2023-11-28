#include <iostream>
#include <vector>   
#include <map>
#include <string>
#include <algorithm>
using namespace std;

vector<vector<int>> graph;
int H, W;
int counter = 0;

string trans(string str) {
	string bi = "";
	int tmp = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != '0') {
			string tmpstr = "";
			if (isdigit(str[i]))	tmp = str[i] - '0';							
			else if (isalpha(str[i]))	tmp = str[i] - 'a' + 10;			
			while (tmp)	tmpstr = to_string(tmp % 2) + tmpstr, tmp /= 2;
			while (tmpstr.length() < 4)	
				tmpstr = "0" + tmpstr;
			bi += tmpstr;
		}
		else {
			bi += "0000";
		}
	}
	return bi;
}

void clearWhite(int num, int y, int x) {
	graph[y][x] = -1;
	if(y - 1 >= 0 && graph[y-1][x] == num)	
		clearWhite(num, y - 1, x);
	if (y + 1 < H + 2 && graph[y+1][x] == num)	
		clearWhite(num, y + 1, x);
	if (x - 1 >= 0 && graph[y][x-1] == num)	clearWhite(num, y, x - 1);
	if (x + 1 < W * 4 + 2 && graph[y][x+1] == num)	clearWhite(num, y, x + 1);
}

void dfs(int num, int y, int x) {	
	if (y - 1 >= 0 && graph[y - 1][x] == num)	graph[y - 1][x] = -1, dfs(num, y - 1, x);
	else if (graph[y - 1][x] != -1)	{
		clearWhite(graph[y - 1][x], y - 1, x);	
		counter++;
	}
	if (y + 1 < H + 2 && graph[y + 1][x] == num)	graph[y + 1][x] = -1, dfs(num, y + 1, x);
	else if (graph[y + 1][x] != -1) {
		clearWhite(graph[y + 1][x], y + 1, x);
		counter++;
	}
	if (x - 1 >= 0 && graph[y][x - 1] == num)	graph[y][x - 1] = -1, dfs(num, y, x - 1);
	else if (graph[y][x - 1] != -1) {
		clearWhite(graph[y][x - 1], y, x - 1);
		counter++;
	}
	if (x + 1 < W * 4 + 2 && graph[y][x + 1] == num)	graph[y][x + 1] = -1, dfs(num, y, x + 1);
	else if (graph[y][x + 1] != -1) {
		clearWhite(graph[y][x + 1], y, x + 1);
		counter++;
	}
	return;
}


int main()
{
	map<int, char> mp;
	mp[1] = 'A';	mp[3] = 'J';	mp[5] = 'D';	mp[4] = 'S';	mp[0] = 'W';	mp[2] = 'K';	//圖形中空白格數
	int cases = 0;
	while (cin >> H >> W && H && W) {
		cin.ignore();		
		graph.resize(H + 2);		
		string tmp = "";
		vector<int>ans;
		for (int i = 0; i < W * 4 + 2; i++)	graph[0].emplace_back(0);
		for (int i = 1; i <= H; i++) {
			tmp = "";			
			getline(cin, tmp);
			string binStr = "0" + trans(tmp) + "0";
			for (int j = 0; j < binStr.length(); j++) {
				graph[i].emplace_back(binStr[j] - '0');
			}
		}
		cout << "Case " << ++cases << ": ";
		for (int i = 0; i < W * 4 + 2; i++)	graph[H + 1].emplace_back(0);
		clearWhite(0, 0, 0);		//清掉外圍空白處
		for (int i = 1; i < H+1; i++) {
			for (int j = 1; j < W * 4 + 1; j++) {
				if (graph[i][j] == 1)	
				{
					counter = 0;
					dfs(1, i, j);					
					ans.emplace_back(counter);
					counter = 0;
				}
			}
		}		
		vector<char>output;
		for (int i = 0; i < ans.size(); i++) {
			output.emplace_back(mp[ans[i]]);
		}
		sort(output.begin(), output.end());
		for (int i = 0; i < output.size(); i++) {
			cout << output[i];
		}
		cout << endl;
		for (int i = 0; i < graph.size(); i++) {
			if (!graph[i].empty())	graph[i].clear();
		}
		if (!graph.empty())	graph.clear();
	}
	return 0;
}
