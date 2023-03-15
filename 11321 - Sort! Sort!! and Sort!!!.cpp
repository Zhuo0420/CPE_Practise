#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

typedef struct list {
    int num;
    int mod;
    int evenOdd;
}List;

bool compare(List a, List b) {
    if (a.mod != b.mod) {
        return a.mod < b.mod;
    }
    else {
        if (a.evenOdd == 0 && b.evenOdd == 0) {
            return a.num < b.num;
        }
        else if (a.evenOdd == 1 && b.evenOdd == 1) {
            return a.num > b.num;
        }
        else if (a.evenOdd == 1 && b.evenOdd == 0) {
            return true;
        }
        else if (a.evenOdd == 0 && b.evenOdd == 1) {
            return false;
        }
    }
}

int main() {
    int n, m;
    int i = 0;
    while (cin >> n >> m) {
        if (n == 0 || m == 0) {
            cout << n << " " << m << endl;
            break;
        }
        cout << n << " " << m << endl;
        List tmp;
        vector<List> arr;
        int c = n;
        while (c--) {       //輸入陣列
            cin >> tmp.num;
            tmp.mod = tmp.num % m;
            tmp.evenOdd = abs(tmp.num % 2);
            arr.push_back(tmp);
        }
        sort(arr.begin(), arr.end(), compare);
        for (i = 0; i < n; i++) {
            cout << arr[i].num << endl;
        }
    }
    return 0;
}
