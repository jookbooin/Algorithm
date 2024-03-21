#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, mp, mf, ms, mv;
int b, c, d, e, ret = INF, sum;
map<int, vector<vector<int>>> ret_v;  // 최솟값 134 : { {1, 2} {2, 4, 5}, {3, 6} }

struct A {
    int p, f, s, v, cost;
};
A adj[16];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> mp >> mf >> ms >> mv;

    for (int i = 0; i < n; i++) {
        cin >> adj[i].p >> adj[i].f >> adj[i].s >> adj[i].v >> adj[i].cost;
    }

    for (int i = 0; i < (1 << n); i++) {
        vector<int> vec;

        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                vec.push_back(j + 1); 
                b += adj[j].p;
                c += adj[j].f;
                d += adj[j].s;
                e += adj[j].v;
                sum += adj[j].cost;
            }
        }

        if(b >= mp && c >= mf && d >= ms && e >= mv){
            if(ret >= sum){ // ret == sum 인 경우 여러개 
                ret = sum;
                ret_v[ret].push_back(vec);
            }
        }

    }

}