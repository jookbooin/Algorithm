# 15686

## 조합

``` cpp
void combi(int idx, vector<int> v){
    if(v.size() == M){
        return
    }

    for(int i = 0; i< N ; i++){
        v.push_back(i);
        combi(idx+1, v);
        v.pop_back();
    }
}

int main(){
    vector<int> v;
    combi(-1,v);
    return 0;
}
```

## vector

1. idx 접근
``` cpp
vector<int> v;

int a = v[idx];
int b = v.at(idx);
```

2. 2차원 배열

``` cpp
// 1. vector 내부 vector
vector<vector<int>> chiclist

// 2. vector<int> 인 10개짜리 배열 
vector<int> v3[10];

// 3. 10 * 10 : 0으로 초기화
vector<vector<int>> v2 (10, vector<int> (10, 0));
```

# 3-I 12869


``` cpp
// 배열 
int direc[6][3] = {{9, 1, 3},
                   {9, 3, 1},
                   {1, 9, 3},
                   {3, 9, 1},
                   {1, 3, 9},
                   {3, 1, 9}};

// 2. 구조체 
struct AA{
    int a,b,c;
};

vector<AA> av = {{9,3,1},
                 {9,1,3}, 
                 {3,9,1}, 
                 {3,1,9}, 
                 {1,9,3},
                 {1,3,9}};
```


## 1. 최단거리 -> bfs !

* ( 기본 ) 점 2개 + 2차원 + 4방향 조합
* ( 심화 ) 점 n개 + m차원 + k 방향

#### `한 단계 실행`을 표현 → bfs
1. queue
2. `visited[nz][nr][nc] = visited[cz][cr][cc] + 1` 

``` cpp
void back(int one, int second, int third) {

    hp[one][second][third] = 1;                 // 첫 방문 점
    queue<HP> q;                                // 구조체로 타입 설정
    q.push({one, second, third});

    while (q.size()) {
        int co = q.front().o;
        int cs = q.front().s;
        int ct = q.front().t;
        q.pop();

        if (hp[0][0][0]) break;                 // 종료 조건

        for (int i = 0; i < 6; i++) {
            int no = max(0, co - direc[i][0]);  // 값이 음수가 나오지 않도록 
            int ns = max(0, cs - direc[i][1]);
            int nt = max(0, ct - direc[i][2]); 

            if (hp[no][ns][nt]) continue;       // 해당 점을 지난적이 있다면 pass

            hp[no][ns][nt] = hp[co][cs][ct] + 1;
            q.push({no, ns, nt});
    }
}


```
## 2. DP
1. 메모제이션 
```cpp
int& ret = dp[a][b][c];
if(ret != INF) return ret; // 메모제이션 
```
2. 최솟 값 & 개수 세기 
``` cpp
ret = min(ret, go(na, nb, nc) + 1 );
```

dp 메모제이션 코드 
``` cpp
int go(int a, int b, int c) {

    // 종료 조건
    if(a<=0 && b <=0 && c<=0 ){
        return 0;
    }
    
    int& ret = dp[a][b][c];
    if(ret != INF) return ret; // 메모제이션 

    for(AA t : av){
        int na = max(0, a-t.a);
        int nb = max(0, b-t.b);
        int nc = max(0, c-t.c);
        ret = min(ret, go(na, nb, nc) + 1 );
    }

    return ret;
}
```
# 3-F 16637
완전 탐색이지만 재귀를 이용한 문제 
재귀가 매우 어렵게 되어 있음 

## 인덱스로 접근 
- 연산자 분리
- 숫자 분리 

# 3-G 12851

## 1. 발전된 for문

모든 for문에 조건을 걸 때 다음과 같은 방법도 있음

``` cpp
for(int next : {cur-1,cur+1,cur*2}){    

    if(next >= 0 && next < max_val){

    }

}

```

## 2. 방문 점 계산 메커니즘

* a점 까지 오는 방법: 3
* b점 까지 오는 방법: 4
* c점 까지 오는 방법: 5

a,b,c 점은 모두 d점으로 갈 수 있다고 할때 d점 까지 가는 방법: 3 + 4 + 5 개 


``` cpp
int visited[max_val];  // 최소 방문 depth 
int val[max_val];      // depth로 방문한 방법 개수

if(!visited[next]){                    // 처음 방문했을때
    visited[next] = visited[cur] + 1 ; // 최단 거리
    val[next] += val[cur];             // 첫 방문시에는 이전 방법 개수랑 동일
    q.push(next);

}else if(visited[next] == visited[cur] + 1){ // 방문했지만, 다른 방법일 때
    val[next] += val[cur];                   // 
}
```

# 13913

추적 Trace_Back
`prev[next] = here`

``` cpp
const int max_len = 200004;
int visited[max_len] , prev[max_len];  // prev 배열 선언

while (q.size()) {          
    prev[next] = cur;  
}

for(int i = K; i != N; i = prev[i]){   // for문으로 역추적하는 방법
        v.push_back(i);
}

v.push_back(ret);
```

# 17071

## 플루이드 알고리즘 ( bfs에 대한 새로운 접근 )

q의 일반적인 형태가 다음과 같을 때

``` cpp
queue<int> q;
    visited[0][N] = 1;  // 0초 때 N 위치
    q.push(N);

    while (q.size()) {
        int cur = q.front();
        q.pop();

        ...
        ...
        q.push(N);
        
    }
}
```

단계(depth)별로 출력하도록 할 수도 있다.
이 문제처럼 단계별 3경우씩 증가되는 경우에는 
각 단계에 해당 하는 횟수만큼 q를 확인하는 것이다
1/ 3/ 9/ 27 

``` cpp
while (q.size()) {

    int qsize = q.size();

    for (int i = 0; i < qsize; i++) {  // 1 3 9 27

        cur = q.front();
        q.pop();

        for (int next : {cur - 1, cur + 1, cur * 2}) {
        }

    }
}

```


## 덧셈공식...
``` cpp
 while (q.size()) {
        int cur = q.front().first;
        int turn = q.front().second;
        int kpos = K + turn * (turn + 1) / 2;  // K+1+2+3+4 를 포현하는 것...
 }
```

# 14497

## 2차원 좌표 1차원으로 표현하는 방법

``` cpp
q.push(1000*jrow + jcol);

while(q.size()){
    int crow = q.front() / 1000;
    int ccol = q.front() % 1000;
}

```

## 큐 2개
특정 조건을 만났을때 새로운 큐에 넣고 -> 기존 큐를 대체하면서 다음 단계를 표현하는 듯

* 0은 현재 단계이고, 1을 만나면 위치를 저장한다.
* 다음 단계는 저장해놓았던 1의 위치부터 시작한다.

``` cpp
queue<int> q;           // 현재 단계 위치 저장용 

while (graph[trow][tcol] != '0') {  // 종료조건 
    cnt++;             // 단계
    queue<int> temp;   // 다음 단계 위치 저장용 

    while(q.size()){

        if(graph[nrow][ncol] != '0'){           // 다음 단계
            temp.push(1000 * nrow + ncol);
        }else {                                 // 현재 단계
            q.push(1000 * nrow + ncol); 
        }

    }

    q = temp;          
}
```


# 3197

## 문제를 단순화 할 필요가 있다.

* ( 단순화 ) 백조 2개를 움직인다 -> 백조 1개가 다른 백조 쪽으로 이동한다

## 플루이드 필?
* qsize = q.size()
* 큐 2개 : Q , tempQ 를 이용 후 `Q = tempQ` 로 바꿈

## Q 삭제 방법

``` cpp
// 1. 번 방법이 더 효율적이다.
void Qclear (queue<pair<int,int>> &q){ // 원본 전달 
    queue<pair<int,int>> empty;
    swap(q, empty);
}

// 2.
while(q.size()) q.pop();
```


# 1987
## 원복 방법
* 방문 처리 visited
``` cpp
void dfs(int cr, int cc,int cnt){
    mx = max(mx,cnt);
    for(int i =0; i<4;i++){
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            if (nr <0 || nr >=R || nc < 0 || nc >= C ) continue;
            if(visited[graph[nr][nc] - 'A']) continue;

            visited[graph[nr][nc] - 'A'] = 1;       // 방문 처리
            dfs(nr,nc,cnt + 1);
            visited[graph[nr][nc] - 'A'] = 0;       // 원복
    }
}
```
## 아스키 코드

총 26개 아스키 코드 
* A : 65
* a : 97

# 2529

## vector 요소 반환
* 첫번째 요소 반환 vector[0] == vector.front()
* 마지막 요소 반환 vector[vector.size()-1] == vector.back()

## 팩토리얼 값
* 10! : 362만 
* 3^10 : 6만
* 2^10 : 1024

## string 
* string은 연산자 오버라이딩을 통해서 `+char` , `+string` 모두 가능하다.
* 숫자 → string 변환하려면 `to_string(int)` 
* 숫자 → char 만드려면 `int + '0'` 과 같이 사용

## 로직
0. 백트래킹 
다음 단계로 넘어가면서 매개변수로 문자열을 더해간다.

```cpp
vector<string> ret;
go(0,""); // "" 기본 문자열을 넘기고 

void go(int idx, string num){
    if(idx == N+1){
        ret.push_back(num);     // 특정 조건에 vector에 추가 
        return;
    }

    for(int i = 0; i <= 9; i++){
        go(idx+1, num + to_string(i));   // 매개변수로 다음 단계로 넘어간다.
    }

}


```
1. 2 < 1 , 2 < 3
`string`, `char`로 크기 비교를 할때 `같은 길이`를 기준으로 `아스키 코드`를 이용해서 비교한다.
```cpp
bool opc(char x, char y, char op){
    if(x < y && op == '<') return true;
    else if (x > y && op == '>') return true;
    return false;
}
```
2. 방문처리 visited
3. 최대 최소 
    * 정렬 

# 9934