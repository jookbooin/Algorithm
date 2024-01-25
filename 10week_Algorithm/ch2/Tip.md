# ? 2178

### 1. 그래프 따닥따닥 붙어 있는 것 입력받을 때
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

### 2. bfs 범위 탐색 먼저해야한다.
``` cpp 
if(nr < 0 || nr >= N || nc < 0 || nc >= M || graph[nr][nc] == 0) continue; 
if(visited[nr][nc]) continue; 
```

### 3. 최단거리 구하는 식 
``` cpp
visited[nr][nc] = visited[row][col] + 1; 
visited[nz][nx][ny] visited[z][x][y] + 1; // 일 수도??
```

### 4. 8방향일 수도 있다
``` cpp 
int dr[8] = {-1, 0, 1, 0};
int dc[8] = {0, 1, 0, -1}; 

 for(int i = 0; i < 8; i++){ }

```

# ? 1012

### 1. 테스트 케이스 초기화 fill

* graph를 전역적으로 표현하는 법
* 테스트 케이스마다 graph를 재 생성해야 하는 것

``` cpp
#include <bits/stdc++.h>
using namespace std;

const int max_n = 51;  // <- 문제 조건에 따라서 설정 or 104

int T, N, M, K, sr, sc;
int graph[max_n][max_n], visited[max_n][max_n];  // <- 임의의 수로 전역적으로 표시 

int main(void) {
    cin >> T;
    for (int i = 0; i < T; i++) {
        
        // max_n로 설정해 놓은 전체 그래프를 초기화한다.
        fill(&graph[0][0], &graph[0][0] + max_n * max_n, 0);
        fill(&visited[0][0], &visited[0][0] + max_n * max_n, 0);

    }

}
```

### 2. dfs 2가지 
``` cpp
// 1. 외부
void dfs(int here){
    visited[here] = 1; // 외부

    if(int there : adj[there]){
        if(visited[there]) continue;
        dfs(there);
    }

}

// 2. 내부
void dfs(int here){

    for(int there : adj[here]){
        if(visited[there]) continue;
        visited[there] = 1;  // 내부
        dfs(there);
    }

}
```


