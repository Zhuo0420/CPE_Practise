
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string a[101];
    int i, j;
    int row = 0, size = 0;
    while (getline(cin, a[row]), a[row] != "") {
        /*if (a[row] == "") {
            break;
        }*/
        if (a[row].length() > size) {
            size = a[row].length();
        }
        row++;
    }
    for (i = 0; i < size; i++) {
        for (j = row - 1; j >= 0; j--) {
            if (i > a[j].length() - 1) {
                cout << " ";
            }
            else {
                cout << a[j][i];
            }
        }
        cout << endl;
    }
    return 0;
}

