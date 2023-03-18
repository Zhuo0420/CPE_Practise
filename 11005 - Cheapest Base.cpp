#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int ca = 1;
    int i, j;
    while (n--) {
        if (ca != 1) {
            cout << endl;
        }
        cout << "Case " << ca++ << ":" << endl;
        int arr[4][9];
        for (i = 0; i < 4; i++) {
            for (j = 0; j < 9; j++) {
                cin >> arr[i][j];
            }
        }
        int qu;
        cin >> qu;
        while (qu--) {
            long long int num;
            cin >> num;
            long long int ori = num;
            vector<long long int> str;
            vector<long long int> sumCost (37);
            vector<long long int> ans;
            int min = 1000;
            for (i = 2; i <= 36; i++) {
                num = ori;
                long long int sum = 0;
                while (num > 0) {       //str為轉為此進位制的數字
                    str.push_back(num % i);
                    num /= i;
                }
                for (j = 0; j < str.size(); j++) {
                    sum += arr[str[j] / 9][str[j] % 9];
                }       //此進位制所需花費
                sumCost[i] = sum;
                str.clear();
            }
            for (i = 2; i <= 36; i++) {
                if (sumCost[i] <= min) {
                    min = sumCost[i];
                }
            }
            for (i = 2; i <= 36; i++) {
                if (sumCost[i] == min) {
                    ans.push_back(i);
                }
            }

            cout << "Cheapest base(s) for number " << ori << ":";
            for (i = 0; i < ans.size(); i++) {
                cout << " " << ans[i];
            }
            cout << endl;
            sumCost.clear();
            ans.clear();
        }

    }
}
