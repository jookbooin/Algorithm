/**
 * A -> B 신뢰 : B 해킹시 A도 해킹 가능
 * N = 10000
 * M = 100 000
 *
 *
 * 한번에 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터 번호
 * N 컴퓨터
 * M 줄
 *  */

/**
 * 트리 / 점들 위치 저장
 *
 *
 */
#include <bits/stdc++.h>

using namespace std;

vector<int> tree[10004];
// 개수 저장하는 인접 리스트 필요??
vector<int> val[10004];

set<int> point;
int visited[10004];

int N, M, mx;

int dfs(int idx) {
    visited[idx] = 1;
    int cnt = 0;
    for (int a : tree[idx]) {
        if (visited[a] == 0) {
            cnt += dfs(a);
        }
    }

    if (cnt == 0) return 1;

    return cnt + 1; // 본인도 추가해야 함.
}
int main(void) {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int f, s;
        cin >> f >> s;
        tree[s].push_back(f);
        // 전체 숫자들도 저장해야할 거 같은데
        point.insert(f);
        point.insert(s);
    }

    // for (int p : point) {
    //     cout << "p : " << p << " | ";

    //     for (int ret : tree[p]) {
    //         cout << ret << " ";
    //     }
    //     cout << endl;
    // }

    for (int p : point) {
        fill(&visited[0], &visited[0] + 10004, 0);
        int ret = dfs(p);
        mx = max(mx, ret);
        val[ret].push_back(p);
        // cout << "ret : " << ret << " p : " << p << endl;
    }

    sort(val[mx].begin(), val[mx].end());

    for (int ret : val[mx]) {
        cout << ret << " ";
    }

    return 0;
}
