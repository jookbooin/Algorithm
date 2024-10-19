/***
 * 파이프 항상 빈 칸 차지
 * 회전 45도만 가능 
 * 빈칸이어야 하는 곳 
 * ㅡ : 2 방향
 * ㅣ : 2 방향 
 * \ : 2 방향 
 * 
 * n : 16
 * 0 : 빈칸, 1 : 벽 
 * (1, 1) -> (n, n)
 * 
 * 이동할 수 없는 경우 0
 * 방법의 수 100만 보다 작다.
 * 
 */
#include <bits/stdc++.h>

using namespace std;
int n ;
int graph[20][20];
int dp[20][20][3]; // dir 모양으로 r,c에 도달하는 방법 수

bool check(int r, int c, int dir){
    if(dir == 0 || dir == 2) { // 가로, 세로
        if(graph[r][c] == 0) return true;
    } else if(dir == 1){
        if(graph[r][c] ==0 && graph[r-1][c] == 0 && graph[r][c-1] == 0) return true;
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i =1 ; i <=n; i++){
        for(int j = 1; j<=n; j++){
            cin >> graph[i][j];
        }
    }

    dp[1][2][0] = 1;
    for(int i = 1; i<= n; i++){
        for(int j = 1; j<=n; j++){

            // 가
            if(check(i,j+1, 0)){
                dp[i][j+1][0] += dp[i][j][0];
                dp[i][j+1][0] += dp[i][j][1];
            }

            // 대각
            if(check(i+1, j+1, 1)){
                dp[i+1][j+1][1] += dp[i][j][0];
                dp[i+1][j+1][1] += dp[i][j][1];
                dp[i+1][j+1][1] += dp[i][j][2];
            }

            // 세로
            if(check(i+1, j, 2)){
                dp[i+1][j][2] += dp[i][j][2];
                dp[i+1][j][2] += dp[i][j][1];
            }
        }
    }

    int ret = dp[n][n][0] + dp[n][n][1] + dp[n][n][2];
    cout << ret << endl;

    return 0;
}