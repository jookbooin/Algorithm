#include <bits/stdc++.h>
using namespace std;   
const int dr[] = {0, -1, 0, 1}; 
const int dc[] = {-1, 0, 1, 0}; 
int visited[51][51], a[51][51], cnt, compSize[2504], n, m, mx, big; 

int dfs (int r, int c, int cnt){  //

    if(visited[r][c]) return 0;             // 방문했다면 ret에 더해지면 안됨.

    visited[r][c] = cnt;
    int ret = 1;

    for(int i =0; i< 4; i++){
        if(!(a[r][c] & (1 << i))){          // 지날 수 있을 때
            int nr = r + dr[i];
            int nc = c + dc[i];
            ret += dfs(nr,nc, cnt);         // 1 + 1 + 1 = 3
        }
    }
    return ret;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            cin >> a[i][j]; 
        }
    }

    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if(!visited[i][j]){
                cnt++;                           // 영역 개수 
                compSize[cnt] = dfs(i, j, cnt);  // 해당 영역 - 내부 개수
                mx = max(mx, compSize[cnt]);     // 영역별 내부 최대 값
            } 
        }
    }

    for(int r = 0; r< m ; r++){
        for(int c =0; c < n ; c++){
            if( r + 1 < m){ // row 
                int a = visited[r + 1][c];
                int b = visited[r][c];
                if(a != b){
                    big = max(big , compSize[a] + compSize[b]);
                }
            }

            if( c + 1 < n){ // col 
                int a = visited[r][c+1];
                int b = visited[r][c];
                if(a != b){
                    big = max(big, compSize[a] + compSize[b]);
                }
            }
        }
    }

    cout << cnt << "\n" << mx << "\n" << big <<'\n';

}