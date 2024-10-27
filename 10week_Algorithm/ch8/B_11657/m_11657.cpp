/***
 * vertex 500
 * edge 6000개 -1만  ---> -30억이 나올 수 있어서 dist는 ll로 해주어야 한다.
 * 
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 987654321;
ll n, m, from, to, cost;

struct edge{
    ll from, to, cost;
};

vector<edge> arr;

ll dist[504];

int main() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> from >> to >> cost;
        arr.push_back({from,to,cost});
    }

    fill(dist, dist+504, INF);
    dist[1] = 0;

    for (int j = 0; j < n; j++) {  // 라운드 수

        // 모든 간선 탐색
        for(edge cur : arr){
            from = cur.from;
            to = cur.to;
            cost = cur.cost;

            if(dist[from] == INF) continue;
            if(dist[to] > dist[from] + cost){
                dist[to] = dist[from] + cost;
            }
        }
    }

    // 음수 간선 check
    for(edge cur : arr){
        from = cur.from;
        to = cur.to;
        cost = cur.cost;

        if(dist[from] == INF) continue;
        if(dist[to] > dist[from] + cost){
            cout << -1 << endl;
            return 0;
        }

    }

    for (int i = 2; i <= n; i++) {
        if (dist[i] == INF) {
            cout << -1 << endl;
        } else {
            cout << dist[i] << endl;
        }
    }
    return 0;
}
