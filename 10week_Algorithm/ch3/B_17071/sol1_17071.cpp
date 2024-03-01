#include <bits/stdc++.h>

using namespace std;

const int max_len = 500000;
int N, K;
int visited[2][max_len + 4];

int main() {
    cin >> N >> K;

    queue<pair<int, int>> q;
    visited[0][N] = 1;
    q.push({N, 0});

    while (q.size()) {
        int cur = q.front().first;
        int turn = q.front().second;
        int kpos = K + turn * (turn + 1) / 2;  // ¿Í ½Ã¹ß.?
        q.pop();

        if (kpos > max_len) {
            cout << -1 << '\n';
            break;
        }

        if (cur == kpos || visited[turn % 2][kpos]) {
            cout << turn << endl;
            break;
        }

        for (int next : {cur - 1, cur + 1, 2 * cur}) {
            if (next < 0 || next > max_len || visited[(turn + 1) % 2][next]) continue;
            q.push({next, turn + 1});
            visited[(turn + 1) % 2][next] = 1;
        }
    }

    return 0;
}