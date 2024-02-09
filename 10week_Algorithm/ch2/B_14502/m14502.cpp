/**
 * 2 10���� �۰ų� ���� �ڿ���
 *
 * �� 3�� ������ ��.
 */

#include <bits/stdc++.h>

using namespace std;

int N, M, mb;
int graph[10][10];
int graph_copy[10][10];
int visited[10][10];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void copyArr(int tmp[10][10], int a[10][10]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            tmp[row][col] = a[row][col];
        }
    }
}

// ����
void dfs(int row, int col) {
    visited[row][col] = 1;
    for (int i = 0; i < 4; i++) {
        int nr = row + dr[i];
        int nc = col + dc[i];

        if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
        if (graph_copy[nr][nc] == 0 && !visited[nr][nc]) {
            graph_copy[nr][nc] = 2;
            dfs(nr, nc);
        }
    }
    return;
}

// ���̷��� check
void virus(int gcopy[10][10]) {
    fill(&visited[0][0], &visited[0][0] + 10 * 10, 0);  // �湮 �ʱ�ȭ

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            if (gcopy[row][col] == 2 && !visited[row][col]) {  // ���̷��� �߽߰�
                dfs(row, col);
            }
        }
    }
}

// 0 ���� ����
int count(int gcopy[][10]) {  // call by value
    int count = 0;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            if (gcopy[row][col] == 0) {
                count++;
            }
        }
    }

    return count;
}

// �� 3�� ����
void wall(int n) {
    if (n == 3) {
        copy(&graph[0][0], &graph[0][0] + 10 * 10, &graph_copy[0][0]);
        virus(graph_copy);
        mb = max(mb, count(graph_copy));
        return;
    }

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            if (graph[row][col] == 0) {
                graph[row][col] = 1;
                wall(n + 1);
                graph[row][col] = 0;
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

    wall(0);

    cout << mb << '\n';

    return 0;
}

// ����
// 3���� �����ؾ��� (0 -> 1)
// 2 ���� ����
// ���� ����
// �ݺ�