#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> adj[20001];
int dist[20001];
const int INF = 987654321;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int main() {
    adj[1].push_back({1, 2});
    adj[1].push_back({2, 3});
    adj[1].push_back({3, 4});

    adj[2].push_back({100, 5});
    adj[3].push_back({10, 5});
    adj[4].push_back({1, 5});
    fill(dist, dist + 20001, INF);
    dist[1] = 0;
    pq.push({0, 1});
    while (pq.size()) {
        int here = pq.top().second;
        int here_dist = pq.top().first;
        pq.pop();

        // 마지막으로 갱신된 정점을 기준으로만 갱신 
        if (dist[here] != here_dist) continue;
        cout << "PQ check : " << here << '\n';
        for (pair<int, int> there : adj[here]) {
            int _dist = there.first;
            int _there = there.second;
            if (dist[_there] > dist[here] + _dist) {
                dist[_there] = dist[here] + _dist;
                cout << "PQ enter " << _there << " : " << dist[_there] << '\n';
                pq.push(make_pair(dist[_there], _there));
            }
        }
    }
    return 0;
}