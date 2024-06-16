/**
 * N = 100
 * (사과) K = 100
 * (뱀 방향전환 횟수) L = 100
 * X C
 * X 초 끝난뒤 왼쪽 (C == L)
 *            오른쪽 (C = R) 로 방향 회전
 *
 * 뱀 (0,0) ->
 * -머리 다음 칸
 * - 벽 OR 자기 자신 몸 부딪히면 게임 끝
 * - 사과 O : 꼬리 유지
 * - 사과 X : 꼬리 삭제 -> deque
 *
 */

#include <bits/stdc++.h>

using namespace std;
int n, k, l, x, ar, ac;
char c;

int graph[104][104];

int direc = 0, tt = 0;
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

deque<pair<int, int>> dq;
queue<pair<int, char>> q;

int main() {
    cin >> n >> k;

    // 초기 뱀 (0,0);
    dq.push_back({1, 1});
    graph[1][1] = 2;

    // 사과 위치
    for (int i = 1; i <= k; i++) {
        cin >> ar >> ac;
        graph[ar][ac] = 1;
    }

    cin >> l;  // 방향 변환 횟수
    // x초후 90도 c방향 -> ( L : -1, R : +1 )

    // 방향 전환
    for (int i = 0; i < l; i++) {
        cin >> x >> c;
        q.push({x, c});
    }

    // x초
    while (true) {
        tt++;

        int cr, cc;
        tie(cr, cc) = dq.front();
        int nr = cr + dr[direc];
        int nc = cc + dc[direc];

        if (nr < 1 || nr > n || nc < 1 || nc > n || graph[nr][nc] == 2) {
            break;
        }

        // 머리 추가
        dq.push_front({nr, nc});
        
        // (nr,nc) 사과 아닐때 꼬리제거
        if (graph[nr][nc] != 1) {
            int lr, lc;
            tie(lr, lc) = dq.back();
            dq.pop_back();  // 꼬리 부분 삭제
            graph[lr][lc] = 0;
        }

        graph[nr][nc] = 2;

        // x초가 끝난 뒤에 방향 전환
        if (q.size() && tt == q.front().first) {
            if (q.front().second == 'L') {  // 0 -> 3 -> 2 -> 1
                direc = (direc - 1 + 4) % 4;
            } else {  // 0 -> 1 -> 2 -> 3
                direc = (direc + 1) % 4;
            }
            q.pop();
        }

    }

    cout << tt << '\n';

    return 0;
}