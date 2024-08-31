/**
 * % 3
 * % 2
 * - 1
 *
 * 3개 이용해서 1 만드는 최소 횟수
 * 1을 만드는 방법 출력
 *
 * 1. 3가지 방법 [3] ( )
 * 2. 횟수 [t]
 * 3.
 */

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e6 + 4;
typedef long long ll;
ll dp[INF];
ll n;
int main() {
    cin >> n;

    fill(&dp[0], &dp[0] + INF, INF);

    dp[1] = 0;

    for (int i = 2; i <= n; i++) {
        dp[i] = min(dp[i], dp[i - 1] + 1);

        if (i % 3 == 0) {
            dp[i] = min(dp[i], dp[i / 3] + 1);
        }
        
        if (i % 2 == 0) {
            dp[i] = min(dp[i], dp[i / 2] + 1);
        }
    }

    cout << dp[n] << "\n";

    cout << n << " ";
    while (n > 1) {
        if (n % 3 == 0 && dp[n / 3] == dp[n] - 1) {
            cout << n / 3 << " ";
            n = n / 3;
        } else if (n % 2 == 0 && dp[n / 2] == dp[n] - 1) {
            cout << n / 2 << " ";
            n = n / 2;
        } else {
            cout << n - 1 << " ";
            n = n - 1;
        }
    }

    return 0;
}