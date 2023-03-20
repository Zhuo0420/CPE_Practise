#include <iostream>
using namespace std;

int main()
{
    int T;
    int i, j;
    cin >> T;
    while (T--) {
        int M, N, Q;
        cin >> M >> N >> Q;
        char** arr = new char* [M];
        for (i = 0; i < M; i++) {
            arr[i] = new char[N];
        }
        for (i = 0; i < M; i++) {
            for (j = 0; j < N; j++) {
                cin >> arr[i][j];
            }
        }
        cout << M << " " << N << " " << Q << endl;
        while (Q--) {
            int ct = 1;
            int x, y;
            cin >> x >> y;
            bool flag = 1;
            if (!N || !M || !Q) {
                cout << "0 0 0" << endl;
                continue;
            }
            while (flag == 1) {
                if (x + ct < M && x - ct >= 0 && y + ct < N && y - ct >= 0 && flag == 1) {
                    for (i = x - ct; i < x + ct && flag == 1; i++) {
                        for (j = y - ct; j < y + ct && flag == 1 ; j++) {
                            if (arr[i][j] != arr[x][y]) {
                                flag = 0;
                                break;
                            }
                        }
                    }
                    if (flag) {
                        ct++;
                    }
                }
                else {
                    flag = 0;
                }
            }
            cout <<( ct - 1 )*2 + 1 << endl;
        }
    }
}
