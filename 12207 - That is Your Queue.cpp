#include <iostream>
#include <deque>
using namespace std;

int main()
{
    int P, C;  
    int cases = 0;
    while (cin >> P >> C) {
        //cin.ignore();
        if (P == 0 && C == 0)    break;
        cases++;
        cout << "Case " << cases << ":" << endl;
        deque<int> line;
        for (int i = 0; i < min(C, P); i++) {
            line.push_back(i+1);
        }
        while (C--) {
            char com;
            cin >> com;
            if (com == 'N') {
                cout << line.front() << endl;                
                line.emplace_back(line.front());
                line.pop_front();
                
            }
            else{
                int x;
                cin >> x;                
                for (auto it = line.begin(); it != line.end(); it++) {
                    if (*it == x) {                        
                        line.erase(it);                        
                        break;
                    }
                }
                line.emplace_front(x);
            }
        }        
    }
    return 0;
}
