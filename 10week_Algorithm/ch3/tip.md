# 15686

## ����

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

1. idx ����
``` cpp
vector<int> v;

int a = v[idx];
int b = v.at(idx);
```

2. 2���� �迭

``` cpp
vector<vector<int>> chiclist
// { { , , }, 
//   { , , },
//   { , , } }
```

# 12869

## �ִܰŸ� -> bfs !


* ( �⺻ ) �� 2�� + 2���� + 4���� ����
* ( ��ȭ ) �� n�� + m���� + k ����

``` cpp
// K ���� 
int direc[6][3] = {{9, 1, 3},
                   {9, 3, 1},
                   {1, 9, 3},
                   {3, 9, 1},
                   {1, 3, 9},
                   {3, 1, 9}};

// �� N �� 
// ���� ���� �ٷ궧 `����ü` ����ϴ� ��� 
struct HP {  
    int o, s, t;
};


void back(int one, int second, int third) {

    hp[one][second][third] = 1;                 // ù �湮 ��
    queue<HP> q;                                // ����ü�� Ÿ�� ����
    q.push({one, second, third});

    while (q.size()) {
        int co = q.front().o;
        int cs = q.front().s;
        int ct = q.front().t;
        q.pop();

        if (hp[0][0][0]) break;                 // ���� ����

        for (int i = 0; i < 6; i++) {
            int no = max(0, co - direc[i][0]);  // ���� ������ ������ �ʵ��� 
            int ns = max(0, cs - direc[i][1]);
            int nt = max(0, ct - direc[i][2]); 

            if (hp[no][ns][nt]) continue;       // �ش� ���� �������� �ִٸ� pass

            hp[no][ns][nt] = hp[co][cs][ct] + 1;
            q.push({no, ns, nt});
    }
}


```

# 12851

1. ������ for��

��� for���� ������ �� �� ������ ���� ����� ����

``` cpp
for(int next : {cur-1,cur+1,cur*2}){    

    if(next >= 0 && next < max_val){

    }

}

```

2. �湮 �� ��� ��Ŀ����

* a�� ���� ���� ���: 3
* b�� ���� ���� ���: 4
* c�� ���� ���� ���: 5

a,b,c ���� ��� d������ �� �� �ִٰ� �Ҷ�
* d�� ���� ���� ���: 3 + 4 + 5 �� 


``` cpp
int visited[max_val];  // �ּ� �湮 depth 
int val[max_val];      // depth�� �湮�� ��� ����

if(!visited[next]){                    // ó�� �湮������
    visited[next] = visited[cur] + 1 ; // �ִ� �Ÿ�
    val[next] += val[cur];             // ù �湮�ÿ��� ���� ��� ������ ����
    q.push(next);

}else if(visited[next] == visited[cur] + 1){ // �湮������, �ٸ� ����� ��
    val[next] += val[cur];                   // 
}
```

# 13913

���� Trace_Back
`prev[next] = here`

``` cpp
const int max_len = 200004;
int visited[max_len] , prev[max_len];  // prev �迭 ����

while (q.size()) {          
    prev[next] = cur;  
}

for(int i = K; i != N; i = prev[i]){   // for������ �������ϴ� ���
        v.push_back(i);
}

v.push_back(ret);
```

# 17071

## �÷��̵� �˰��� ( bfs�� ���� ���ο� ���� )

q�� �Ϲ����� ���°� ������ ���� ��

``` cpp
queue<int> q;
    visited[0][N] = 1;  // 0�� �� N ��ġ
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

�ܰ�(depth)���� ����ϵ��� �� ���� �ִ�.
�� ����ó�� �ܰ躰 3��쾿 �����Ǵ� ��쿡�� 
�� �ܰ迡 �ش� �ϴ� Ƚ����ŭ q�� Ȯ���ϴ� ���̴�
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


## ��������...
``` cpp
 while (q.size()) {
        int cur = q.front().first;
        int turn = q.front().second;
        int kpos = K + turn * (turn + 1) / 2;  // K+1+2+3+4 �� �����ϴ� ��...
 }
```

# 14497

## 2���� ��ǥ 1�������� ǥ���ϴ� ���

``` cpp
q.push(1000*jrow + jcol);

while(q.size()){
    int crow = q.front() / 1000;
    int ccol = q.front() % 1000;
}

```

## ť 2��
Ư�� ������ �������� ���ο� ť�� �ְ� -> ���� ť�� ��ü�ϸ鼭 ���� �ܰ踦 ǥ���ϴ� ��

* 0�� ���� �ܰ��̰�, 1�� ������ ��ġ�� �����Ѵ�.
* ���� �ܰ�� �����س��Ҵ� 1�� ��ġ���� �����Ѵ�.

``` cpp
queue<int> q;           // ���� �ܰ� ��ġ ����� 

while (graph[trow][tcol] != '0') {  // �������� 
    cnt++;             // �ܰ�
    queue<int> temp;   // ���� �ܰ� ��ġ ����� 

    while(q.size()){

        if(graph[nrow][ncol] != '0'){           // ���� �ܰ�
            temp.push(1000 * nrow + ncol);
        }else {                                 // ���� �ܰ�
            q.push(1000 * nrow + ncol); 
        }

    }

    q = temp;          
}
```


# 3197

## ������ �ܼ�ȭ �� �ʿ䰡 �ִ�.

* ( �ܼ�ȭ ) ���� 2���� �����δ� -> ���� 1���� �ٸ� ���� ������ �̵��Ѵ�

## �÷��̵� ��?
* qsize = q.size()
* ť 2�� : Q , tempQ �� �̿� �� `Q = tempQ` �� �ٲ�

## Q ���� ���

``` cpp
// 1. �� ����� �� ȿ�����̴�.
void Qclear (queue<pair<int,int>> &q){ // ���� ���� 
    queue<pair<int,int>> empty;
    swap(q, empty);
}

// 2.
while(q.size()) q.pop();
```
