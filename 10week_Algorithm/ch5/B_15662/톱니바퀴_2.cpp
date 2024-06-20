#include <bits/stdc++.h>

using namespace std;
vector<int> adj[1004];
vector<pair<int, int>> rot;
int dir[1004];

int t, k, a, b, c, d, cnt = 0;
string str;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> str;
        for (int j = 0; j < 8; j++) {
            adj[i].push_back(str[j] - '0');
        }
    }

    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        rot.push_back({a - 1, b});  // 인덱스를 0부터 시작하도록 조정
    }

    for (auto p : rot) {
        tie(c, d) = p;

        // 방향 초기화
        memset(dir, 0, sizeof(dir));
        dir[c] = d;

        // c 오른쪽
        for (int i = c; i < t - 1; i++) {
            // 같은 극이라면 00 11
            if (adj[i][2] == adj[i + 1][6]) break;
            dir[i + 1] = -dir[i];
        }

        // c 왼쪽
        for (int i = c; i > 0; i--) {
            // 같은 극이라면 00 11
            if (adj[i][6] == adj[i - 1][2]) break;
            dir[i - 1] = -dir[i];
        }

        // 회전
        for (int i = 0; i < t; i++) {
            if (dir[i] == 1) {  // 시계 방향
                rotate(adj[i].rbegin(), adj[i].rbegin() + 1, adj[i].rend());
            } else if (dir[i] == -1) {  // 반시계 방향
                rotate(adj[i].begin(), adj[i].begin() + 1, adj[i].end());
            }
        }
    }

    for (int i = 0; i < t; i++) {
        if (adj[i][0]) cnt++;
    }

    cout << cnt << '\n';
    return 0;
}
