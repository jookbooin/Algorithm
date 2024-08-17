/**
 * n 개 도시 ( 2 ~ 16 )
 * w[i][j] : i → j로 가기 위한 비용
 * w[j][i] != w[i][j]
 * w[i][j] = 0  : i → j로 갈 수 없다.
 */

#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int n;
int val[16][16];
int dp[16][1 << 16];  // c : 확인할 위치, r : 이미 지난 점들 비트

int dfs(int cur, int visited) {
    // 모두 방문했을 때
    if (visited == (1 << n) - 1) {
        // TSP 순회가 되는 경우
        if (val[cur][0] != 0) {
            return val[cur][0];
        }
        return INF;
    }

    // 현재 cur 위치 visited 방문했을때 최소 값
    int& ret = dp[cur][visited];

    // 이미 최솟값 계산이 되어 있다.
    if (ret != -1) return ret;

    // 계산되어 있지 않을때 -> 최솟값을 구하기 위해 INF 선언
    ret = INF; 

    for (int i = 0; i < n; i++) {
        // 이미 방문
        if (visited & (1 << i)) continue;

        // cur -> cur
        if (val[cur][i] == 0) continue;

        int cost = val[cur][i];

        // cur -> i 이동 결과 최솟값
        // dp[3][1111] = val[3][0]
        int temp = dfs(i, (1 << i) | visited);

        ret = min(ret, temp + cost);
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> val[i][j];
        }
    }

    // 범위 이외의 값으로 초기화 → 지나지 않은 것 표현
    memset(dp, -1, sizeof(dp));

    cout << dfs(0, 1) << '\n';

    return 0;
}