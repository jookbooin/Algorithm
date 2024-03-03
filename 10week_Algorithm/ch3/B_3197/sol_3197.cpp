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
                swan_tempQ.push({nr, nc});  // ���� �ܰ�

            else if (graph[nr][nc] == 'L')  // ���� �߽߰� ����
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
            if (graph[i][j] == 'L') {  // ���� ��ġ 1��
                swanX = i;
                swanY = j;.
            }

            if (graph[i][j] == '.' || graph[i][j] == 'L') { // ��� . Q�� �ִ´�  // ���� 2�� Q�� �ִ´�.
                visited[i][j] = 1;
                waterQ.push({i, j});
            }
            
        }
    }

    swanQ.push({swanX, swanY});         // ���� �����̴� Q
    visited_swan[swanX][swanY] = 1;

    while (true) {

        if (move_swan()) break;         // ���� 1������ �ѹ������θ� �̵��ϴ� �� ( �ܼ�ȭ )
        water_melting();                // ���ʿ��� melting �ϴ� �� 

        waterQ = water_tempQ;
        swanQ = swan_tempQ;
        Qclear(water_tempQ);
        Qclear(swan_tempQ);
        day++;
    }

    cout << day << '\n';

    return 0;
}