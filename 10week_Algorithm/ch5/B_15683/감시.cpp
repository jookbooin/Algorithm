#include <bits/stdc++.h>

using namespace std;
const int INF = 987654321;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

vector<vector<int>> adjv[5] = {
    {},
    {{0}, {1}, {2}, {3}},
    {{0, 2}, {1, 3}},
    {{0, 1}, {1, 2}, {2, 3}, {3, 0}},
    {{0, 1, 3}, {0, 1, 2}, {1, 2, 3}, {2, 3, 0}}};

int n, m, ret = INF;
int graph[12][12];
int visited[12][12];

vector<pair<int, int>> vp;  // 1 2 3 4
vector<pair<int, int>> vf;  // 5

// 한방향 방문
void visit(int r, int c, int dir) {
    int cr = r, cc = c;
    visited[cr][cc]++;  // CCTV 자신의 위치도 방문 처리
    while (1) {
        int nr = cr + dr[dir];
        int nc = cc + dc[dir];

        if (nr < 0 || nr >= n || nc < 0 || nc >= m) break;
        if (graph[nr][nc] == 6) break;

        // 지나감
        visited[nr][nc]++;

        cr = nr, cc = nc;
    }
}

// 한방향 복구
void restore(int r, int c, int dir) {
    int cr = r, cc = c;

    visited[cr][cc]--;  // CCTV 자신의 위치도 복구
    while (1) {
        int nr = cr + dr[dir];
        int nc = cc + dc[dir];
        if (nr < 0 || nr >= n || nc < 0 || nc >= m) break;
        if (graph[nr][nc] == 6) break;

        // 아까 표시한 점 원복
        visited[nr][nc]--;
        cr = nr, cc = nc;
    }
}

void visited_count() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] != 6 && visited[i][j] == 0) cnt++;
        }
    }
    ret = min(ret, cnt);
}

void point_move(int depth) {
    if (depth == vp.size()) {
        visited_count();
        return;
    }

    auto p = vp[depth];                        // r, c
    int cctv_type = graph[p.first][p.second];  // 1,2,3,4
    auto cctvs = adjv[cctv_type];              // {{0, 1}, {1, 2}, {2, 3}, {3, 0}}

    for (auto cctv : cctvs) {   // {0, 1}
        for (int dir : cctv) {  // cctv 보이는 방향
            visit(p.first, p.second, dir);
        }

        point_move(depth + 1);  // 다음 점 이동

        for (int dir : cctv) {  // 움직인 방향 원복
            restore(p.first, p.second, dir);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 5) {
                vf.push_back({i, j});
            } else if (1 <= graph[i][j] && graph[i][j] <= 4) {
                vp.push_back({i, j});
            }
        }
    }

    // 5는 미리 처리
    if (vf.size()) {
        for (auto p : vf) {
            for (int i = 0; i < 4; i++) {  // 4방향 방문처리
                visit(p.first, p.second, i);
            }
        }
    }

    point_move(0);
    cout << ret << '\n';

    return 0;
}
