#include <iostream>
#include <stack>
#include <string>

using namespace std;

typedef tuple<int, int, int> tp;

string in1, in2;
stack <char> line;

void dfs(int i1, int i2, string ret) {
    if (i2 == in2.length()) {
        cout << ret << endl;
        return;
    }
    if (i1 < in1.length()) {
        line.emplace(in1[i1]);
        dfs(i1 + 1, i2, ret + (ret.empty() ? "i" : " i"));
        line.pop();
    }
    if (!line.empty() && line.top() == in2[i2]) {
        char tmp = line.top();
        line.pop();
        dfs(i1, i2 + 1, ret + " o");
        line.emplace(tmp);
    }
}

int main()
{
    while (cin>>in1>>in2) {
        line = stack<char>();
        cout << "[" << endl;
        if (in1.length() == in2.length()) {
            dfs(0, 0, "");
        }
        cout << "]" << endl;

    }
}
