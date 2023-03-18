#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    int ca = 1;
    cin >> n;
    cin.get();
    while (n--) {
        cout << "Pair #" << ca++ << ": ";
        string s1;
        string s2;
        int n1 = 0;
        int n2 = 0;
        
        getline(cin, s1);
        getline(cin, s2);
        for (int i = 0; i < s1.size(); i++) {
            n1 *= 2;
            n1 += s1[i] - '0';
        }
        for (int i = 0; i < s2.size(); i++) {
            n2 *= 2;
            n2 += s2[i] - '0';
        }
        int t;
        while (n2 != 0) {
            t = n2;
            n2 = n1 % n2;
            n1 = t;
        }
        if (n1 > 1) {
            cout << "All you need is love!" << endl;
        }
        else {
            cout << "Love is not all you need!" << endl;
        }
    }
}
