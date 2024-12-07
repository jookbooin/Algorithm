#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF = 1e18;
ll n, spos, epos, m, s, e, cost;
vector<pair<ll, ll>> adj[54];

ll val[54], dist[54];

int main() {
    cin >> n >> spos >> epos >> m;

    for (int i = 0; i < m; i++) {
        cin >> s >> e >> cost;
        adj[s].push_back({e, cost});
    }

    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }

    fill(&dist[0], &dist[0] + 54, -INF);
    dist[spos] = val[spos]; // 시작 도시의 돈 초기화

    queue<int> q;
    for (int i = 0; i < n; i++) {

        for (int here = 0; here < n; here++) {
            for (auto it : adj[here]) {
                int d = it.second;
                int next = it.first;

                // 지날 수 있는 점 + 최댓값
                if (dist[here] != -INF && dist[here] - d + val[next] > dist[next]) {
                    dist[next] = dist[here] - d + val[next];

                    if (i == n - 1) { // 사이클을 발견한 경우
                        q.push(next);
                    }

                }
            }
        }
    }

    // 사이클 탐지
    int ok = 0;
    vector<int> visited(n, 0);

    while (!q.empty()) {
        int here = q.front(); q.pop();
        if (here == epos) {
            ok = 1;  // 끝에 도달할 수 있다.
            break;
        }

        // 
        for (pair<int, int> there : adj[here]) {
            if (!visited[there.first]) {
                visited[there.first] = 1;
                q.push(there.first);
            }
        }
    }

    if (dist[epos] == -INF) { // 도달하지 못했을 때
        puts("gg");
    } else if (ok) {          // 완화 -> 순환이 발생했을 때
        puts("Gee");
    } else {                  // 정상
        cout << dist[epos] << '\n';
    }
    
    return 0;
}
