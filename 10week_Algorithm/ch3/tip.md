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
