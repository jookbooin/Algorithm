#include <bits/stdc++.h>
using namespace std;

char graph[54][54];
int dp[54][54]; // 가능한 횟수 최댓값
int visited[54][54];

int n, m;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int dfs(int cr, int cc){
    if(visited[cr][cc]){
        cout << -1 << endl;
        exit(0);
    }

    // 종료 조건 
    if (graph[cr][cc] == 'H' || cr<0 || cr>=n || cc<0 || cc >=n) {
        return 0;
    }

    int& ret = dp[cr][cc];  
    if(ret) return ret;

    visited[cr][cc] = 1;
    int val = graph[cr][cc] - '0';

    for(int i = 0; i<4; i++){
        int nr = cr + val * dr[i];
        int nc = cc + val * dc[i];

        ret = max(ret, dfs(nr,nc) + 1);

    }

    visited[cr][cc] = 0;
    return ret;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }

    cout << dfs(0,0) << endl;
}