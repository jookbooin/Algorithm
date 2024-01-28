/**
 * 일정한 높이 이하의 모든 지점은 물에 잠긴다
 * 그 지역에 많은 비가 내렸을 때 물에 잠기지 않는 안전한 영역이
 *  최대로 몇 개가 만들어 지는 지를 조사하려고 한다.
 * 
 * N = 100
*/

#include <bits/stdc++.h>

using namespace std;
const int max_n = 101;

int dr[] = {-1,0,1,0 };
int dc[] = { 0,1,0,-1};

int graph[max_n][max_n], visited[max_n][max_n];
int N;
int result;

void dfs(int row, int col,int limit){
    visited[row][col] = 1;
    for(int i = 0; i<4 ; i++){
        int nr = row + dr[i];
        int nc = col + dc[i];

        if(nr < 0 || nr >= N || nc < 0 || nc >= N || graph[nr][nc] <= limit) continue;
        if(visited[nr][nc]) continue;
        dfs(nr,nc,limit);
    }
}


int find(int limit){
    int count = 0;
    
    for(int row = 0 ; row <N ; row ++){
        for(int col = 0; col < N; col ++ ){
            if(graph[row][col] > limit && !visited[row][col]){
                dfs(row,col,limit);
                count ++;
            }
        }
    }

    return count;
}

int main(void){

    cin >> N ;
    for(int row = 0 ; row < N ; row ++){
        for(int col = 0; col < N ; col ++){
            cin >> graph[row][col];
        }
    }

    // 100 00 00 
    for(int limit = 0; limit <= 101; limit ++){
        fill(&visited[0][0], &visited[0][0] + (max_n)*(max_n) , 0);
        result = max(result, find(limit));
        // cout << limit << " : " << result << '\n';
    }
    

    cout << result << '\n';
    return 0;

}