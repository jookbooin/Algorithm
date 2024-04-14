/**
 * tree - graph의 subset
 * 1. 모든 노드 -> 다른 노드로 이동할 수 있다 == 연결되어 있다?
 * 2. 엣지 제거 시 연결이 끊겨서 특정 노드에 도달할 수 없다. -> graph
 * 3. 엣지 추가되면 (A, B 사이에서) 연결되어 한개의 사이클 생김
 *
 * T : 테스트 케이스 개수
 * N : 노드 개수 (1~N)
 * M : 엣지 개수 -> 10^6 edges.
 * A-B ( 엣지에 연결되어져 있는 두개의 노드 )
 * M 총합은 10^6
 */

#include <bits/stdc++.h>
using namespace std;

int t, n, m, a, b, cnt ;
vector<int> adj[1004];
int visited[1004];  // 특정 점 방문여부만 체크하기 위해서

void dfs(int cur){
    visited[cur] = 1;
    for(int next : adj[cur]){
        if(!visited[next]) dfs(next);
    }
    return ;
}

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {

        for(int i = 0; i < 1004; i++) adj[i].clear();
        fill(&visited[0], &visited[0]+ 1004,0); // 초기화 
        cnt = 0;

        cin >> n;
        cin >> m;

        for (int i = 0; i < m; i++) {
            cin >> a >> b;  // a b의 엣지는 중복이 되면 안된다.
                adj[a].push_back(b);
                adj[b].push_back(a);
        }

        for(int i = 1; i<=n; i++){
            if(visited[i]) continue;
            cnt ++;         // 연결되어 있다면 오직 1번만 지나게 되어있다.
            dfs(i);
        }

        if(m == n-1 && cnt == 1) cout << "tree" <<'\n';
        else cout << "graph" << '\n';
    }

    return 0;
}