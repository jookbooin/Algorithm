# ? 2178

### 1. �׷��� ���ڵ��� �پ� �ִ� �� �Է¹��� ��
`cin` ��  ���๮�� ( ����, ���ٶ�� )������ ���� �� �ִ�.
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

### 2. bfs ���� Ž�� �����ؾ��Ѵ�.
``` cpp 
if(nr < 0 || nr >= N || nc < 0 || nc >= M || graph[nr][nc] == 0) continue; 
if(visited[nr][nc]) continue; 
```

### 3. �ִܰŸ� ���ϴ� �� 
``` cpp
visited[nr][nc] = visited[row][col] + 1; 
visited[nz][nx][ny] visited[z][x][y] + 1; // �� ����??
```

### 4. 8������ ���� �ִ�
``` cpp 
int dr[8] = {-1, 0, 1, 0};
int dc[8] = {0, 1, 0, -1}; 

 for(int i = 0; i < 8; i++){ }

```

# ? 1012

### 1. �׽�Ʈ ���̽� �ʱ�ȭ fill

* graph�� ���������� ǥ���ϴ� ��
* �׽�Ʈ ���̽����� graph�� �� �����ؾ� �ϴ� ��

``` cpp
#include <bits/stdc++.h>
using namespace std;

const int max_n = 51;  // <- ���� ���ǿ� ���� ���� or 104

int T, N, M, K, sr, sc;
int graph[max_n][max_n], visited[max_n][max_n];  // <- ������ ���� ���������� ǥ�� 

int main(void) {
    cin >> T;
    for (int i = 0; i < T; i++) {
        
        // max_n�� ������ ���� ��ü �׷����� �ʱ�ȭ�Ѵ�.
        fill(&graph[0][0], &graph[0][0] + max_n * max_n, 0);
        fill(&visited[0][0], &visited[0][0] + max_n * max_n, 0);

    }

}
```

### 2. dfs 2���� 
``` cpp
// 1. �ܺ�
void dfs(int here){
    visited[here] = 1; // �ܺ�

    if(int there : adj[there]){
        if(visited[there]) continue;
        dfs(there);
    }

}

// 2. ����
void dfs(int here){

    for(int there : adj[here]){
        if(visited[there]) continue;
        visited[there] = 1;  // ����
        dfs(there);
    }

}
```


