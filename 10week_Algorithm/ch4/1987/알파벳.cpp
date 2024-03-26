/**
 * 좌측 상단 (1,1) 시작
 * 상하좌우
 * 새로 이동한 칸에 적혀 있는 알파벳은 지나온 알파벳과는 달라야 함
 * 말이 최대한 몇칸 갈 수 있을까
 * 
 * r,c = 20
*/

/**
 * - 시작 위치 방문 표시 
 * - 알파벳 방문(26), 위치 방문
 * 
*/
#include<bits/stdc++.h>
using namespace std;

int alpha[26]; // 알파벳 방문 처리
int r,c,ret=0;
char graph[24][24];
int visited[24][24];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0 ,-1};

void dfs(int cr, int cc, int cnt){

    ret = max(ret,cnt);
    
    for(int i = 0; i<4; i++){
        int nr = cr + dr[i];
        int nc = cc + dc[i];

        if(nr<1 || nr > r || nc <1  || nc > c || visited[nr][nc]) continue;
        if(alpha[graph[nr][nc]-'A']) continue;

        // 방문 처리
        visited[nr][nc] = 1;
        alpha[graph[nr][nc]-'A'] = 1;
        // dfs(nr,nc);
        dfs(nr,nc,cnt+1);
        // 방문 취소 
        visited[nr][nc] = 0;
        alpha[graph[nr][nc]-'A'] = 0;
    }

}

int main(){
    cin >> r >> c;
    
    for(int i = 1; i<=r;i++){
        for(int j = 1; j<= c; j++){
            cin >> graph[i][j];
        }
    }
    
    visited[1][1] = 1;
    alpha[graph[1][1]-'A'] = 1;

    dfs(1,1,1);

    cout << ret << '\n';
    // cout << graph[1][1]-'A'<<'\n';
    // cout << (int)'A' << endl;
    // cout << (int)'Z' << endl;
    return 0;

}