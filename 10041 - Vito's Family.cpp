/*
The world-known gangster Vito Deadstone is moving to New York. He has a very big family there, all
of them living in Lamafia Avenue. Since he will visit all his relatives very often, he is trying to find a
house close to them.
Vito wants to minimize the total distance to all of them and has blackmailed you to write a program
that solves his problem.
Input
The input consists of several test cases. The first line contains the number of test cases.
For each test case you will be given the integer number of relatives r (0 < r < 500) and the street
numbers (also integers) s1, s2, . . . , si
, . . . , sr where they live (0 < si < 30000 ). Note that several
relatives could live in the same street number.
Output
For each test case your program must write the minimal sum of distances from the optimal Vito’s house
to each one of his relatives. The distance between two street numbers si and sj is dij = |si − sj |.

Sample Input
2
2 2 4
3 2 4 6

Sample Output
2
4
*/
#include <iostream>
#include<cmath>
#include<algorithm>
using namespace std;
void sort(int *arr, int a) {
    for (int i = 0; i < a; i++) {
        for (int j = i + 1; j < a; j++) {
            int x;
            if (arr[i] > arr[j]) {
                x = arr[i];
                arr[i] = arr[j];
                arr[j] = x;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, a, i = 0, j = 0;
    cin >> n;
    while (n--) {
        int arr[30000] = {};
        cin >> a;
        int t = a;
        i = 0;
        while (t--) {
            cin >> arr[i];
            i++;
        }
        sort(arr, a);
        int middle = a / 2;
        int sum = 0;
        for (i = 0; i < a; i++) {
            sum += abs(arr[i] - arr[middle]);
        }
        cout << sum << endl;
    }
    return 0;
}
