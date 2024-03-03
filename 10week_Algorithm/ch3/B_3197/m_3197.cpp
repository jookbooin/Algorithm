/**
 * R C 1500
 * '.'�� �� ����, 'X'�� ���� ����, 'L'�� ����
 *
 * ���� 2
 * ���� ������ ������ ����
 * �����¿� ������
 *
 * 2���� ��� ��� ->
 */

#include <bits/stdc++.h>

using namespace std;

int R, C, fsr, fsc, ssr, ssc, cnt = 0, cr, cc,vi;
const int max_len = 1504;
char graph[max_len][max_len];
int visited[max_len][max_len];
bool flag1, flag2;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int main(void) {
    cin >> R >> C;

    for (int r = 0; r < R; r++) {
        for (int c = 0; c < C; c++) {
            cin >> graph[r][c];

            if (graph[r][c] == 'L') {
                if (!fsr) {  // ù��° ����
                    fsr = r;
                    fsc = c;
                } else {     // �ι�° ����
                    ssr = r;
                    ssc = c;
                }
            }
        }
    }

    queue<pair<int, int>> q1;  // ù��° ����
    queue<pair<int, int>> q2;  // �ι�° ����

    q1.push({fsr, fsc});
    visited[fsr][fsc] = 2;

    q2.push({ssr, ssc});
    visited[ssr][ssc] = 3;

    // while 1�� �� �ʿ���  cnt ������
    while (!flag1) {
        queue<pair<int, int>> nq1;  // ���� �ܰ迡�� ������ X �����
        queue<pair<int, int>> nq2;  // ���� �ܰ迡�� ������ X �����
        cnt++;

        while (q1.size() && !flag1 && !flag2) {
            cr = q1.front().first;
            cc = q1.front().second;
            q1.pop();

            for (int i = 0; i < 4; i++) {
                int nr = cr + dr[i];
                int nc = cc + dc[i];

                if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;

                if(visited[nr][nc] == 3){ // �ι�° ������ ������ ���� �������� -> ���� �� �ִ� ��� �ո�
                    flag1 = true;
                    break;
                }

                if(visited[nr][nc]) continue;

                visited[nr][nc] = 2;

                if(graph[nr][nc] == '.') {
                    q1.push({nr,nc});
                }else if (graph[nr][nc] == 'X'){
                    graph[nr][nc] = '.';
                    nq1.push({nr,nc});
                }
            }

            if(flag1) break;
        }

        while(q2.size() && !flag1 && !flag2){
            cr = q2.front().first;
            cc = q2.front().second;
            q2.pop();

            for (int i = 0; i < 4; i++) {
                int nr = cr + dr[i];
                int nc = cc + dc[i];

                if (nr < 0 || nr >= R || nc < 0 || nc >= C ) continue;
                
                if(visited[nr][nc] == 2){
                    flag2 = true;
                    break;
                }

                if(visited[nr][nc]) continue;

                visited[nr][nc] = 3;

                if(graph[nr][nc] == '.') {
                    q2.push({nr,nc});
                }else if (graph[nr][nc] == 'X'){
                    graph[nr][nc] = '.';
                    nq2.push({nr,nc});
                }
            }
            if(flag2) break;
        }

        // ���� �� �ִٸ�??
        if(flag1 || flag2) break;

        // ���� �ܰ�
        q1 = nq1;
        q2 = nq2;
        
    }

    if(flag1)
        cout << cnt - 1  << endl;
    else if(flag2)
        cout << cnt << endl;

    return 0;
}
