#include <bits/stdc++.h>

using namespace std;
const int INF = 987654321;

int n, m, x, s, e, t, ret = 0;

vector<pair<int,int>> adj[1004];

int go(int s, int e) {
    vector<int> dist(1004, INF);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    pq.push({0, s});
    dist[s] = 0;

    while (!pq.empty()) {
        int here_cost = pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if (dist[here] < here_cost) continue;

        for (pair<int,int> next : adj[here]) {
            int next_cost = here_cost + next.first;
            if (next_cost < dist[next.second]) {
                dist[next.second] = next_cost;
                pq.push({next_cost, next.second});
            }
        }
    }
    
    return dist[e];
}

int main() {
    cin >> n >> m >> x;

    // 단방향
    for (int i = 0; i < m; i++) {
        cin >> s >> e >> t;
        adj[s].push_back({t, e});
    }

    for (int i = 1; i <= n; i++) {
        if (i == x) continue;
        ret = max(ret, go(i, x) + go(x, i));
    }
    
    cout << ret << '\n';
    return 0;
}
