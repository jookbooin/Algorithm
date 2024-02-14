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

### 1. 붙어있는 형태로 입력받을 때

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

# 2910

### 1. 정렬 comparator(커스텀 비교 함수)

기본 정렬은 `오름 차순 `, 추가적인 정렬 조건을 주기위해서는 sort의 세번째 인자에 `comparator`를 전달해주면 된다.

``` cpp
// 오름차순
sort(b, b + 5);
sort(a.begin(), a.end(), less<int>());

 // 내림차순
 sort(b, b + 5, greater<int>());
```

pair을 이용했을때 `first`, `second` 에 각각 다른 정렬 조건을 줄 수 있다.

``` cpp
bool cmp (pair<int,int> a, pair<int,int> b){
    return a.first > b.first   // first는 내림차순 
                               // second는 오름차순 ( 기본 )
}

//
bool cmp(pair<int,int> a, pair<int, int> b){
	if(a.first == b.first){
		return mp_first[a.second] < mp_first[b.second];
	}
	return a.first > b.first;
}

```

### 2. map

map은 key 값에 따라서 사전순서대로 자동 정렬된다.
`value` 값을 기준으로 정렬하기 위해서는 `vector`로 변환한 뒤 `pair`정렬 방식을 사용해야한다.


# 4659

### 1. 포함되어 있는지 확인 

* vector - find

``` cpp
// vector 생성 
vector<char> cv{'a', 'e', 'i', 'o', 'u'};

for (int i = 0; i < input.size(); i++) {
            auto it = find(cv.begin(), cv.end(), input[i]);

            if (it != cv.end()) {  // 모음 일때

            }else {                // 자음 일때

            }
}
```
* 함수
함수를 이용해서 `bool` 값으로 `포함되어 있는지 안되어 있는지` 판별할 수 있음.
``` cpp
bool isVowel(int idx) {
    return (idx == 'a' || idx == 'e' || idx == 'i' || idx == 'o' || idx == 'u');
}

 for (int i = 0; i < s.size(); i++) {
            int idx = s[i];
            if (isVowel(idx)){}  // 포함
            else{}               // 포함 x
 }
```

### 2. char ↔ int 아스키 코드 
c, c++ 에서는 문자 형변환이 자연스럽게 되는듯
``` cpp

bool isVowel(int idx) {
    return (idx == 'a' || idx == 'e' || idx == 'i' || idx == 'o' || idx == 'u');
}

string input;
cin >> input

for (int i = 0; i < input.size() ; i++){
    int ascii = input[i];
    isVowel(ascii);
}
```

### Tip : 이전 단계 저장하기

``` cpp
// 1. i-1 과 i 인덱스 비교
for(int i = 0 ; i < input.size() ; i++){
    if(input[i - 1] == input[i])
}

// 변수 prev 설정 
int prev = -1;
for(int i = 0 ; i < input.size() ; i++){
    int ascii = input[i];
    if(i > 0 && prev == ascii){}

    prev = ascii;  // 이전 문자를 prev 변수에 저장 
}
```

# 2870

## 1. ret.front()
string.front() 를 사용하기 위해서는 `string.size()`를 통해 `빈 문자열이 아님`을 먼저 확인해야 한다.

``` cpp
if(ret.size() && ret.front() == '0'){  
    ret.erase(0,1);
}
```

## 2. 자리수 

* int : 9 자리
* long long : 18자리
* 이후에는 `string`으로 잡는 생각을 해야한다.

## 3. 문자열 -> int 정렬 + 커스텀 정렬

* 오름차순 : a < b ( true )
  내림차순 : a > b ( true )

* 문자열 비교는 아스키 코드를 기반으로 정렬을 하기 때문에 `"222"` , `"1234"` 와 같은 문자열을 비교하기 위해서는 size 를 비교해야한다.

``` cpp
bool cmp(string a, string b){
    if(a.size() == b.size()) return a < b;

    return a.size() < b.size();
}
```

## 4. 아스키 코드 65 97
* A : 65    | Z : 90 

* a : 97    | z : 122

* 0 : 48

# 2852

## 1. 문자열 -> 숫자
* c스타일 : `atoi(ti.substr(0, 2).c_str())`
* c++ 스타일 : `stoi(ti.substr(0, 2))`

## 2. 시간을 계산하는 기준..
* total : hour => min*60 => sec*60*60

## prev 
이전값을 유지하기 위해서 사용 
하지만 겹치는 변수명은 `define` 사용
``` cpp
#define prev hihi
```

# 9012

## 1. stack 

``` cpp
stack <int> stk;

stk.push(1);

stk.pop();      // 가장 위에 있는 요소 삭제

stk.top();      // 가장 위에 있는 요소 확인

stk.size();

stk.empty()     // 비어있는지 확인할 수 있음.
```


# 14502

## 2차원 배열을 꼭 깊은 복사하는 것이 답은 아니다.

좌표만을 구별했음 
* 바이러스 좌표
* 벽 좌표

``` cpp
for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            cin >> graph[row][col];
            if (graph[row][col] == 2) virusList.push_back({row, col});
            if (graph[row][col] == 0) wallList.push_back({row, col});
        }
    }
```

## 배열 복사 

* STL 내장함수 copy
``` cpp
// 원본을 => graph_copy 로 복사 
copy(&graph[0][0], &graph[0][0] + 10 * 10, &graph_copy[0][0]);
```

* 제작 함수 
``` cpp
void copyArr(int tmp[10][10], int a[10][10]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            tmp[row][col] = a[row][col];
        }
    }
}
```

## 3점을 선택하는 방법 = 조합 


* 3중 for문 
``` cpp
for (int i = 0; i < wallList.size(); i++) {
        for (int j = 0; j < i; j++) {
            for (int k = 0; k < j; k++) {
                graph[wallList[i].first][wallList[i].second] = 1;
                graph[wallList[j].first][wallList[j].second] = 1;
                graph[wallList[k].first][wallList[k].second] = 1;
                ret = max(ret, solve());
                graph[wallList[i].first][wallList[i].second] = 0;
                graph[wallList[j].first][wallList[j].second] = 0;
                graph[wallList[k].first][wallList[k].second] = 0;
            }
        }
    }

```

* 재귀 

``` cpp
void wall(int n) {
    if (n == 3) {
        copy(&graph[0][0], &graph[0][0] + 10 * 10, &graph_copy[0][0]);
        virus(graph_copy);
        mb = max(mb, count(graph_copy));
        return;
    }

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            if (graph[row][col] == 0) {
                graph[row][col] = 1;
                wall(n + 1);
                graph[row][col] = 0;
            }
        }
    }
}
```

# 1068

## 1. tree 는 root 부터 시작해 본다.
``` cpp
 dfs(root)
```

## 2. 트리 개수 세는법 (암기)
``` cpp
int dfs(int idx){
    int child = 0;
    int ret = 0;
    for(int a : tree[idx]){
        if(a == ers) continue;

        ret += dfs(a);  // 하위 자식 노드 개수를 재귀로 더한다
        child ++;
    }

    if(child == 0)  // 리프 노드일 때
        return 1;
}
```

## 3. vector 선언

* 2차원 배열 : vector<vector<int>> vec2
* 인접 리스트 : vector<int> tree[10];


# 1325

## 1068 트리개수 세는법 + 자신 개수 포함
``` cpp
int dfs(int idx) {
    visited[idx] = 1;
    int ret = 1;  //  현재 노드
    for (int a : tree[idx]) {
        if (visited[a]) continue;
        ret += dfs(a);      // + 자식들
    }
    
    return ret;
}
```

# 17298 

## 짝짓기 문제 : stack을 우선 생각해봐라

stack의 top은 `st.size()` , `!st.empty()` 와 함께 써야함

* 앞에서 가는 방법 ( sol_17298 )

``` cpp
 for (int i = 0; i < N; i++) {
        while (st.size() && val[st.top()] < val[i]) {  // st이 비어있지 않아야 top 탐색가능
            ret[st.top()] = val[i];
            st.pop();
        }
        st.push(i);
    }
```

* 뒤에서 올 수도 있음 m17298


## 초기화 하는 방법에 memset, fill 사용
``` cpp
memset(ret, -1, sizeof(ret));
```

