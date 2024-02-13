// 1번.
// 정점은 0번 부터 9번까지 10개의 노드가 있다. 1 - 2 /  1 - 3 / 3 - 4 라는 경로가 있다. (1번과 2번, 1번과 3번, 3번과 4번은 연결되어있다.) 
// 이를  이를 인접행렬로 표현한다면? 

// 2번. 
// 0번부터 방문안한 노드를 찾고 해당 노드부터 방문, 연결된 노드를 이어서 방문해서 출력하는 재귀함수를 만들고 싶다면 어떻게 해야할까?
// 또한, 정점을 방문하고 다시 방문하지 않게 만드려면 어떻게 해야할까? 

#include <bits/stdc++.h>

using namespace std;

const int V = 10;
bool graph[V][V], visited[V];

void go(int from) {
    visited[from] = 1;
    cout << from << '\n';
    for(int to = 0; to< V; to++){
        if(visited[to]) continue;
        if(graph[from][to]){ // 1-2 , 1-3 , 1-4 연결된 점으로 들어간다.
            go(to);
        }
    }
}

int main(void) {
    graph[1][2] = 1;
    graph[2][1] = 1;

    graph[1][3] = 1;
    graph[3][1] = 1;

    graph[3][4] = 1;
    graph[4][3] = 1;

    for (int row = 0; row < V; row++) {
        for (int col = 0; col < V; col++) {
            if (graph[row][col] && visited[row] == 0) {
                go(row);
            }
        }
    }
    
    return 0;
}