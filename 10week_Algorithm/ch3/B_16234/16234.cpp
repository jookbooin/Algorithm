/**
 * r,c -> A[r][c] 명
 * 
 *  영역 
 * 
 * N = 50, L , R = 100
*/

/**
 * 전체 graph 대상으로 연합 계산
 * 연합 생기지 않을때 까지 반복
*/

#include <bits/stdc++.h>

using namespace std;

int N,L,R, cnt = 0,ret,sm;
int graph[104][104];
int visited[104][104];
bool flag;


int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

vector<pair<int,int>> pos;

void dfs(int row , int col ){
    
    pos.push_back({row,col});
    visited[row][col] = 1; // 연합 방문 표시
    sm += graph[row][col];

    for(int i = 0; i< 4; i++){
        int nr = row + dr[i];
        int nc = col + dc[i];

        if(nr < 0||nr >=N || nc <0 || nc >= N || visited[nr][nc]) continue;
        ret = abs(graph[row][col] - graph[nr][nc]);
        if(ret < L || ret > R) continue;
        
        // 영역별 방문 처리 겹치지 않도록
        // 영역 내 개수 
        // 영역 내부 합
        dfs(nr,nc);
    }

}

void change(){  // 연합 수 바꾸기 
    int ans = sm / pos.size();
    int r,c;
    for(pair<int,int> p : pos){
        tie(r,c) = p;
        graph[r][c] = ans;
    }
}

int main(void){
    
    cin >> N >> L >> R;
    for(int row = 0 ; row< N ; row++){
        for(int col = 0; col < N ; col ++){
            cin >> graph[row][col] ;
        }
    }

    while(1){
        flag = false;
        fill(&visited[0][0],&visited[0][0] + 104*104 , 0);  // 일 자

        for(int row = 0 ; row< N ; row++){
            for(int col = 0; col < N ; col ++){
                if(!visited[row][col]){ // 어떠한 연합에도 포함 x
                    pos.clear(); sm = 0;  // 현재 위치
                    dfs(row,col);
                    change();
                    if(pos.size() > 1) flag = true;
                }
            }
        }

        if(!flag) break;
        cnt ++; // 일 수 
    }
    
    cout << cnt << endl;
    return 0;
}