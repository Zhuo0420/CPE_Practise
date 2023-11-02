#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--) {
        int B, SG, SB;
        multiset <int> green;
        multiset <int> blue;
        vector<int> result;
        cin >> B >> SG >> SB;
        for (int i = 0; i < SG; i++) {
            int tmp;
            cin >> tmp;
            green.emplace(tmp);
        }
        for (int i = 0; i < SB; i++) {
            int tmp;
            cin >> tmp;
            blue.emplace(tmp);
        }      
        while (!(green.empty()) && !(blue.empty())) {
            for (int i = 0; i < B; i++) {
                if (green.empty() || blue.empty())  break;
                result.emplace_back(*green.rbegin() - *blue.rbegin());
                auto it = green.end();
                green.erase(--it);
                it = blue.end();
                blue.erase(--it);
            }
            for (auto i : result) {
                if (i > 0) green.emplace(i);
                else if (i < 0)    blue.emplace(abs(i));
            }
            result.clear();            
        }    
        multiset<int>::reverse_iterator it;
        if (!(green.empty()) && blue.empty()) {
            cout << "green wins" << endl;            
            for (it = green.rbegin(); it != green.rend();it++) {
                cout << *it << endl;
            }
        }
        else if (green.empty() && !(blue.empty())) {
            cout << "blue wins" << endl;           
            for (it = blue.rbegin(); it != blue.rend(); it++) {
                cout << *it << endl;
            }
        }
        else {
            cout << "green and blue died" << endl;
        }      
        if(n!=0)
            cout << endl;
    }
}
