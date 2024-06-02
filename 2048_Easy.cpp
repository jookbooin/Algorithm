/**
 * N = 20
 * 이동하려고 하는 쪽의 칸이 먼저 합쳐진다.
 *
 * 최대 5번 이동해서 만들 수 있는 가장 큰 블록 값
 * 총 경우의 수 -> 2^10 개
 *
 * 20*20 = 400 * 1000 =
 */

#include <bits/stdc++.h>

using namespace std;

int n, mr, mc, cr, cc, nr, nc, mx;
int graph[24][24];

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

void move(int rgraph[24][24], int r) {  // r 방향
    mr = dr[r], mc = dc[r];

    if (r == 0) {  // 우
        for (int i = 0; i < n; i++) {
            for (int j = n - 1; j >= 0; j--) {
                cr = i, cc = j;
                // 이동
                while (cc < n - 1) {  // 끝점, 다른 수,
                    nr = cr + mr;
                    nc = cc + mc;

                    if (rgraph[nr][nc] == rgraph[cr][cc]) {
                        rgraph[nr][nc] *= 2;
                        rgraph[cr][cc] = 0;
                        break;
                    } else if (rgraph[nr][nc] == 0) {
                        rgraph[nr][nc] = rgraph[cr][cc];
                        rgraph[cr][cc] = 0;
                        cc = nr;
                    } else {  // 다른 숫자
                        break;
                    }
                }
            }
        }

    } else if (r == 1) {  // 아래
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                cr = i, cc = j;
                while (cr < n - 1) {
                    nr = cr + mr;
                    nc = cc + mc;
                    if (rgraph[nr][nc] == rgraph[cr][cc]) {
                        rgraph[nr][nc] *= 2;
                        rgraph[cr][cc] = 0;
                        break;
                    } else if (rgraph[nr][nc] == 0) {
                        rgraph[nr][nc] = rgraph[cr][cc];
                        rgraph[cr][cc] = 0;
                        cr = nr;
                    } else {
                        break;
                    }
                }
            }
        }

    } else if (r == 2) {  // 좌
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cr = i, cc = j;
                while (cc > 0) {
                    nr = cr + mr;
                    nc = cc + mc;
                    if (rgraph[nr][nc] == rgraph[cr][cc]) {
                        rgraph[nr][nc] *= 2;
                        rgraph[cr][cc] = 0;
                        break;
                    } else if (rgraph[nr][nc] == 0) {
                        rgraph[nr][nc] = rgraph[cr][cc];
                        rgraph[cr][cc] = 0;
                        cc = nc;
                    } else {
                        break;
                    }
                }
            }
        }

    } else {  // 위
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cr = i, cc = j;
                while (cr > 0) {
                    nr = cr + mr;
                    nc = cc + mc;
                    if (rgraph[nr][nc] == rgraph[cr][cc]) {
                        rgraph[nr][nc] *= 2;
                        rgraph[cr][cc] = 0;
                        break;
                    } else if (rgraph[nr][nc] == 0) {
                        rgraph[nr][nc] = rgraph[cr][cc];
                        rgraph[cr][cc] = 0;
                        cr = nr;
                    } else {
                        break;
                    }
                }
            }
        }
    }
}

void cal(int rgraph[24][24]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            mx = max(mx, rgraph[i][j]);
        }
    }
}

void result(int rgraph[24][24], int depth) {
    if (depth == 5) {
        // 최댓값 계산
        cal(rgraph);
        return;
    }

    for (int i = 0; i < 4; i++) {
        // 1. 복사
        int temp[24][24];
        copy(&rgraph[0][0], &rgraph[0][0] + 24 * 24, &temp[0][0]);

        // 2. i 방향 움직임
        move(temp, i);

        // 3. 다음 단계
        result(temp, depth + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    result(graph, 0);

    cout << mx << '\n';

    return 0;
}