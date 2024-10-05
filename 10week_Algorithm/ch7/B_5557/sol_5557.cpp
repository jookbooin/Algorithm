#include <bits/stdc++.h>

using namespace std;
long long n;
long long arr[104];
long long dp[104][24];  // 개수

long long go(long long pos, long long result) {
    if (result < 0 || result > 20) return 0;

    long long& ret = dp[pos][result]; 
    if (ret) return ret;

    if (pos == n - 2) {
        return result == arr[n-1] ? 1 : 0;
    }

    // pos + 1
    ret += go(pos + 1, result + arr[pos + 1]);
    ret += go(pos + 1, result - arr[pos + 1]);

    return ret;
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // fill(&dp[0][0], &dp[0][0] + 104*24, -1 );/
    cout << go(0, arr[0]) << endl;

    return 0;
}
