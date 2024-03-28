
#include<bits/stdc++.h>
using namespace std;

int alpha[26]; // 알파벳 방문 처리
int r,c,ret=0;
char graph[24][24];
int visited[24][24];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0 ,-1};

void go(int cr, int cc, int num ,int cnt){

    ret = max(ret,cnt);
    
    for(int i = 0; i<4; i++){
        int nr = cr + dr[i];
        int nc = cc + dc[i];

        if(nr<1 || nr > r || nc <1  || nc > c) continue;
        // 해당 알파벳의 위치
        int _next = (1 << (int)(graph[nr][nc]-'A'));
        
        // 방문한 점이 겹치지 않는다면
        if((num & _next) == 0 ){
            go(nr,nc, num | _next, cnt + 1);
        }
    }

    return ;
}

int main(){
    cin >> r >> c;
    
    for(int i = 1; i<=r;i++){
        for(int j = 1; j<= c; j++){
            cin >> graph[i][j];
        }
    }

    go(1,1, 1 << (int)(graph[1][1] - 'A'),1);

    cout << ret << '\n';
    return 0;

}