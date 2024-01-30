# 2178

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

# 1012

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

#  2583

1. bits/stdc++.h에서 기본적으로 사용할 수 없는 변수명
`bits/stdc++.h는 모든 라이브러리를 로드`
해당 변수명을 사용해야할 때는 `#define`으로 값을 할당해놓고 사용해야한다.

``` cpp
#include <bits/stdc++.h>
using namespace std;
#define prev aaa
#define next aaaa
int prev[4];
int main() {
    cout << prev[0] << '\n';
    return 0;
}

```

2. int형 dfs ( 재귀 )

영역 개수를 세는 경우에 재귀 방법 예시 

`depth:0` -> `depth:1` -> ... 마지막 단계에서 return 될때, 재귀로 인해서 
 sum += `depth: n` -> sum += `depth: n-1` -> ... -> sum += `depth: 1` -> sum += `depth: 0` 형태로 더해온다.
``` cpp
int dfs(int row, int col ){

    visited[row][col] = 1;
    int ret = 1;

    for (int i = 0; i < 4; i++) {
        int nr = row + dr[i];
        int nc = col + dc[i];

        if (nr < 0 || nr >= M || nc < 0 || nc >= N || graph[nr][nc]) continue;
        if (visited[nr][nc]) continue;
        
        ret += dfs(nr, nc);
    }
    cout << "( "<< row << ","<< col <<" ) -> " << ret <<endl;

    return ret;

}

area.push_back(dfs(row,col));


// 출력값 
// ( 1,2 ) -> depth : 5 ret : 1
// ( 1,3 ) -> depth : 4 ret : 2
// ( 0,3 ) -> depth : 3 ret : 3
// ( 0,2 ) -> depth : 2 ret : 4
// ( 0,1 ) -> depth : 1 ret : 5
// ( 1,0 ) -> depth : 1 ret : 1
// ( 0,0 ) -> depth : 0 ret : 7

// ( 4,2 ) -> depth : 12 ret : 1
// ( 4,3 ) -> depth : 11 ret : 2
// ( 4,4 ) -> depth : 10 ret : 3
// ( 3,4 ) -> depth : 9 ret : 4
// ( 2,4 ) -> depth : 8 ret : 5
// ( 2,5 ) -> depth : 7 ret : 6
// ( 3,5 ) -> depth : 6 ret : 7
// ( 4,5 ) -> depth : 5 ret : 8
// ( 4,6 ) -> depth : 4 ret : 9
// ( 3,6 ) -> depth : 3 ret : 10
// ( 2,6 ) -> depth : 2 ret : 11
// ( 1,6 ) -> depth : 1 ret : 12
// ( 0,6 ) -> depth : 0 ret : 13

// ( 4,0 ) -> depth : 0 ret : 1
```


# 1992

## 1. 붙어있는 형태로 입력받을 때

1000
0000
0111
0000

####  string으로 변환

* `string` input으로 입력받고
* `char` input[col] 로 분해
* `int` input[col] - '0'

``` cpp
int graph[max_n][max_n];

string input;

for(int row = 0; row < N ; row ++){
    cin >> input;
    for(int col = 0 ; col < M ; col++){
        graph[row][col] = input[col] - '0';
    }
}

```

#### scanf
int 일 때는 `%1d`로 입력받는 것이 중요.
``` cpp
// int
int graph[max_n][max_n];

for(int row = 0; row < N ; row ++){
    for(int col = 0 ; col < M ; col++){
        scanf("%1d",&graph[row][col]);
    }
}

// char
char graph[max_n][max_n];

for(int row = 0; row < N ; row ++){
    for(int col = 0 ; col < M ; col++){
        scanf("%c",&graph[row][col]);
    }
}
```

#### char + cin

cin 으로 `int` 타입을 받으면 `개행 문자` 직전까지 받지만,
`char` 타입은 한 문자만 입력 받기 때문에 상관없다.

``` cpp
char graph[max_n][max_n];

for(int row = 0; row < N ; row ++){
    for(int col = 0 ; col < M ; col++){
        cin >> graph[row][col];
    }
}
```

## 2. char -> string

* string(1, char);
* string + char

``` cpp
 char ch = 'B';
 cout << string(1,ch) <<endl;  // B
 cout << string(2,ch) <<endl;  // BB
 cout << string(3,ch) <<endl;  // BBB

 string str= "";
 cout << str + ch << endl;

```


``` cpp

```


