/**
 *
 *
 */

#include <bits/stdc++.h>

using namespace std;

const int mmax = 100000;
int t, n, m, mov;

int pos[mmax + 4];  // 영화 위치 저장

// 세그먼트 트리 생성

// update
void update(vector<int>& tree, int cur, int start, int end, int idx, int diff) {
    if (idx < start || idx > end) return;
    tree[cur] += diff;

    if (start != end) {
        int mid = (start + end) / 2;
        update(tree, cur * 2, start, mid, idx, diff);
        update(tree, cur * 2 + 1, mid + 1, end, idx, diff);
    }
}

// sum
int sum(vector<int>& tree, int cur, int start, int end, int left, int right) {
    if (left > end || right < start) {
        // cout << " 1" << endl;
        return 0;
    }

    if (left <= start && end <= right) {
    //    cout << "start : "<< start << " end : "  << end << endl;
    //    cout << "left : "<< left << " right : "  << right << endl;
    //    cout << endl;
        return tree[cur];
    }

    int mid = (start+  end) / 2;
    int left_sum = sum(tree, cur * 2, start, mid, left, right);
    int right_sum = sum(tree, cur * 2 + 1, mid + 1, end, left, right);

    return left_sum + right_sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> m;

        vector<int> tree((n + m) * 4 + 1);

        // pos 초기화 + tree 초기화
        memset(pos, 0, sizeof(pos));
        for (int i = 1; i <= n; i++) {
            pos[i] = m + i;

            // [1, m+n]
            update(tree, 1, 1, m + n, pos[i], 1);
        }

        // 찾는 영화 (m)
        for (int i = m; i >= 1; i--) {
            cin >> mov;

            // [1, pos[mov]-1]까지 구간합
            cout << sum(tree, 1, 1, m + n, 1, pos[mov] - 1) << " ";
            // pos[mov] = 0
            update(tree, 1, 1, m + n, pos[mov], -1);

            // pos[mov] = i;
            update(tree, 1, 1, m + n, i, 1);
            pos[mov] = i;
        }
        cout << endl;
    }

    return 0;
}