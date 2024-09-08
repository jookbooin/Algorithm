/**
 * N*M
 * (1,1) ~ (N,M)
 * 오락실 C : 오락실 번호가 증가하는 순서대로
 * (r,c) → (r+1,c), (r,c+1)
 *
 * < 오락실 방문 규칙 >
 * 오락실 번호 증가하는 순서
 * - 순서대로 방문            = (1) → (2)
 * - 아무 것도 방문하지 않거나 = (2)
 *
 * 오락실을 K번 방문해서 학원까지 도착하는 경로의 수...?
 * - 0개 방문하고 학원까지
 * - 1개 방문하고 학원까지
 * - 2개 방문하고 학원까지
 *
 * 오락실 위치 c개
 *
 *
 * 경로 저장 = 메모제이션
 * dp[nr][nc][이전에 방문한 오락실 번호][현재까지 방문한 오락실 개수 ];
 * dp[nr][nc][prev][c] = dp[nr-1][nc][prev][c] + dp[nr][nc-1][prev][c]
 *
 */

#include <bits/stdc++.h>

using namespace std;

int n, m, c, gr, gc;
const int mod = 1000007;

int graph[54][54], dp[54][54][54][54];

int go(int cr, int cc, int cnt, int prev) {
    // 범위 벗어났을때
    if (cr > n || cc > m) return 0;

    // 학원에 도착했을때?
    if (cr == n && cc == m) {
        // 오락실 모두 방문했고
        // (n, m) 이 오락실이 아닌 경우
        if (cnt == 0 && graph[cr][cc] == 0) return 1;

        // 오락실 방문 횟수 1번 남았고,
        // (n, m) 이 오락실
        // (n, m) 이 오름차순이면 방문 가능
        if (cnt == 1 && graph[cr][cc] > prev) return 1;
        return 0;
    }

    // 메모이제이션
    int &ret = dp[cr][cc][cnt][prev];
    if (ret != -1) return ret;

    // -1 일때
    ret = 0;

    if (graph[cr][cc] == 0) {
        ret = (go(cr + 1, cc, cnt, prev) + go(cr, cc + 1, cnt, prev)) % mod;
    } else if (graph[cr][cc] > prev) {
        ret = (go(cr + 1, cc, cnt - 1, graph[cr][cc]) + go(cr, cc + 1, cnt - 1, graph[cr][cc])) % mod;
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    memset(dp, -1, sizeof(dp));

    cin >> n >> m >> c;

    for (int i = 1; i <= c; i++) {
        cin >> gr >> gc;
        graph[gr][gc] = i;
    }

    // 오락실 c번 방문
    for (int k = 0; k <= c; k++) {
        cout << go(1, 1, k, 0) << " ";
    }

    return 0;
}