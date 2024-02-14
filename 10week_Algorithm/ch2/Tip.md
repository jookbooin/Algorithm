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

### 1. �پ��ִ� ���·� �Է¹��� ��

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

# 2910

### 1. ���� comparator(Ŀ���� �� �Լ�)

�⺻ ������ `���� ���� `, �߰����� ���� ������ �ֱ����ؼ��� sort�� ����° ���ڿ� `comparator`�� �������ָ� �ȴ�.

``` cpp
// ��������
sort(b, b + 5);
sort(a.begin(), a.end(), less<int>());

 // ��������
 sort(b, b + 5, greater<int>());
```

pair�� �̿������� `first`, `second` �� ���� �ٸ� ���� ������ �� �� �ִ�.

``` cpp
bool cmp (pair<int,int> a, pair<int,int> b){
    return a.first > b.first   // first�� �������� 
                               // second�� �������� ( �⺻ )
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

map�� key ���� ���� ����������� �ڵ� ���ĵȴ�.
`value` ���� �������� �����ϱ� ���ؼ��� `vector`�� ��ȯ�� �� `pair`���� ����� ����ؾ��Ѵ�.


# 4659

### 1. ���ԵǾ� �ִ��� Ȯ�� 

* vector - find

``` cpp
// vector ���� 
vector<char> cv{'a', 'e', 'i', 'o', 'u'};

for (int i = 0; i < input.size(); i++) {
            auto it = find(cv.begin(), cv.end(), input[i]);

            if (it != cv.end()) {  // ���� �϶�

            }else {                // ���� �϶�

            }
}
```
* �Լ�
�Լ��� �̿��ؼ� `bool` ������ `���ԵǾ� �ִ��� �ȵǾ� �ִ���` �Ǻ��� �� ����.
``` cpp
bool isVowel(int idx) {
    return (idx == 'a' || idx == 'e' || idx == 'i' || idx == 'o' || idx == 'u');
}

 for (int i = 0; i < s.size(); i++) {
            int idx = s[i];
            if (isVowel(idx)){}  // ����
            else{}               // ���� x
 }
```

### 2. char �� int �ƽ�Ű �ڵ� 
c, c++ ������ ���� ����ȯ�� �ڿ������� �Ǵµ�
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

### Tip : ���� �ܰ� �����ϱ�

``` cpp
// 1. i-1 �� i �ε��� ��
for(int i = 0 ; i < input.size() ; i++){
    if(input[i - 1] == input[i])
}

// ���� prev ���� 
int prev = -1;
for(int i = 0 ; i < input.size() ; i++){
    int ascii = input[i];
    if(i > 0 && prev == ascii){}

    prev = ascii;  // ���� ���ڸ� prev ������ ���� 
}
```

# 2870

## 1. ret.front()
string.front() �� ����ϱ� ���ؼ��� `string.size()`�� ���� `�� ���ڿ��� �ƴ�`�� ���� Ȯ���ؾ� �Ѵ�.

``` cpp
if(ret.size() && ret.front() == '0'){  
    ret.erase(0,1);
}
```

## 2. �ڸ��� 

* int : 9 �ڸ�
* long long : 18�ڸ�
* ���Ŀ��� `string`���� ��� ������ �ؾ��Ѵ�.

## 3. ���ڿ� -> int ���� + Ŀ���� ����

* �������� : a < b ( true )
  �������� : a > b ( true )

* ���ڿ� �񱳴� �ƽ�Ű �ڵ带 ������� ������ �ϱ� ������ `"222"` , `"1234"` �� ���� ���ڿ��� ���ϱ� ���ؼ��� size �� ���ؾ��Ѵ�.

``` cpp
bool cmp(string a, string b){
    if(a.size() == b.size()) return a < b;

    return a.size() < b.size();
}
```

## 4. �ƽ�Ű �ڵ� 65 97
* A : 65    | Z : 90 

* a : 97    | z : 122

* 0 : 48

# 2852

## 1. ���ڿ� -> ����
* c��Ÿ�� : `atoi(ti.substr(0, 2).c_str())`
* c++ ��Ÿ�� : `stoi(ti.substr(0, 2))`

## 2. �ð��� ����ϴ� ����..
* total : hour => min*60 => sec*60*60

## prev 
�������� �����ϱ� ���ؼ� ��� 
������ ��ġ�� �������� `define` ���
``` cpp
#define prev hihi
```

# 9012

## 1. stack 

``` cpp
stack <int> stk;

stk.push(1);

stk.pop();      // ���� ���� �ִ� ��� ����

stk.top();      // ���� ���� �ִ� ��� Ȯ��

stk.size();

stk.empty()     // ����ִ��� Ȯ���� �� ����.
```


# 14502

## 2���� �迭�� �� ���� �����ϴ� ���� ���� �ƴϴ�.

��ǥ���� �������� 
* ���̷��� ��ǥ
* �� ��ǥ

``` cpp
for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            cin >> graph[row][col];
            if (graph[row][col] == 2) virusList.push_back({row, col});
            if (graph[row][col] == 0) wallList.push_back({row, col});
        }
    }
```

## �迭 ���� 

* STL �����Լ� copy
``` cpp
// ������ => graph_copy �� ���� 
copy(&graph[0][0], &graph[0][0] + 10 * 10, &graph_copy[0][0]);
```

* ���� �Լ� 
``` cpp
void copyArr(int tmp[10][10], int a[10][10]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < M; col++) {
            tmp[row][col] = a[row][col];
        }
    }
}
```

## 3���� �����ϴ� ��� = ���� 


* 3�� for�� 
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

* ��� 

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

## 1. tree �� root ���� ������ ����.
``` cpp
 dfs(root)
```

## 2. Ʈ�� ���� ���¹� (�ϱ�)
``` cpp
int dfs(int idx){
    int child = 0;
    int ret = 0;
    for(int a : tree[idx]){
        if(a == ers) continue;

        ret += dfs(a);  // ���� �ڽ� ��� ������ ��ͷ� ���Ѵ�
        child ++;
    }

    if(child == 0)  // ���� ����� ��
        return 1;
}
```

## 3. vector ����

* 2���� �迭 : vector<vector<int>> vec2
* ���� ����Ʈ : vector<int> tree[10];


# 1325

## 1068 Ʈ������ ���¹� + �ڽ� ���� ����
``` cpp
int dfs(int idx) {
    visited[idx] = 1;
    int ret = 1;  //  ���� ���
    for (int a : tree[idx]) {
        if (visited[a]) continue;
        ret += dfs(a);      // + �ڽĵ�
    }
    
    return ret;
}
```

# 17298 

## ¦���� ���� : stack�� �켱 �����غ���

stack�� top�� `st.size()` , `!st.empty()` �� �Բ� �����

* �տ��� ���� ��� ( sol_17298 )

``` cpp
 for (int i = 0; i < N; i++) {
        while (st.size() && val[st.top()] < val[i]) {  // st�� ������� �ʾƾ� top Ž������
            ret[st.top()] = val[i];
            st.pop();
        }
        st.push(i);
    }
```

* �ڿ��� �� ���� ���� m17298


## �ʱ�ȭ �ϴ� ����� memset, fill ���
``` cpp
memset(ret, -1, sizeof(ret));
```

