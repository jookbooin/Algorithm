/***
 * 시작점 -> 다른 모든 정점
 * 
 * 정점 v : 2만
 * 간선 e : 30만
 * 시작 번호 k
 * 
 * u v 로 가는 가중치 w
 * 
 * i번 정점으로 가능 최단 거리의 경로값 출력
 * 시작점 0
 * 
 * 시작점 k
 * 가중치 배열 dist 
 * 
 */

#include <iostream>
#include <queue>

using namespace std;
const int N = 20000;
const int V = 300000;
const int INF = 987654321;

int v,e,k, src,dst,w;

// graph
vector<pair<int,int>> graph[N + 4];
vector<int> dist(N+4, INF); // 초기화

// 최소 힙
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;

void go(int start){
    // 초기값 
    dist[start] = 0;
    pq.push({0,start});

    while(!pq.empty()){
        int cur_dist = pq.top().first;
        int cur_node = pq.top().second;
        pq.pop();

        if(dist[cur_node] != cur_dist) continue;

        for(int i = 0; i< graph[cur_node].size(); i++){
            int next_node = graph[cur_node][i].first;
            int next_dist = cur_dist + graph[cur_node][i].second;

            if(next_dist < dist[next_node]){
                pq.push({next_dist, next_node});
                dist[next_node] = next_dist;
            }
        }
    }

}

int main(){
    cin >> v >> e >> k;

    for(int i =0; i<e; i++){
        cin >> src >> dst >> w;
        
        // 간선은 2개 존재해야??
        graph[src].push_back({dst,w});
        // graph[dst].push_back({src,w});
    }

    // 최단 거리 계산
    go(k);

    for(int i = 1; i <= v; i++ ){
        if(i == k) {
            cout << 0 << endl;
            continue;
        }else if(dist[i] == INF){
            cout << "INF" << endl;
            continue;
        }

        cout << dist[i] << endl;
    }

    return 0;
}
