#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

int main()
{
    long long int x;      
    string s;
    vector<int> v;
    while (cin >> x) {
        int ans = 0;
        v.clear();
        cin.get();
        getline(cin, s);
        stringstream ss(s);
        while (ss >> s) {
            v.push_back(stoi(s));
        }
        v.pop_back();
        reverse(v.begin(), v.end());
        ss.clear();
        ss.str("");
        long long t = 1;
        for (int i = 0; i < v.size(); i++) {
            ans += v[i] * (i+1) * t;
            t *= x;
        }
        cout << ans << endl;
    }
    return 0;
}
