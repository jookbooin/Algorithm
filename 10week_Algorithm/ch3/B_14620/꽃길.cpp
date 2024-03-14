/**
 * 씨앗 3개
 *
 * 꽃 4방향 -> 꽃잎 겹치면 죽는다.
 * 격자마다 화단 대여 가격이 다르다.
 *
 * 3개 모두 꽃피면서 -> 꽃모양 5개 대여 -> 최소비용
 *
 * N = 6~10
 * G = 200
 */

#include <bits/stdc++.h>

using namespace std;

int N, ret = 1e9, fsum;
int graph[204][204], visited[204][204];

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

bool check(int cr, int cc) {  // 방문 여부 check;

    if (visited[cr][cc]) return false;  // 방문 o

    for (int i = 0; i < 4; i++) {
        int nr = cr + dr[i];
        int nc = cc + dc[i];
        if (visited[nr][nc]) return false;
    }

    return true;
}

void add_sum(int cr, int cc) {
    fsum = 0;

    visited[cr][cc] = 1;
    fsum += graph[cr][cc];

    for (int i = 0; i < 4; i++) {
        int nr = cr + dr[i];
        int nc = cc + dc[i];
        visited[nr][nc] = 1;
        fsum += graph[nr][nc];
    }
}

void erase(int cr, int cc){
    visited[cr][cc] = 0;

    for (int i = 0; i < 4; i++) {
        int nr = cr + dr[i];
        int nc = cc + dc[i];
        visited[nr][nc] = 0;
    }

}

void go(int cnt, int dsum) {
    if (cnt == 3) {
        // 최솟값 계산
        ret = min(ret, dsum);
        return;
    }

    for (int r = 1; r < N - 1; r++) {
        for (int c = 1; c < N - 1; c++) {
            if (check(r, c)) {  // 방문 할 수 있다면

                // 방문 처리 + 값 계산
                add_sum(r, c);

                // 다음 단계
                go(cnt + 1, dsum + fsum);

                // 방문 해제
                erase(r, c);
            }
        }
    }
}

// 1 ~ N-2
int main(void) {
    cin >> N;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cin >> graph[r][c];
        }
    }

    go(0, 0);
    cout << ret << "\n";

    return 0;
}
