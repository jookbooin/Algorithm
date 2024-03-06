#include <bits/stdc++.h>

using namespace std;
int R,C,mx=1,cr,cc,s;
char graph[24][24];
int visited[26];

int dr[4] = {-1,0,1,0};
int dc[4] = { 0,1,0,-1};

int alpha[26] ;

void dfs(int cr, int cc,int cnt){

    mx = max(mx,cnt);

    for(int i =0; i<4;i++){
            int nr = cr + dr[i];
            int nc = cc + dc[i];

            if (nr <0 || nr >=R || nc < 0 || nc >= C ) continue;
            if(visited[graph[nr][nc] - 'A']) continue;

            visited[graph[nr][nc] - 'A'] = 1;
            dfs(nr,nc,cnt + 1);
            visited[graph[nr][nc] - 'A'] = 0;
    }

}

int main(void){
    cin >> R >> C;

    for(int r = 0 ; r< R; r ++){
        for(int c = 0; c< C; c++){
            cin >> graph[r][c];
        }
    }

    visited[graph[0][0] - 'A'] = 1;

    dfs(0,0,1);
    
    cout << mx << endl;

    return 0;
}