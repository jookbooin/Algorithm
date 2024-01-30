# 2178

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

# 1012

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

#  2583

1. bits/stdc++.h���� �⺻������ ����� �� ���� ������
`bits/stdc++.h�� ��� ���̺귯���� �ε�`
�ش� �������� ����ؾ��� ���� `#define`���� ���� �Ҵ��س��� ����ؾ��Ѵ�.

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

2. int�� dfs ( ��� )

���� ������ ���� ��쿡 ��� ��� ���� 

`depth:0` -> `depth:1` -> ... ������ �ܰ迡�� return �ɶ�, ��ͷ� ���ؼ� 
 sum += `depth: n` -> sum += `depth: n-1` -> ... -> sum += `depth: 1` -> sum += `depth: 0` ���·� ���ؿ´�.
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


// ��°� 
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

## 1. �پ��ִ� ���·� �Է¹��� ��

1000
0000
0111
0000

####  string���� ��ȯ

* `string` input���� �Է¹ް�
* `char` input[col] �� ����
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
int �� ���� `%1d`�� �Է¹޴� ���� �߿�.
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

cin ���� `int` Ÿ���� ������ `���� ����` �������� ������,
`char` Ÿ���� �� ���ڸ� �Է� �ޱ� ������ �������.

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


