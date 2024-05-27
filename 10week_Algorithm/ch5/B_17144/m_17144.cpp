/**
 * 공기청정기 항상 1번 열 ( 2행 )
 *
 * 1. 미세먼지 확산
 * - 확산 양 : A/5
 * - 남은 양 : A[r][c] - (A/5) * ( 확산 방향 개수 )
 *
 * 2. 공기청정기 작동
 * - 위쪽 : 반시계
 *   아래쪽 : 시계
 *
 * - 위/아래 끝 부분만 이동함.
 *
 * (1) 확산 (O)
 * (2) 순환 (X)
 */

#include <bits/stdc++.h>

using namespace std;

int r, c, t, input, ret;
int upar, upac, downar, downac;

vector<pair<int, int>> air;  // 공기 청정기 위치

// 위로 rotate
int dr1[4] = {0, -1, 0, 1};
int dc1[4] = {1, 0, -1, 0};

// 아래로 rotate
int dr2[4] = {0, 1, 0, -1};
int dc2[4] = {1, 0, -1, 0};

int temp[54][54], graph[54][54];

vector<pair<int, int>> upv, downv;

void rotate(vector<pair<int,int>> & v) {

    // 끝 점 부터 이동 
    for(int i = v.size()-1 ; i >0 ; i--){
        graph[v[i].first][v[i].second] = graph[v[i-1].first][v[i-1].second];
    }
    
    graph[v[0].first][v[0].second] = 0;

}

vector<pair<int,int>> make_rotate_v(int airr,int airc, int dr[], int dc[]){
    vector<pair<int,int>> v;

    int cr = airr;
    int cc = airc;
    int cnt = 0;

    while(true){
        int nr = cr + dr[cnt];
        int nc = cc + dc[cnt];

        if(nr == airr && nc == airc) break;

        // (cr, cc)가 범위를 넘어가는 경계에 
        if(nr < 0 || nr >=r || nc < 0 || nc >= c){
            cnt ++;
            nr = cr + dr[cnt];
            nc = cc + dc[cnt];
        }

        if(nr == airr && nc == airc) break;

        // 다음 위치로 이동?
        cr = nr;
        cc = nc;

        v.push_back({nr,nc});
    }

    return v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c >> t;

    bool flag = true;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> graph[i][j];

            if (graph[i][j] == -1) {
                if (flag) {
                    upv = make_rotate_v(i,j,dr1,dc1);
                    flag = false;
                } else {
                    downv = make_rotate_v(i,j,dr2,dc2);
                }
            }
        }
    }

    // t번 반복
    for (int i = 0; i < t; i++) {
        fill(&temp[0][0], &temp[0][0] + 54 * 54, 0);
        queue<pair<int, int>> q;

        // 1. 미세먼지 확산

        // 위치 확인
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (graph[i][j] != -1 && graph[i][j]) q.push({i, j});
            }
        }

        // 소비
        while (q.size()) {
            int cr, cc;
            tie(cr, cc) = q.front();
            q.pop();
            int spread = graph[cr][cc] / 5;

            for (int i = 0; i < 4; i++) {
                int nr = cr + dr1[i], nc = cc + dc1[i];

                if (nr < 0 || nr >= r || nc < 0 || nc >= c) continue;  // 벗어날 때
                if (graph[nr][nc] == -1) continue;                     // 공기 청정기 위치

                temp[nr][nc] += spread;
                graph[cr][cc] -= spread;
            }
        }

        // graph 값 초기화
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                graph[i][j] += temp[i][j];
            }
        }

        // 2. 공기 청정기 작동
        rotate(upv);  // 위로
        rotate(downv);  // 아래
    }

    // 총 개수
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (graph[i][j] != -1) ret += graph[i][j];
        }
    }

    cout << ret << '\n';

    return 0;
}