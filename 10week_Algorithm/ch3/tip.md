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