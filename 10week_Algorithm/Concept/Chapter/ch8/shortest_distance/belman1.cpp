#include <bits/stdc++.h>
using namespace std;
long long t, n, m, a, b, c, dist[1004], INF = 987654321;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    fill(dist, dist + 1004, INF);
    vector<pair<int, int>> adj[1004];
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    dist[1] = 0;
    queue<int> q;

    for (int i = 0; i < n; i++) { // n-1번 탐색 
        for (int here = 1; here <= n; here++) {
            for (auto there : adj[here]) {
                int d = there.second;
                int to = there.first;
                if (dist[here] != INF && dist[here] + d < dist[to]) {

                    // n번째 사이클에서도 완화가 일어나면 음수 사이클이 존재하는 것으로 판단.
                    if (i == n - 1) q.push(to);

                    dist[to] = dist[here] + d;
                    cout << here << " : " << to << "\n";
                }
            }
        }
    }
    if (q.size()) 
        cout << -1 << "\n";
    else
        for (int i = 1; i <= n; i++) cout << (dist[i] == INF ? -1 : dist[i]) << "\n";
}