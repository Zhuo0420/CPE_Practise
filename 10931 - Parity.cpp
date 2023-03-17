#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int num;
    while (cin >> num) {
        int ori = num;
        if (num == 0) {
            break;
        }
        vector<int> v;
        while (ori != 0) {
            v.push_back(ori % 2);
            ori /= 2;
        }
        cout << "The parity of ";
        for (int i = v.size() - 1; i >= 0; i--) {
            cout << v[i];
        }
        cout << " is ";
        int ct = 0;
        for (int i = 0; i < v.size(); i++) {
            ct += (v[i] == 1) ? 1 : 0;
        }
        cout << ct << " (mod 2)." << endl;
    }
    return 0;
}
