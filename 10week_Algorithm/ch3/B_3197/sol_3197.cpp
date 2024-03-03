#include <bits/stdc++.h>

using namespace std;

const int max_len = 1504;

int R, C, swanX, swanY;
int cr, cc, day;
string input;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

queue<pair<int, int>> waterQ, water_tempQ, swanQ, swan_tempQ;
char graph[max_len][max_len];
int visited[max_len][max_len], visited_swan[max_len][max_len];

void Qclear (queue<pair<int,int>> &q){
    queue<pair<int,int>> empty;
    swap(q,empty);
}



void water_melting() {

    while (waterQ.size()) {
        tie(cr, cc) = waterQ.front();
        waterQ.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr < 0 || nr >= R || nc < 0 || nc >= C || visited[nr][nc]) continue;

            if (graph[nr][nc] == 'X') {
                visited[nr][nc] = 1;
                water_tempQ.push({nr,nc});
                graph[nr][nc] = '.';
            }

        }
    }

}

bool move_swan() {
    while (swanQ.size()) {
        tie(cr, cc) = swanQ.front();
        swanQ.pop();

        for (int i = 0; i < 4; i++) {
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr < 0 || nr >= R || nc < 0 || nc >= C || visited_swan[nr][nc]) continue;

            visited_swan[nr][nc] = 1;

            if (graph[nr][nc] == '.')
                swanQ.push({nr, nc});

            else if (graph[nr][nc] == 'X')
                swan_tempQ.push({nr, nc});  // 다음 단계

            else if (graph[nr][nc] == 'L')  // 백조 발견시 종료
                return true;  
        }
    }

    return false;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> R >> C;

    for (int i = 0; i < R; i++) {
        cin >> input;
        for (int j = 0; j < C; j++) {
            graph[i][j] = input[j];
            if (graph[i][j] == 'L') {  // 백조 위치 1개
                swanX = i;
                swanY = j;.
            }

            if (graph[i][j] == '.' || graph[i][j] == 'L') { // 모든 . Q에 넣는다  // 백조 2개 Q에 넣는다.
                visited[i][j] = 1;
                waterQ.push({i, j});
            }
            
        }
    }

    swanQ.push({swanX, swanY});         // 백조 움직이는 Q
    visited_swan[swanX][swanY] = 1;

    while (true) {

        if (move_swan()) break;         // 백조 1마리가 한방향으로만 이동하는 것 ( 단순화 )
        water_melting();                // 양쪽에서 melting 하는 것 

        waterQ = water_tempQ;
        swanQ = swan_tempQ;
        Qclear(water_tempQ);
        Qclear(swan_tempQ);
        day++;
    }

    cout << day << '\n';

    return 0;
}