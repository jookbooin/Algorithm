#include <bits/stdc++.h>

using namespace std;

const int dr[] = {0, 0, -1, 1};
const int dc[] = {1, -1, 0, 0};

typedef struct _horse {
    int r, c, dir;
} horse;

int graph[16][16]; // 색깔판
vector<horse> hv; // 움직이는 순서 
vector<int> hpos[16][16]; // idx 차례로 저장?

int n, k, cnt = 0, r, c, dir;

bool check_blue(int nr, int nc) {
    if (graph[nr][nc] == 2) return true;
    if (nr < 0 || nr >= n || nc < 0 || nc >= n) return true;

    return false;
}

void move(int cr, int cc, int dir, int i) { // i번째 말
    int nr = cr + dr[dir];
    int nc = cc + dc[dir];

    if (check_blue(nr, nc)) {
        // 반대 방향
        hv[i].dir ^= 1;

        nr = cr + dr[hv[i].dir];
        nc = cc + dc[hv[i].dir];

        // 움직이지 않음
        if (check_blue(nr, nc)) return;
    }

    vector<int>& cur_v = hpos[cr][cc];
    vector<int>& next_v = hpos[nr][nc];

    // 쌓여있는 말 확인
    auto pos = find(cur_v.begin(), cur_v.end(), i);

    // 빨강
    if (graph[nr][nc] == 1) {
        // cur_v의 [pos, cur_v.end()) 
        reverse(pos, cur_v.end());
    }

    // 쌓여있는 인덱스
    for (auto it = pos; it != cur_v.end(); it++) {
        // 1. 
        next_v.push_back(*it);
        
        // 2. 위치 변경
        hv[*it].r = nr;
        hv[*it].c = nc;
    }

    cur_v.erase(pos, cur_v.end());
}

bool check() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (hpos[i][j].size() >= 4) return true;
        }
    }
    return false;
}

bool simul() {
    for (int i = 0; i < hv.size(); i++) {
        int cr = hv[i].r;
        int cc = hv[i].c;
        int dir = hv[i].dir;

        // 움직임
        move(cr, cc, dir, i);

        // 종료 조건 : 말 4개
        if (check()) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < k; i++) {  // 수정된 부분
        cin >> r >> c >> dir;
        r--; c--; dir--;  // 수정된 부분

        // 1. 말 순서
        hv.push_back({r, c, dir});  

        // 2. 말 위치
        hpos[r][c].push_back(i);
    }

    int cnt = 0;
    bool flag = false;

    while (cnt <= 1000) {
        cnt++;
        if (simul()) {
            flag = true;
            break;
        }
    }

    if (flag) cout << cnt << '\n';
    else cout << -1 << '\n';
    
    return 0;
}
