#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
int n;
int dp[INF];

void go(int cur) {
    if (cur == 0) return;

    cout << cur << " ";
    if (cur % 3 == 0 && dp[cur / 3] == dp[cur] - 1) {
        go(n / 3);
    } else if (cur % 2 == 0 && dp[cur / 2] == dp[cur] - 1) {
        go(n / 2);
    } else {
        go(n - 1);
    }

    return;
}
int main() {
    cin >> n;

    fill(&dp[0], &dp[0] + INF, INF);
    //
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0) {
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }

        if (i % 3 == 0) {
            dp[i] = min(dp[i], dp[i / 3] + 1);
        }

        dp[i] = min(dp[i], dp[i - 1] + 1);
    }

    // 출력

    cout << dp[n] << '\n';
    go(n);
    return 0;
}