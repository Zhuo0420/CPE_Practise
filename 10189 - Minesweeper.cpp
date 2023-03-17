#include <iostream>
using namespace std;


int main()
{
    int n, m;
    int i, j;
    int ca = 1;
    int p[8][2] = { {1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,-1},{1,-1},{-1,1} };
    while (cin >> n >> m) {
        if (n == 0 || m == 0) {
            break;
        }
        char** arr = new char* [n];
        for (i = 0; i < n; i++) {
            arr[i] = new char[m];
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                cin >> arr[i][j];
            }
        }
        int ct = 0;
        if (ca != 1) {
            cout << endl;
        }
        cout << "Field #" << ca++ << ":" << endl;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                for (int k = 0; k < 8; k++) {
                    if (i + p[k][0] >= 0 && i + p[k][0] < n && j + p[k][1] >= 0 && j + p[k][1] < m) {
                        if (arr[i + p[k][0]][j + p[k][1]] == '*') {
                            ct++;
                        }
                    }
                }
                if (arr[i][j] == '*') {
                    cout << "*";
                }
                else {
                    cout << ct;
                }
                ct = 0;
            }
            cout << endl;
        }
    }
    
}
