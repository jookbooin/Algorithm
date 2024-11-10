/**
 * 세로 n
 * 가로 m (50)
 * 
 * H = 구멍 
 * 
 * 1. 동전이 있는 곳에 쓰여진 숫자 X
 * 2. 4 방향 중 택 1
 * 3. 고른 방향 만큼 X 움직임 
 *     - 중간에 있는 구멍이 무시..?
 * 
 * 무한번 움직일 수 있다면 -1
 * 
 */

#include <bits/stdc++.h>

using namespace std;
int n, m;

const int INF = 987654321;

int dp[54][54];
int graph[54][54];
int visited[54][54];

int dr[4] = {-1,0,1,0};
int dc[4] = {0,1,0,-1};

bool flag = false;

int go(int r, int c){

    // 이미 지난점 지나면 -> 무한 순회 
    if(visited[r][c]) {
        cout << -1 << endl;
        exit(0);
    }

    int& ret = dp[r][c];
    if(ret != -1) return ret;
    ret = 1;

    int val = graph[r][c];

    visited[r][c] = 1; // r,c 방문 처리

    for(int i = 0; i<= 4; i++ ){
        
        // val 만큼 이동 
        int nr = r + dr[i] * val;
        int nc = c + dc[i] * val;

        if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
        if(graph[nr][nc] == -1) continue;
        
        ret = max(ret, go(nr, nc) + 1);
    }

    visited[r][c] = 0;

    return ret;
}

string str ;
int main(){
    cin >> n >> m;

    for(int i = 0; i< n; i++){
        cin >> str;
        for(int j = 0; j< str.size(); j++){
            if(str[j] == 'H'){
                graph[i][j] = -1;
                continue;
            }

            graph[i][j] = str[j] - '0';
        }
    }

    memset(dp, -1, sizeof(dp));

    int ans = go(0,0);

    if(flag){
        cout << -1 << endl;
    }else {
        cout << ans  << endl;
    }

    return 0;
}