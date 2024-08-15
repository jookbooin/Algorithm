#include <bits/stdc++.h>
using namespace std;

/**
 * t초
 * pos 위치 ( 1, 2 )
 * 이동 횟수
 */
int dp[1004][2][34], brr[1004];
int n, m;

// pos 0 : 1, 1 : 2
int go(int t, int pos, int mcnt) {
    if (mcnt < 0) return -1004;
    if (t == n) return 0;  // 시작점

    int &ret = dp[t][pos][mcnt];
    if (!ret) return ret;  // 값이 0 미만이 아닌지 확인용

    // 이동 (0 → 1, 1 → 0)
    int a = go(t + 1, pos ^ 1, mcnt - 1);

    // 이동 x
    int b = go(t + 1, pos, mcnt);

    ret = max(a, b) + (pos == (brr[t] - 1));
    return ret ;
}

int main() {
    memset(dp, -1, sizeof(dp));

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> brr[i];

    // 이동 o
    int f = go(0, 1, m - 1);

    // 이동 x
    int s = go(0, 0, m);

    cout << max(f, s) << '\n';
    return 0;
}