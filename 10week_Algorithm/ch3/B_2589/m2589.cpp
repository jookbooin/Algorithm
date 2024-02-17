/**
 * L ���� W �ٴ�
 * ��ĭ 1
 * ������ ���� ���� �ִ� �Ÿ��� �̵� ���� �� �ð��� �ɸ��� ���� �� ��
 *
 * N = 50
 */

/**
 * 1. ���� �и�
 * 2. ��ü ���鼭 L ���Ë� -> DFS
 * 3. visited = visited + 1 �ִ�
 */

#include <bits/stdc++.h>

using namespace std;

int N, M, mx = 0,r,c;
char graph[54][54];
int visited[54][54];

int dr[] = {-1, 0, 1, 0};
int dc[] = {0, 1, 0, -1};

void bfs(int row, int col) {
    
    visited[row][col] = 1;
    queue<pair<int,int>> q;
    q.push({row,col});

    while (q.size()) {
        tie(r,c) = q.front();
        q.pop();
        mx = max(mx, visited[r][c]);

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= N || nc < 0 || nc >= M || graph[nr][nc] == 'W') continue;
            if (!visited[nr][nc]) {
                q.push({nr,nc});
                visited[nr][nc] = visited[r][c] + 1;
            }
        }
    }
}

int main(void) {
    cin >> N >> M;

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            cin >> graph[row][col];
        }
    }

    for(int row = 0 ; row < N ; row ++){
        for(int col = 0; col < M ;col ++){
            fill(&visited[0][0], &visited[0][0]+54*54, 0);
            if(graph[row][col] == 'L'){
                bfs(row,col);
            }

        }
    }

    cout << mx-1 << endl;

    return 0;
}
