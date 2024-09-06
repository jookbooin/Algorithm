#include <bits/stdc++.h>

using namespace std;

int r1, c1, r2, c2, m, n, k, cnt = 0;

int graph[104][104], visited[104][104];

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

vector<int> v;

void bfs(int r, int c) {
    int cr, cc;

    queue<pair<int, int>> q;
    q.push({r, c});
    visited[r][c] = 1;
    int sum = 0;

    while (q.size()) {
        tie(cr, cc) = q.front();
        q.pop();
        sum++;

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr < 0 || nr >= m || nc < 0 || nc >= n) continue;
            if (graph[nr][nc] || visited[nr][nc]) continue; // 사각형이거나, 방문하거나

            q.push({nr, nc});
            visited[nr][nc] = 1;
        }
    }

    v.push_back(sum);
}

int main() {
    cin >> m >> n >> k;

    // n : 가로, m : 세로

    for (int i = 0; i < k; i++) {
        cin >> c1 >> r1 >> c2 >> r2;
        // [r1][c1] ~ [r2 - 1][c2 - 1] 까지 graph 1
        for (int r = r1; r < r2; r++) {
            for (int c = c1; c < c2; c++) {
                graph[r][c] = 1;
            }
        }
    }


    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] == 0 && visited[i][j] == 0) {
                bfs(i, j);
            }
        }
    }

    sort(v.begin(), v.end());

    cout << v.size() << endl;
    for(int a : v){
        cout << a << " ";
    }

    return 0;
}