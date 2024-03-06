/**
 * R,C = 1 000 000
 *
 *
 *
 * �� 4���� Q
 *
 */

/**
 * Ż�ⱸ ��ġ�� �˾ƾ� ��
 */

#include <bits/stdc++.h>

using namespace std;

int R, C, pr, pc, r, c, ret;
const int INF = 987654321;

char graph[1004][1004];
int person_check[1004][1004];
int fire_check[1004][1004];

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R >> C;

    fill(&fire_check[0][0], &fire_check[0][0] + 1004 * 1004, INF);

    queue<pair<int, int>> fireq;
    queue<pair<int, int>> personq;

    for (int row = 0; row < R; row++) {
        for (int col = 0; col < C; col++) {
            cin >> graph[row][col];

            if (graph[row][col] == 'J') {  // ���� ������ �� �� �ִٰ�...?
                pr = row;
                pc = col;
            } else if (graph[row][col] == 'F'){
                fire_check[row][col] = 1;
                fireq.push({row, col});
            }
        }
    }

    // 1. ���� ������ ���� bfs
    while (fireq.size()) {
        tie(r, c) = fireq.front();
        fireq.pop();
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if (fire_check[nr][nc] != INF || graph[nr][nc] == '#') continue;
            fire_check[nr][nc] = fire_check[r][c] + 1;
            fireq.push({nr, nc});
        }
    }

    // 2. ��� �̵� ���
    //      ��� �̵� ��� ������ ent ���� �ȳ����� Impossible

    person_check[pr][pc] = 1;
    personq.push({pr, pc});

    while (personq.size()) {
        tie(r, c) = personq.front();
        personq.pop();
        // cout << "( " << r << ", "<< c <<" )" << " " << person_check[r][c] <<  sendl;
        if (r == R - 1 || c == C - 1 || r == 0 || c == 0) {
            ret = person_check[r][c];
            break;
        }

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
            if (person_check[nr][nc] || graph[nr][nc] == '#') continue;
            if (fire_check[nr][nc] <= person_check[r][c] + 1) continue;

            person_check[nr][nc] = person_check[r][c] + 1;
            personq.push({nr, nc});
        }
    }

    if (ret != 0) {
        cout << ret << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }

    return 0;
}