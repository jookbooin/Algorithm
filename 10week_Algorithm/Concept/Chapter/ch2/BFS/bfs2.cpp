// 승원이는 당근을 좋아해서 당근마킷에 엔지니어로 취업했다.
// 당근을 매우좋아하기 때문에 차도 당근차를 샀다. 이 당근차는 한칸 움직일 때마다 당근을 내뿜으면서 간다.
// 즉, "한칸" 움직일 때 "당근한개"가 소모된다는 것이다. 승원이는 오늘도 아침 9시에 일어나 당근마킷으로 출근하고자 한다.
// 승원이는 최단거리로 당근마킷으로 향한다고 할 때 당근몇개를 소모해야 당근마킷에 갈 수 있는지 알아보자.
// 이 때 승원이는 육지로만 갈 수 있으며 바다로는 못간다.
// 맵의 1은 육지며 0은 바다를 가리킨다. 승원이는 상하좌우로만 갈 수 있다.

// 맵의 세로길이 N과 가로길이 M 이 주어지고 이어서 N * M의 맵이 주어진다.
// 그 다음 줄에 승원이의 위치(y, x)와 당근마킷의 위치(y, x)가 주어진다.
// 이 때 승원이의 시작위치(y, x)에서 "당근한개"가 이미 소모된 상태로 본다.

// 범위
// 1 <= N <= 100
// 1 <= M <= 100

// 예제입력

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
        
        tie(row, col) = q.front(); // tie -> pair이나 tuple로 부터 값을 끄집어 내는 것
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
