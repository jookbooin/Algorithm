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
vector<vector<int>> chiclist
// { { , , }, 
//   { , , },
//   { , , } }
```

# 12869

## 최단거리 -> bfs !


* ( 기본 ) 점 2개 + 2차원 + 4방향 조합
* ( 심화 ) 점 n개 + m차원 + k 방향

``` cpp
// K 방향 
int direc[6][3] = {{9, 1, 3},
                   {9, 3, 1},
                   {1, 9, 3},
                   {3, 9, 1},
                   {1, 3, 9},
                   {3, 1, 9}};

// 점 N 개 
// 여러 점을 다룰때 `구조체` 사용하는 방법 
struct HP {  
    int o, s, t;
};


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

# 12851

1. 발전된 for문

모든 for문에 조건을 걸 때 다음과 같은 방법도 있음

``` cpp
for(int next : {cur-1,cur+1,cur*2}){    

    if(next >= 0 && next < max_val){

    }

}

```

2. 방문 점 계산 메커니즘

* a점 까지 오는 방법: 3
* b점 까지 오는 방법: 4
* c점 까지 오는 방법: 5

a,b,c 점은 모두 d점으로 갈 수 있다고 할때
* d점 까지 가는 방법: 3 + 4 + 5 개 


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
