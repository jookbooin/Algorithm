#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int n, m, tt, t, s, g, h, a, b, d;

vector<pair<int, int>> adj[2004]; // 최대 크기 조정
int dist1[2004], dist2[2004], dest3[2004];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void go(int start, int* dest) {
    fill(dest, dest + 2004, INF);
    pq.push({0, start});
    dest[start] = 0;

    while (!pq.empty()) {
        int here = pq.top().second;
        int here_cost = pq.top().first;
        pq.pop();

        if (dest[here] < here_cost) continue;

        for (pair<int, int> next : adj[here]) {
            int next_node = next.second;
            int next_cost = here_cost + next.first;

            if (next_cost < dest[next_node]) {
                dest[next_node] = next_cost;
                pq.push({next_cost, next_node});
            }
        }
    }
}

int main() {
    cin >> tt;
    while (tt--) {
        cin >> n >> m >> t;
        cin >> s >> g >> h;

        for (int i = 0; i <= n; i++) 
            adj[i].clear(); // 그래프 초기화

        int gh = 0;
        for (int j = 0; j < m; j++) {
            cin >> a >> b >> d;
            adj[a].push_back({d, b});
            adj[b].push_back({d, a});
            if ((a == g && b == h) || (a == h && b == g)) {
                gh = d;
            }
        }

        vector<int> dv(t);
        for (int k = 0; k < t; k++) {
            cin >> dv[k];
        }

        go(s, dist1);
        go(g, dist2);
        go(h, dest3);

        vector<int> result;
        for (int a : dv) {
            int sgha = dist1[g] + gh + dest3[a];
            int shga = dist1[h] + gh + dist2[a];

            if (dist1[a] == sgha || dist1[a] == shga) {
                result.push_back(a);
            }
        }

        sort(result.begin(), result.end());
        for (int a : result) {
            cout << a << " ";
        }
        cout << '\n';
    }
    return 0;
}
