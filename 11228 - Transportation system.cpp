#include <iostream>
#include <vector>
#include <tuple>
#include <math.h>
#include <algorithm>
using namespace std;


vector<tuple<int, int, double>> edge;
vector<int>set;
int n, cases = 0;

double dis(pair<int, int> n1, pair<int, int>n2) {
    return sqrt(pow(n1.first - n2.first, 2) + pow(n1.second - n2.second, 2));
}

bool cmp(tuple<int, int, double> edge1, tuple<int, int, double> edge2) {
    return get<2>(edge1) < get<2>(edge2);
}


void link(int x, int y) {
    if (x < y) {
        for (int i = 0; i < n; i++) {
            if (set[i] == y)
                set[i] = x;
        }
    }
    else {
        for (int i = 0; i < n; i++) {
            if (set[i] == x)
                set[i] = y;
        }
    }
}

void kruskcal( int r) {

    set.assign(n, 0);
    for (int i = 0; i < n; i++) {
        set[i] = i;
    }
    sort(edge.begin(), edge.end(), cmp);
    
    int side = 0;
    int state = 1;
    double raildis = 0;
    double roaddis = 0;

    for (int i = 0; i < edge.size();i++) {

        //if (side == n - 1)  break;          //side 數最多 n-1 條，當 side == n-1，表示每一點都有被 edge 連到

        int n1Set = set[get<0>(edge[i])];       //get<0>(edge[i]) node 所在的 set根節點
        int n2Set = set[get<1>(edge[i])];
        double dis = get<2>(edge[i]);

        if (n1Set != n2Set) {       //不同 set，link
            link(n1Set, n2Set);
            if (dis > r) raildis += dis, ++state;
            else    roaddis += dis;
            ++side;
        }
    }
    cout << "Case #" << cases << ": " << state << " " << (int)(roaddis + 0.5) << " " << (int)(raildis + 0.5) << endl;
}

int main()
{
    int T;
    cin >> T;    
    while (++cases && cases <= T) {
        vector<pair<int, int>>city;
        edge.clear();
        int r;
        cin >> n >> r;        
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            city.emplace_back(make_pair(x, y));
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                edge.emplace_back(i, j, dis(city[i], city[j]));     //i, j 為編號
            }
        }
        kruskcal(r);
    }
}
