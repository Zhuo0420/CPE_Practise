
#include <iostream>
using namespace std;

int arr[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

int count(int M, int D) {
    int sum = 0;
    int i, j;
    for (i = 0; i < M - 1; i++) {
        sum += arr[i];
    }
    sum += D;   //總天數
    return (sum % 7 + 5) % 7;
}

int main()
{
    
    int n;
    int i, j;
    int ans;    //1~7
    int sum = 0;
    cin >> n;
    while (n--) {
        int M, D;
        cin >> M >> D;
        if (M % 2 == 0 && M != 2 && D == M) {
            cout << "Monday" << endl;
        }
        else {
            ans = count(M, D);
            switch (ans)
            {
            case 1:
                cout << "Monday" << endl;
                break;
            case 2:
                cout << "Tuesday" << endl;
                break;
            case 3:
                cout << "Wednesday" << endl;
                break;
            case 4:
                cout << "Thursday" << endl;
                break;
            case 5:
                cout << "Friday" << endl;
                break;
            case 6:
                cout << "Saturday" << endl;
                break;
            case 0:
                cout << "Sunday" << endl;
                break;
            default:
                break;
            }
        }
    }
    return 0;
}
