#include <iostream>
using namespace std;

int main()
{
    int N;
    int count = 0;
    while (cin>>N && N!=EOF) {
        count++;
        int i, j;
        bool f = true;
        int* a = new int[N];
        bool sum[20001] = {0};
        for (i = 0; i < N; i++) {
            cin >> a[i];
            if (a[i] < 1) f = false;
        }
        if (f) {
            for (i = 0; i < N; i++) {
                for (j = i; j < N; j++) {
                    if (sum[a[i] + a[j]] || a[j] < a[i]) {
                        f = false;
                        break;
                    }
                    sum[a[i] + a[j]] = true;
                }
            }
        }
        if (f) {
            cout << "Case #" << count << ": It is a B2-Sequence." << endl;
            cout << endl;
        }
        else {
            cout << "Case #" << count << ": It is not a B2-Sequence." << endl;
            cout << endl;
        }
        delete[]a;
    }
    return 0;
}
