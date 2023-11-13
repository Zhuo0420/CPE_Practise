#include <iostream>
#include <stack>
using namespace std;


int main()
{
    int n, input;    
    while (cin >> n && n) {
        while (cin >> input && input) {      //第一個車廂號碼
            stack<int>line;         //原始車廂
            stack<int>station;      //車站
            bool ans = true;
            for (int i = n; i > 0; --i) {           //先將車廂由大到小推入stack (進入station順序會由小到大)
                line.emplace(i);
            }
            for (int i = 0; i < n; ++i) {                
                if (i) cin >> input;
                if (!(station.empty()) && station.top() == input)   station.pop();      //在站台上的車廂可以直接連接到目標順序的情況，而不需要進行額外的調整
                else  {     //需調整
                    while (!(line.empty()) && line.top() != input) {    // 將堆疊 line 中的車廂移至車站，直到找到與輸入車廂相同的車廂
                        station.emplace(line.top());
                        line.pop();
                    }
                    if (line.empty())    ans = false;       //全移至車站後依然沒有找到要pop的車廂
                    else line.pop();                //找到目標車廂，將此車廂出站 (pop)
                }
            }
            cout << (ans ? "Yes" : "No") << endl;
        }
        cout << endl;
    }
}
