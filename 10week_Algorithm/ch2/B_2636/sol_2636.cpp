#include <bits/stdc++.h>

using namespace std;

const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};
int graph[104][104], visited[104][104];
vector<pair<int, int>> ch;
int R, C, cnt, cheese;

void bfs(int row, int col) {

    queue<pair<int, int>> q;
    q.push({row, col});
    visited[row][col] = 1;  // ( 0, 0 )

    while (q.size()) {

        tie(row, col) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = row + dr[i];
            int nc = col + dc[i];
            if (nr < 0 || nr >= R || nc < 0 || nc >= C || visited[nr][nc]) continue;

            visited[nr][nc] = 1;        // graph[nr][nc] = 0, 1 모두 방문 처리 해야함.

            if (graph[nr][nc] == 1) {
                ch.push_back({nr, nc});
            } else {
                q.push({nr, nc});
            }
        }
    }
}

void dfs(int row, int col) {
    // 이거좀 외우자 !!!!
    visited[row][col] = 1;
    if (graph[row][col] == 1) {
        ch.push_back({row, col});
        return;
    }

    for (int i = 0; i < 4; i++) {
        int nr = row + dr[i];
        int nc = col + dc[i];
        if (nr < 0 || nr >= R || nc < 0 || nc >= C || visited[nr][nc]) continue;
        dfs(nr, nc);
    }
}

int main(void) {
    cin >> R >> C;

    for (int row = 0; row < R; row++) {
        for (int col = 0; col < C; col++) {
            cin >> graph[row][col];
        }
    }

    // 치즈가 없어질 떄 까지 삭제
    while (true) {
        fill(&visited[0][0], &visited[0][0] + 104 * 104, 0);
        ch.clear();

        bfs(0, 0);

        if (ch.size() == 0) {
            break;
        }

        cnt++;
        cheese = ch.size();
        for (pair<int, int> p : ch) {
            graph[p.first][p.second] = 0;
        }
    }

    cout << cnt << '\n'
         << cheese << '\n';
    return 0;
}
