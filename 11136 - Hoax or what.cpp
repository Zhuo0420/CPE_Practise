#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n;      //days    
    while (cin >> n) {
        if (n == 0)    break;
        long long int k;      //bills
        multiset<long long int> pri;
        long long int sum = 0;
        while (n--){
            cin >> k;                   
            for (int i = 0; i < k; i++) {
                long long int temp;
                cin >> temp;
                pri.insert(temp);
            }
            if (!(pri.empty())) {
                sum += *(--pri.end()) - *pri.begin();
                pri.erase(pri.begin());
                if (!(pri.empty()))     pri.erase(--(pri.end()));
            }
        }
        cout << sum << endl;        
    }
}
