#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str[10001];
    int n = 0, i, j;
    bool f = 0;
    while (getline(cin, str[n]), str[n]!="") {
        n++;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < str[i].length(); j++) {
            if (str[i][j] == '"' && f != 1) {
                f = 1;
                cout << "``";
            }
            else if (str[i][j] == '"' && f == 1) {
                f = 0;
                cout << "''";
            }
            else {
                cout << str[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}
