/**
 * 배추들이 모여있는 곳에는 배추흰지렁이가 한 마리만 있으면 되므로
 * 1 : 배추가 심어져 있는 땅
 * M = 50 / N = 50 /  K = 2500
 *
 * X = M-1, Y = N-1
 *
 */
#include <bits/stdc++.h>
using namespace std;

const int max_n = 51;

int T, N, M, K, sr, sc;
int graph[max_n][max_n], visited[max_n][max_n];

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void dfs(int row, int col) {
    visited[row][col] = 1;

    for (int i = 0; i < 4; i++) {
        int nr = row + dr[i];
        int nc = col + dc[i];

        if (nr < 0 || nr >= N || nc < 0 || nc >= M) continue;
        if (graph[nr][nc] == 1 && !visited[nr][nc]) dfs(nr, nc);
    }
}

int main(void) {
    cin >> T;
    for (int i = 0; i < T; i++) {
        // T 단계마다 초기화
        fill(&graph[0][0], &graph[0][0] + 51 * 51, 0);
        fill(&visited[0][0], &visited[0][0] + 51 * 51, 0);
        int count = 0;

        cin >> M >> N >> K;  // 가로 , 세로 , 심어진 위치의 개수

        // 1. 배추 위치 초기화
        for (int i = 0; i < K; i++) {
            cin >> sc >> sr;
            graph[sr][sc] = 1;
        }

        // 2. 지렁이
        for (int row = 0; row < N; row++) {
            for (int col = 0; col < M; col++) {
                if (graph[row][col] == 1 && !visited[row][col]) {
                    count++;
                    dfs(row, col);
                }
            }
        }

        cout << count << '\n';
    }

    return 0;
}
