/**
 * 3가지 경우의 수 : (0,1), (1,0), (1,1)
 *
 * N = 16
 * 이동 시킬 수 없으면 : 0, 방법의 수 100만
 */

#include <bits/stdc++.h>

using namespace std;

int n, ret = 0;
int arr[20][20];

int dr[3] = {0, 1, 1}; // 오른쪽, 아래, 대각선
int dc[3] = {1, 0, 1}; // 오른쪽, 아래, 대각선

void dfs(int cr, int cc, int direc) {

    if (cr == n - 1 && cc == n - 1) {
        ret += 1;
        return; 
    }

    for (int i = 0; i < 3; i++) {
        // 오 : 0, 아래 : 1, 대각선 : 2
        if ((direc == 0 && i == 1) || (direc == 1 && i == 0)) 
            continue;

        int nr = cr + dr[i];
        int nc = cc + dc[i];

        if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
        if (arr[nr][nc] == 1) continue;
        if (i == 2) {
            if (arr[cr][cc + 1] == 1 || arr[cr + 1][cc] == 1) continue; 
        }

        dfs(nr, nc, i);
    }
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    dfs(0, 1, 0); 

    cout << ret << '\n';

    return 0;
}

