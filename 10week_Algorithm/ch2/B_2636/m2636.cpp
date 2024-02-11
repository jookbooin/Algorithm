/**
 * ����� �����ϸ� 1�ð� �ڿ� ��´�.
 *
 * 1. ġ�� ��� �������µ� �ɸ��� �ð�
 * 2. ��� ����� �ѽð� ���� �����ִ� ĭ ��
 *
 * row, col = 100
 */

/**
 * (�ݺ�)
 * 1. ǥ��� ���� ���� -> ǥ�� ���� ����
 * 2. ǥ�� 0���� ��ȯ
 * 3. ġ�� ���� ����
 *
 *
 * ���� : ǥ���̶� �´�� �־�� �ϳ�..?
 *
 */

#include <bits/stdc++.h>

using namespace std;

const int MAX_LEN = 101;
const int dr[4] = {-1, 0, 1, 0};
const int dc[4] = {0, 1, 0, -1};

int R, C;
int graph[MAX_LEN][MAX_LEN];
int stch[MAX_LEN * MAX_LEN];  // �ʴ� �������� ����
int cnt = 0;
int arrcnt = 0;

list<int> result;
bool check(int row, int col) {
    for (int i = 0; i < 4; i++) {
        int nr = row + dr[i];
        int nc = col + dc[i];

        if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;
        if (graph[nr][nc] == 2)  // �ٱ� �� �ϋ�
            return true;
    }
    return false;
}


// �ٱ� �κ�( 0 -> 2 )�� ��ĥ
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

            if (row == 0 || row == R - 1 || col == 0 || col == C - 1) {  // ���� �ڸ� check
                graph[row][col] = 2;
            }

            if (graph[row][col] == 1) {  // ��ü
                cnt++;
            }
        }
    }

    while (cnt > 0) {
        
        vector<pair<int,int>> out;
        // 1. �ٱ� �κ� ǥ��
        for (int row = 0; row < R; row++) {
            for (int col = 0; col < C; col++) {
                if (graph[row][col] == 0 && check(row, col)) {
                    paintDfs(row, col);
                }
            }
        }
        
        // 2. ǥ���� �� ����
        for (int row = 0; row < R; row++) {
            for (int col = 0; col < C; col++) {
                if(graph[row][col] == 1 && check(row,col)){
                    out.push_back({row,col});
                }
            }
        }

         // 3. ���� ����
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
