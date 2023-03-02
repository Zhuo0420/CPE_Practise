#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int t = 1;
    while (n--) {
        int i, j;
        int N;
        char ch;
        cin >> ch >> ch >> N;
        bool f = true;
        long long int** a;
        a = new long long int*[N];
        for (i = 0; i < N; i++) {
            a[i] = new long long int [N];
        }
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                cin >> a[i][j];
                if (a[i][j] < 0) {
                    f = false;
                }
            }
        }
        cout << "Test #" << t << ": ";
        if (!f) {
            cout << "Non-symmetric." << endl;
            t++;
            continue;
        }
        for (i = 0; i < N; i++) {
            for (j = 0; j < N - i; j++) {
                if (a[i][j] != a[N - i - 1][N - j - 1]) {
                    f = false;
                    break;
                }
            }
        }
        if (!f) {
            cout << "Non-symmetric." << endl;
        }
        else {
            cout << "Symmetric." << endl;
        }
        for (i = 0; i < N; i++) {
            delete[]a[i];
        }
        delete[]a;
        t++;
    }
    return 0;
}
