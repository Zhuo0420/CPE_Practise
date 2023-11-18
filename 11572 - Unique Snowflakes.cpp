#include <iostream>
#include <unordered_set>
#include <vector>


using namespace std;

int main()
{
    int cases;
    cin >> cases;
    while (cases--) {
        int k;
        int ans = 0;
        unordered_set<int> s;
        vector<int>v;
        cin >> k;
        while (k--) {
            int tmp;
            cin >> tmp;
            if (s.count(tmp)) {
                if (ans <= s.size())    ans = s.size();
            }
            while (s.count(tmp)) {
                s.erase(*v.begin());
                v.erase(v.begin());
            }
            s.emplace(tmp);
            v.emplace_back(tmp);
        }
        if (ans <= s.size())    ans = s.size();
        cout << ans << endl;
    }
}
