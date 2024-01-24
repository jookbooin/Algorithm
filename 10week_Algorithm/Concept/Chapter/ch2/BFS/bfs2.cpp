// �¿��̴� ����� �����ؼ� ��ٸ�Ŷ�� �����Ͼ�� ����ߴ�.
// ����� �ſ������ϱ� ������ ���� ������� ���. �� ������� ��ĭ ������ ������ ����� �������鼭 ����.
// ��, "��ĭ" ������ �� "����Ѱ�"�� �Ҹ�ȴٴ� ���̴�. �¿��̴� ���õ� ��ħ 9�ÿ� �Ͼ ��ٸ�Ŷ���� ����ϰ��� �Ѵ�.
// �¿��̴� �ִܰŸ��� ��ٸ�Ŷ���� ���Ѵٰ� �� �� ��ٸ�� �Ҹ��ؾ� ��ٸ�Ŷ�� �� �� �ִ��� �˾ƺ���.
// �� �� �¿��̴� �����θ� �� �� ������ �ٴٷδ� ������.
// ���� 1�� ������ 0�� �ٴٸ� ����Ų��. �¿��̴� �����¿�θ� �� �� �ִ�.

// ���� ���α��� N�� ���α��� M �� �־����� �̾ N * M�� ���� �־�����.
// �� ���� �ٿ� �¿����� ��ġ(y, x)�� ��ٸ�Ŷ�� ��ġ(y, x)�� �־�����.
// �� �� �¿����� ������ġ(y, x)���� "����Ѱ�"�� �̹� �Ҹ�� ���·� ����.

// ����
// 1 <= N <= 100
// 1 <= M <= 100

// �����Է�

// 5 5
// 0 0
// 4 4
// 1 0 1 0 1
// 1 1 1 0 1
// 0 0 1 1 1
// 0 0 1 1 1
// 0 0 1 1 1

#include <bits/stdc++.h>
using namespace std;
const int max_n = 104;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int n, m, row, col, srow, scol, erow, ecol;
int graph[max_n][max_n], visited[max_n][max_n];

int main(void) {
    cin >> n >> m;
    cin >> srow >> scol;
    cin >> erow >> ecol;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            cin >> graph[row][col];
        }
    }

    queue<pair<int, int>> q;
    visited[srow][scol] = 1;
    q.push({srow, scol});

    while (q.size()) {
        
        tie(row, col) = q.front(); // tie -> pair�̳� tuple�� ���� ���� ������ ���� ��
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nrow = row + dr[i];
            int ncol = col + dc[i];

            if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= m || graph[nrow][ncol] == 0) continue;
            if (visited[nrow][ncol]) continue;
            visited[nrow][ncol] = visited[row][col] + 1;
            q.push({nrow, ncol});
        }
    }

    cout << endl;
    cout << "end : " << visited[erow][ecol] << endl;

    for (int row = 0; row < n; row++) {
        for (int col = 0; col < m; col++) {
            cout << visited[row][col] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
