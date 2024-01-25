#include<bits/stdc++.h>
using namespace std; 

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1}; 

const int max_n = 104; 
int N,M, row, col; 
int graph[max_n][max_n], visited[max_n][max_n];
int main(){ 
    
    cin >> N >> M ;
    for(int row = 0; row < N; row ++){
        for(int col = 0; col < M; col++){
            scanf("%1d",&graph[row][col]);
        }
    } 

    queue<pair<int, int>> q;  
    visited[0][0] = 1;
    q.push({0, 0});  

    while(q.size()){
        
        tie(row, col) = q.front(); q.pop(); 

        for(int i = 0; i < 4; i++){
            int nr = row + dr[i]; 
            int nc = col  + dc[i]; 

            if(nr < 0 || nr >= N || nc < 0 || nc >= M || graph[nr][nc] == 0) continue; 
            if(visited[nr][nc]) continue; 
            visited[nr][nc] = visited[row][col] + 1; 
            q.push({nr, nc}); 
        } 
    }

    cout << visited[N - 1][M - 1]; 
    return 0;
}  
