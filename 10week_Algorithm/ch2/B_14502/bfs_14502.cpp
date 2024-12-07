
#include <bits/stdc++.h>
using namespace std;

int N, M, ret;
int graph[10][10], visited[10][10];
vector<pair<int, int>> virusList, wallList;
const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

void dfs(int row, int col) {
    
    for (int i = 0; i < 4; i++){
        int nr = row + dr[i];
        int nc = col + dc[i];

        // 방문했거나 1일때는 지나지 않는다.
        if (nr < 0 || nc < 0 || nr >= N || nc >= M || visited[nr][nc] || graph[nr][nc] == 1) continue;
        visited[nr][nc] = 1;
        dfs(nr, nc);
    }

    return;
}

int solve() {
    // 매 단계마다 for문을 초기화 해주어야 한다.
    fill(&visited[0][0], &visited[0][0] + 10 * 10, 0);

    queue<pair<int,int>> q;
    for (pair<int, int> p : virusList) {
        visited[p.first][p.second] = 1; // 2일때 visited 인정 
        q.push({p.first, p.second});
    }

    while(q.size()){
        auto b = q.front();
        q.pop();

        for(int i = 0; i< 4; i++){
            int nr = b.first + dr[i];
            int nc = b.second + dc[i];

            if (nr < 0 || nc < 0 || nr >= N || nc >= M || visited[nr][nc] || graph[nr][nc] == 1) continue;
            visited[nr][nc] = 1;
            q.push({nr,nc});
        }
    }

    // 2. bfs 

    int count = 0;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            if (graph[row][col] == 0 && !visited[row][col]) count++;
        }
    }

    return count;
}

int main(void) {
    cin >> N >> M;

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            cin >> graph[row][col];
            if (graph[row][col] == 2) virusList.push_back({row, col});
            if (graph[row][col] == 0) wallList.push_back({row, col});
        }
    }

    // 3점 선택
    for (int i = 0; i < wallList.size(); i++) {
        for (int j = i+1; j < wallList.size(); j++) {
            for (int k = j+1; k < wallList.size(); k++) {
                graph[wallList[i].first][wallList[i].second] = 1;
                graph[wallList[j].first][wallList[j].second] = 1;
                graph[wallList[k].first][wallList[k].second] = 1;
                ret = max(ret, solve());
                graph[wallList[i].first][wallList[i].second] = 0;
                graph[wallList[j].first][wallList[j].second] = 0;
                graph[wallList[k].first][wallList[k].second] = 0;
            }
        }
    }

    cout << ret << '\n';

    return 0;
}