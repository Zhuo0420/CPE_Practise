#include <iostream>
#include <vector>
using namespace std;

int main()
{
    long long int a, b;
    while (cin>>a>>b) {
        if (a <= 1 || b <= 1) {
            cout << "Boring!" << endl;
        }
        else {
            vector<long long int> v;
            bool flag = true;
            v.push_back(a);
            while (a > 1) {
                if (a % b!=0) {
                    flag = false;
                    break;
                }
                v.push_back(a/b);
                a/=b;
            }
            if (flag) {
                for (int i = 0; i < v.size(); i++) {
                    cout << v[i];
                    if (i != v.size() - 1) {
                        cout << " ";
                    }
                }
                cout << endl;
            }
            else {
                cout << "Boring!" << endl;
            }
        }
    }
}
