#include <bits/stdc++.h>
using namespace std;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int m, n, k, row, col, ret, nr, nc, t;

int a[104][104];
bool visited[104][104];
void dfs(int row, int col) {
    visited[row][col] = 1;
    for (int i = 0; i < 4; i++) {
        nr = row + dr[i];
        nc = col + dc[i];

        if (nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
        if (a[nr][nc] == 1 && !visited[nr][nc]) {
            dfs(nr, nc);
        }
    }
    return;
}

int main(void) {
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            cin >> a[row][col];
        }
    }

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            if (a[row][col] == 1 && !visited[row][col]) {
                ret++;
                dfs(row, col);
            }
        }
    }

    cout << ret << '\n'; // ¿µ¿ª

    return 0;
}
