#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a,b;
    int min = 0;
    while (getline(cin,a) && getline(cin,b)) {
        char t1[26] = { 0 }, t2[26] = { 0 };
        min = 0;
        for (int i = 0; i < a.length(); i++) {
            t1[a[i] - 'a']++;
        }
        for (int i = 0; i < b.length(); i++) {
            t2[b[i] - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (t1[i] != 0 && t2[i] != 0) {
                if (t1[i] > t2[i]) {
                    min = t2[i];
                }
                else min = t1[i];
                for (int j = 0; j < min; j++) {
                    cout << char(i + 'a');
                }
            }
        }
        cout << endl;
    }
    return 0;
}
