#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
int n, m, k, a[104][104], b[104][104], visited[104][104], ret = INF, r, c, s, dir, sy, sx, ey, ex;

vector<pair<int, int>> vv;
vector<int> v_idx;

struct A {
    int y, x, ss;
};

vector<A> v;

// 재귀
void go(int y, int x, int first) {
    
    // 첫번째 호출이 아닐때
    // 꼭짓점 만나면 방향 전환
    if (!first && y == sy && x == sx) dir++;
    if (!first && y == sy && x == ex) dir++;
    if (!first && y == ey && x == ex) dir++;
    if (!first && y == ey && x == sx) dir++;

    int ny = y + dy[dir];
    int nx = x + dx[dir];

    if (visited[ny][nx]) return;

    visited[ny][nx] = 1;
    vv.push_back({ny, nx});

    // 첫 호출이 아니기 때문에 0
    go(ny, nx, 0);
}

void rotateAll(int y, int x, int ss) {
    for (int i = 1; i <= ss; i++) {
        sy = y - 1 * i;
        sx = x - 1 * i;
        ey = y + 1 * i;
        ex = x + 1 * i;

        vv.clear();
        dir = 0;
        memset(visited, 0, sizeof(visited));
        visited[sy][sx] = 1;
        vv.push_back({sy, sx});  // 회전 시키는 idx들 저장
        go(sy, sx, 1);           // 테두리 저장

        vector<int> vvv;  // 배열 값 저장
        for (pair<int, int> c : vv) {
            vvv.push_back(b[c.first][c.second]);
        }

        // 시계 방향 회전
        rotate(vvv.rbegin(), vvv.rbegin() + 1, vvv.rend());

        // rotate한 값 배열에 반영
        for (int i = 0; i < vv.size(); i++) {
            b[vv[i].first][vv[i].second] = vvv[i];
        }
    }
}

int solve() {
    // 돌리고
    for (int i : v_idx) rotateAll(v[i].y, v[i].x, v[i].ss);

    int mn = INF;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) sum += b[i][j];
        mn = min(mn, sum);
    }

    return mn;
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < k; i++) {
        cin >> r >> c >> s;
        r--;
        c--;
        v.push_back({r, c, s});  //
        v_idx.push_back(i);      // permutation 용 idx
    }

    do {
        memcpy(b, a, sizeof(b));
        ret = min(ret, solve());

    } while (next_permutation(v_idx.begin(), v_idx.end()));

    cout << ret << '\n';

    return 0;
}