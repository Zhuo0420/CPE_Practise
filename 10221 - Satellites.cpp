#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#define PI acos(0.0)*2.0
using namespace std;
int main()
{
    double s, a;    //地表到衛星 角度
    double r = 6440.0;  //半徑
    string str;     //min or deg
    double s1;      //弦長
    double s2;      //弧長
    while (cin >> s >> a >> str) {
        if (str == "min") {
            a /= 60.0;          //degrees
        }
        if (a > 180.0) {
            a = 360 - a;
        }
        s1 = (cos(a / 2) * (r + s)) * 2;
        s2 = (2 * (r + s) * PI) * (a / 360);
        cout << fixed << setprecision(6) << s2 << " " << s1 << endl;
    }
}
