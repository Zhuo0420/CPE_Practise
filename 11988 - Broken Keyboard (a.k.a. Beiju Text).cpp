#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main()
{
    string str;
    bool n = 0;
    while (getline(cin, str)) {
        deque<string> dqu;
        string tmp = "";
        n = 1;      //true => i 在 [] 外, false => i 在 [] 內   
        for (int i = 0; i < str.length(); i++) {
            if (str[i] == '[' || str[i] == ']') {
                if (n) dqu.push_back(tmp);
                else    dqu.push_front(tmp);
                n = (str[i] == ']');
                tmp = "";
            }
            else    tmp += str[i];
        }
        if (n) dqu.push_back(tmp);
        else    dqu.push_front(tmp);
        for (auto i : dqu) {
            cout << i;
        }
        cout << endl;
    }
}
