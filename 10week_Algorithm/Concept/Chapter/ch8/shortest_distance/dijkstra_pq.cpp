#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int INF = 987654321;
const int N = 10;
const int E = 20;
int from, to, cost;

vector<pair<int,int>> graph[N]; // 그래프
vector<int> dist(N, INF); // 거리 저장할 리스트 

priority_queue<pair<int,int>> pq1; // 

void dijkstra1(int start){

    dist[start] = 0; // 시작 노드 거리 0
    pq1.push({0,start}); // cost , node

    while(!pq1.empty()){

        int cur_cost = -pq1.top().first; // 최소힙으로 만들때 `-` 
        int cur_node = pq1.top().second;
        pq1.pop();

        // 마지막으로 갱신된 정점으로만 계산 진행
        if(dist[cur_node] != cur_cost) continue;

        for(int i = 0; i< graph[cur_node].size(); i++){
            int next_node = graph[cur_node][i].first;
            int next_cost = cur_cost + graph[cur_node][i].second;

            // cost 업데이트
            if(next_cost < dist[next_node]){
                dist[next_node] = next_cost;
                pq1.push({-next_cost, next_node});
            }
        }
    }

}

int main() {

    for (int i = 0; i < E; i++){
        
        cin >> from >> to >> cost;

        graph[from].push_back({to, cost});
        graph[to].push_back({from, cost});
    }
    
    dijkstra1(0);
    cout << "shortest cost : " << dist[N-1] << endl;

}