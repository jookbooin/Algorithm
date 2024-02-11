/**
 * 공기와 접촉하면 1시간 뒤에 녹는다.
 *
 * 1. 치즈 모두 없어지는데 걸리는 시간
 * 2. 모두 녹기전 한시간 전에 남아있는 칸 수
 *
 * row, col = 100
 */

/**
 * (반복)
 * 1. 표면과 내부 구별 -> 표면 개수 세기
 * 2. 표면 0으로 변환
 * 3. 치즈 개수 세기
 *
 *
 * 내부 : 표면이랑 맞닿아 있어야 하나..?
 *
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_LEN = 101;
const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

int R, C;
int graph[MAX_LEN][MAX_LEN];
int stch[MAX_LEN * MAX_LEN];  // 초당 남은개수 저장
int cnt = 0;
int arrcnt = 0;

list<int> result;
bool check(int row, int col) {
    for (int i = 0; i < 4; i++) {
        int nr = row + dr[i];
        int nc = col + dc[i];

        if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
        if (graph[nr][nc] == 2)  // 바깥 쪽 일떄
            return true;
    }
    return false;
}


// 바깥 부분( 0 -> 2 )로 색칠
void paintDfs(int row, int col) {
    if(graph[row][col] == 0){
        graph[row][col] = 2;
    }

    for (int i = 0; i < 4; i++) {
        int nr = row + dr[i];
        int nc = col + dc[i];

        if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;

        if (graph[nr][nc] == 0) {
            paintDfs(nr, nc);
        }
    }
}

int main(void) {
    cin >> R >> C;
    for (int row = 0; row < R; row++) {
        for (int col = 0; col < C; col++) {
            cin >> graph[row][col];

            if (row == 0 || row == R - 1 || col == 0 || col == C - 1) {  // 가장 자리 check
                graph[row][col] = 2;
            }

            if (graph[row][col] == 1) {  // 전체
                cnt++;
            }
        }
    }

    while (cnt > 0) {
        
        vector<pair<int,int>> out;
        // 1. 바깥 부분 표시
        for (int row = 0; row < R; row++) {
            for (int col = 0; col < C; col++) {
                if (graph[row][col] == 0 && check(row, col)) {
                    paintDfs(row, col);
                }
            }
        }
        
        // 2. 표면인 점 선택
        for (int row = 0; row < R; row++) {
            for (int col = 0; col < C; col++) {
                if(graph[row][col] == 1 && check(row,col)){
                    out.push_back({row,col});
                }
            }
        }

         // 3. 개수 세기
        cnt -= out.size();
        stch[arrcnt++] = cnt;

        for(pair<int,int> p : out){
            graph[p.first][p.second] = 2;
        }

    }

    cout << arrcnt << endl;
    cout << stch[arrcnt-2]<< endl;


    return 0;
}
