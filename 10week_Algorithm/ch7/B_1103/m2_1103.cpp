/**
 * 무한정 : 이미 지난점을 또 지난다 -> visited
 * dp[r][c] = 해당 점을 지나는 최대 횟수
 *
 */

#include <bits/stdc++.h>

using namespace std;

char graph[54][54];
int dp[54][54]; // 가능한 횟수 최댓값
int visited[54][54];

int n, m;
const int INF = 987654321;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int dfs(int cr, int cc) {

    // 이전 방문 위치 ==> 순환
    if(visited[cr][cc]){
        return INF;
    }

    // 종료 조건 
    if (graph[cr][cc] == 'H' || cr<0 || cr>=n || cc<0 || cc >=n) {
        return 0;
    }   

    // dp = 최대 횟수이니 이미 지났다면 동일함
    if(dp[cr][cc] != -1) return dp[cr][cc];

    // 현재 위치 방문
    visited[cr][cc] = 1;
    dp[cr][cc] = 0;
    int val = graph[cr][cc] - '0';  

    for (int i = 0; i < 4; i++) {
        // 다음 위치
        int nr = cr + val * dr[i];
        int nc = cc + val * dc[i];

        dp[cr][cc] = max(dp[cr][cc], dfs(nr,nc) + 1 );

        // 방문 해제
    }

    visited[cr][cc] = 0;

    return dp[cr][cc];
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }

    memset(dp, -1, sizeof(-1));
    dp[0][0] = 0;

    int val = dfs(0, 0);

    if(val >= INF){
        cout << -1 << endl;
    }else{
        cout << val << endl;
    }
    return 0;
}