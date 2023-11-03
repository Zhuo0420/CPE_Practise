#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main()
{
    int cases;
    cin >> cases;
    while (cases--) {
        int n, maxLength = 0;
        cin >> n;        
        unordered_set<int> s;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            int tmp;
            cin >> tmp;
            if (s.count(tmp))   if (maxLength < s.size())  maxLength = s.size();                
            while (s.count(tmp)) s.erase(*(v.begin())), v.erase(v.begin());

            s.emplace(tmp);
            v.emplace_back(tmp);
        }
        cout << maxLength << endl;
    }
}
