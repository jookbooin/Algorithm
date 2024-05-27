#include <bits/stdc++.h>
using namespace std;

int r, c, t, ret;
int graph[54][54], temp[54][54];

// 반시계 방향
int dr1[] = {0, -1, 0, 1};
int dc1[] = {1, 0, -1, 0};

// 시계 방향
int dr2[] = {0, 1, 0, -1};
int dc2[] = {1, 0, -1, 0};

vector<pair<int, int>> upv, downv;

void mise_go(int dr[], int dc[]){

    fill(&temp[0][0], &temp[0][0] + 54*54, 0);

    queue<pair<int,int>> q;

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if(graph[i][j] != -1 && graph[i][j]){
                q.push({i,j});
            }
        }
    }

    while(q.size()){
        int cr,cc;
        tie(cr,cc) = q.front(); q.pop();
        int spread = graph[cr][cc]/5;
        
        for(int i =0; i<4; i++){
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (nr < 0 || nr >= r || nc < 0 || nc >= c || graph[nr][nc] == -1) continue; 

            graph[cr][cc] -= spread;

            // 확산 결과 저장 
            temp[nr][nc] += spread;
        }
    }   

    // 4방향 확산 결과 더함 
    for(int i =0; i< r; i++){
        for(int j = 0; j < c; j++){
            graph[i][j] += temp[i][j];
        }
    }
    
    return;
}

vector<pair<int, int>> air(int airr, int airc, int dr[], int dc[]) {
    vector<pair<int, int>> v;

    // 공기 청정기 위치
    int cr = airr;
    int cc = airc;

    int cnt = 0;  // 방향

    while (true) {
        int nr = cr + dr[cnt];
        int nc = cc + dc[cnt];

        if (nr == airr && nc == airc) break; // 정화

        // 방향 전환
        if (nr < 0 || nr >= r || nc < 0 || nc >= c) {
            cnt++;

            // 모서리 만났을 때 다음 위치 이동
            nr = cr + dr[cnt];
            nc = cc + dc[cnt];

        }

        if (nr == airr && nc == airc) break; // 정화

        // 다음 위치로 이동
        cr = nr;
        cc = nc;

        v.push_back({nr, nc});
    }

    return v;
}

void rotate(vector<pair<int,int>> &v){
    
    // 끝점 부터 한칸 씩 이동시킨다 .
    for(int i = v.size()-1; i > 0; i--){
        graph[v[i].first][v[i].second] = graph[v[i-1].first][v[i-1].second];
    }

    graph[v[0].first][v[0].second] = 0;

    return;
}

int main() {
    cin >> r >> c >> t;

    bool flag = 1;  // 위아래 구별용

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> graph[i][j];

            if (graph[i][j] == -1) {

                if (flag) {  // 위 공기 청정기
                    upv = air(i, j, dr1, dc1);
                    flag = false;

                } else {  // 아래 공기 청정기
                    downv = air(i, j, dr2, dc2);
                }

            }
        }
    }

    for (int i = 0; i < t; i++) {
        mise_go(dr1, dc1);

        rotate(upv);
        rotate(downv);

    }

    for(int i =0; i<r; i++){
        for(int j = 0; j<c; j++){
            if(graph[i][j] != -1) ret += graph[i][j];
        }
    }

    cout << ret << '\n';

    return 0;
}