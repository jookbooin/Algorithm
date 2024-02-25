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