/**
 * M��N(M,N��100)
 * ���簢�� K�� -> �������κ� = �и��� ����
 *
 * �� ���� �и��� ���� ���� +   �и��� �� ������ ���� �������� + ��ĭ ���̿� �ΰ� ���
 *
 *              (N,M)
 *         ->
 * (0,0)
 */

// M (row) , N (col) , K (����)
// ���� �Ʒ�( x , y ) ������ �� ( x , y)

#include <bits/stdc++.h>

using namespace std;

const int max_n = 104;
int N, M, K, ldx, ldy, rux, ruy;
int ldrow, ldcol, rurow, rucol;
int con, rec;      // ����
vector<int> area;  // ���簢�� ���̵�

int graph[max_n][max_n], visited[max_n][max_n];

const int dr[] = {-1, 0, 1, 0};
const int dc[] = {0, 1, 0, -1};

int dfs(int row, int col,int depth ){

    visited[row][col] = 1;
    int ret = 1;

    for (int i = 0; i < 4; i++) {
        int nr = row + dr[i];
        int nc = col + dc[i];

        if (nr < 0 || nr >= M || nc < 0 || nc >= N || graph[nr][nc]) continue;
        if (visited[nr][nc]) continue;
        
        ret += dfs(nr, nc,depth + 1);
    }

    cout << "( "<< row << ","<< col <<" ) -> " <<"depth : " << depth << " ret : "<< ret <<endl;

    return ret;

}


int main(void) {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin.tie(NULL);

    cin >> M >> N >> K;

    for (int i = 0; i < K; i++) {
        cin >> ldx >> ldy >> rux >> ruy;
        for(int row = ldy ; row < ruy; row ++){
            for(int col = ldx; col < rux; col ++){
                graph[row][col] = 1;
            }
        }
    }

    cout << endl;
    for (int row = 0; row < M; row++) {
        for (int col = 0; col < N; col++) {
            cout << graph[row][col] << " ";
        }
        cout << endl;
    }
    cout << endl;


    for (int row = 0; row < M; row++) {
        for (int col = 0; col < N; col++) {
            if (graph[row][col] == 0 && visited[row][col] == 0) {
                area.push_back(dfs(row,col,0));
            }
        }
    }

    sort(area.begin(), area.end());
    cout << area.size() << '\n';
    for (int a : area) {
        cout << a << " ";
    }

    return 0;
}
