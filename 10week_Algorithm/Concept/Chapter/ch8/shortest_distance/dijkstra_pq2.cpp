#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;                // 무한대 값 설정
vector<pair<int, int>> adj[20004];  // 그래프의 인접 리스트 표현
vector<int> dist(20004, INF);       // 최단 거리 배열

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int here_cost = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        cout << "here_cost : " << here_cost << " u : " << u << endl;
        
        // 느긋한삭제
        if (dist[u] != here_cost) continue;

        for (auto &[v, weight] : adj[u]) {
            int new_cost = here_cost + weight;
            if (new_cost < dist[v]) {
                dist[v] = new_cost;
                pq.push({new_cost, v});
            }
        }
    }
}
int main() {
    int n, m, start;
    cin >> n >> m >> start;
    for (int i = 0; i < m; i++) {
        int u, v, w;

        // 출발, 도착, 걸리는 시간
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
    }
    dijkstra(start);

    for (int i = 1; i <= n; i++) {
        if (dist[i] == INF)
            cout << "INF\n";
        else
            cout << dist[i] << "\n";
    }
    return 0;
}

/*
start 교차로에서 갈 수 있는 교차로까지의 최단시간 구하는 

5 7 1
1 2 1
1 3 4
2 3 2
2 3 1
2 4 5
3 4 1
4 5 2
*/