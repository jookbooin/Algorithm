#include <bits/stdc++.h>

using namespace std;

vector<int> adj[1004];
int dir[1004];

int t, k, a, b, cnt = 0;
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
        a--;

        memset(dir, 0, sizeof(dir));
        dir[a] = b;

        // a 오른쪽
        for (int j = a; j < t - 1; j++) {
            if (adj[j][2] == adj[j + 1][6]) break;
            dir[j + 1] = -dir[j];
        }

        // a 왼쪽
        for (int j = a; j > 0; j--) {
            if (adj[j][6] == adj[j - 1][2]) break;
            dir[j - 1] = -dir[j];
        }

        for (int j = 0; j < t; j++) {
            if (dir[j] == 1) {  // 시계 방향
                rotate(adj[j].rbegin(), adj[j].rbegin() + 1, adj[j].rend());
            } else if (dir[j] == -1) {  // 반시계 방향
                rotate(adj[j].begin(), adj[j].begin() + 1, adj[j].end());
            }
        }
    }

    for (int i = 0; i < t; i++) {
        if (adj[i][0]) cnt++;
    }

    cout << cnt << '\n';
    return 0;
}
