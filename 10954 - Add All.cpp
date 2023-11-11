#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main()
{
    int N;
    while (cin >> N && N) {
        priority_queue<int, vector<int>, greater<int>> line;
        vector<long long int> tmpSum;
        long long int Sum = 0;
        while (N--) {
            int tmp;
            cin >> tmp;
            line.emplace(tmp);
        }
        int tmp = 0, ans = 0;
        while (line.size() > 1) {
            tmp = line.top();
            line.pop();
            tmp += line.top();
            line.pop();
            line.emplace(tmp);
            ans += tmp;
        }
        cout << ans << endl;
    }
}
