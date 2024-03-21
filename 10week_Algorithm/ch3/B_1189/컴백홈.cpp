/**
 * 한수 왼쪽 아래 
 * T 못가는 부분
 * 
 * R C S-> 거리 K 주어졌을때 집까지 도착
 * R = 5
 * C = 5
 * K = 25
*/
#include <bits/stdc++.h>

using namespace std;

int R,C,K,ret=0;
char graph[6][6];
int visited[6][6];

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void dfs(int cr, int cc, int cnt){
    
    for(int i =0 ; i<4; i++){
        int nr = cr + dr[i];
        int nc = cc + dc[i];

        if(nr < 0 || nr >= R || nc < 0 || nc >= C ||visited[nr][nc]) continue;
    
        if(graph[nr][nc] == '.'){

            if(visited[cr][cc] == K-1 && ( nr == 0 && nc == C-1 )){
                ret ++;
                return ;
            }

            visited[nr][nc] = visited[cr][cc] + 1;
            dfs(nr,nc,cnt+1);
            visited[nr][nc] = 0;

        }
    }

}

int main(void){
    // 도착 0 , C-1
    // 시작 R-1 , 0

    cin >> R >> C >> K;
    for(int r = 0; r < R; r ++){
        for(int c = 0; c < C ; c++){
           cin >> graph[r][c];
        }
    }

    visited[R-1][0] = 1;
    dfs(R-1,0,0);
    cout << ret << "\n";


    return 0;
}


