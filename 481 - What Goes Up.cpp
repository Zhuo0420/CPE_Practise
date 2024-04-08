#include <iostream>
#include <vector>
using namespace std;

void LIS(vector<int> V) {
    int n = V.size();
    if (n == 0) {
        cout << 0 << endl;
        return;
    }
    vector<int> tail;           //存元素位置 index (同時也代表長度)
    tail.assign(n + 1, 0);
    vector<int> S;              //存現有的 LIS

    int length = 1;
    tail[0] = length;
    S.emplace_back(V[0]);
    for (int i = 1; i < n; i++) {        
        if (V[i] > S.back()) {      //V[i] 大於 LIS 最大值 (尾 length) case，直接將新元素加到尾端
            S.emplace_back(V[i]);
            tail[i] = ++length;
        }
        else {                      //其餘，比尾端小
            auto it = lower_bound(S.begin(), S.end(), V[i]);        //it 為 LIS 中剛好大於 V[i] 的元素位置，將其替換掉
            *it = V[i];
            tail[i] = (it - S.begin() + 1);          //i元素對應 LIS 中序列長度(位置)
        }
    }
    vector<int> ans;
    for (int i = V.size() - 1; i >= 0; i--) {
        if (tail[i] == length) {
            ans.emplace_back(V[i]);
            --length;
        }
    }

    cout << ans.size() << endl << "-" << endl;
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << endl;
    }
}

int main()
{
    int n;    
    vector<int> V;    
    while (cin>>n) {        
        V.emplace_back(n);
    }
    LIS(V);
    return 0;
}