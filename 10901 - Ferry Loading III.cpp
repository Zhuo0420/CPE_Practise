#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;

int main()
{
	int c;
	cin >> c;
	while (c--) {
		int n, t, m;        //一趟可載n台車，花t分鐘，有m台車		
		queue<p>line[2];		
		cin >> n >> t >> m;
		for (int i = 0; i < m; ++i) {
			int tmpTime;
			string tmpSide;
			cin >> tmpTime >> tmpSide;
			
			tmpSide == "left" ? line[0].push({ tmpTime, i }) : line[1].push({ tmpTime, i });
		}		
		int side = 0;
		int time = 0;       //已經過時間
		vector<int> ans(m);
		while (!line[0].empty() || !line[1].empty()) {
			int close = 0, cnt = 0;
			if (line[0].empty())	close = line[1].front().first;
			else if (line[1].empty())	close = line[0].front().first;
			else {
				close = min(line[1].front().first, line[0].front().first);				
			}
			time = max(time, close);
			while (!line[side].empty() && cnt < n && line[side].front().first <= time) {
				ans[line[side].front().second] = time + t;				
				line[side].pop();	
				++cnt;		
			}
			time += t;
			side ^= 1;
		}
		for (auto &i : ans)	cout << i << endl;
		if(c)	cout << endl;
	}
}
