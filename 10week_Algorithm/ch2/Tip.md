## 2178

1. 그래프 따닥따닥 붙어 있는 것 입력받을 때
`cin` 은  개행문자 ( 띄어쓰기, 한줄띄기 )까지만 받을 수 있다.
``` cpp
/**
 * 4 6
   101111
   101010
   101011
   111011
*/

// 1. string 
for(int i = 0; i < n; i++){
    cin >> s;
    for(int j = 0; j < m; j++){
        a[i][j] = s[j] - '0';
    }
}


// 2. scanf 
for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
        scanf("%1d", &a[i][j]);
    }
}

```

2. bfs 범위 탐색 먼저해야한다.
``` cpp 
if(nr < 0 || nr >= N || nc < 0 || nc >= M || graph[nr][nc] == 0) continue; 
if(visited[nr][nc]) continue; 
```

3. 최단거리 구하는 식 
``` cpp
visited[nr][nc] = visited[row][col] + 1; 
visited[nz][nx][ny] visited[z][x][y] + 1; // 일 수도??
```

4. 8방향일 수도 있다
``` cpp 
int dr[8] = {-1, 0, 1, 0};
int dc[8] = {0, 1, 0, -1}; 

 for(int i = 0; i < 8; i++){ }

```