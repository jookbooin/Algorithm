/**
 * A -> B �ŷ� : B ��ŷ�� A�� ��ŷ ����
 * N = 10000
 * M = 100 000
 *
 *
 * �ѹ��� ���� ���� ��ǻ�͸� ��ŷ�� �� �ִ� ��ǻ�� ��ȣ
 * N ��ǻ��
 * M ��
 *  */

/**
 * Ʈ�� / ���� ��ġ ����
 *
 *
 */
#include <bits/stdc++.h>

using namespace std;

vector<int> tree[10004];
// ���� �����ϴ� ���� ����Ʈ �ʿ�??
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

    return cnt + 1; // ���ε� �߰��ؾ� ��.
}
int main(void) {
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        int f, s;
        cin >> f >> s;
        tree[s].push_back(f);
        // ��ü ���ڵ鵵 �����ؾ��� �� ������
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
