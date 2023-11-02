#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	int n;
	map<string, int> course;			//存組合 <組合字串, 有幾個學生有種些組合>
	vector<string> class_num;			//class number
	string line;

	while (cin >> n && n != 0) {
		int max_num = 0;
		int total = 0;
		course.clear();

		while (n--) {
			line.clear();
			class_num.clear();
			for (int i = 0; i < 5; i++) {
				string tmp;
				cin >> tmp;
				class_num.push_back(tmp);
			}
			sort(class_num.begin(), class_num.end());
			for (int i = 0; i < 5; i++) {
				line += class_num[i];
			}
			course[line]++;
		}

		for (auto it = course.begin(); it != course.end(); ++it)		//找最多人選的組合，max_num為有此組合的學生數
			if (it->second > max_num) max_num = it->second;
		for (auto it = course.begin(); it != course.end(); ++it)
			if (it->second == max_num) total += max_num;

		cout << total << endl;
		
	}

	return 0;
}