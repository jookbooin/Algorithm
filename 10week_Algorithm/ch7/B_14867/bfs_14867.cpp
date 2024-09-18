/**
 * a b          : 100 000
 * 최종 : c d
 * 
 * F(x) : x 전부 채움
 * E(x) : x 전부 비움
 * M(x,y) : x를 y로 이동
 * 
 * [3, 7]
 * 
 * 0 7
 * 3 4
 * 0 4
 * 3 1 
 * 0 1 
 * 1 0 
 * 1 7
 * 3 5
 * 0 5
 * 3 2
 
 <경우의 수>
    - F(A), F(B), E(A), E(B), M(A,B), M(B,A)

    - 순환 확인 방법 ? 
    - 이미 수 존재하면 return 
 */

#include <bits/stdc++.h>

using namespace std;

int a,b,c,d;

map<pair<int,int>, int> mp;
queue<pair<int,int>> q;

void enque(int ca, int cb, int depth){
    
    // 0이 아닌 값이 있다면?
    if(mp[{ca, cb}]) return;
    mp[{ca,cb}] = depth + 1;
    q.push({ca, cb});
}

void bfs(){
    
    mp[{0,0}] = 1;
    q.push({0,0});
    int ca, cb;

    while(q.size()){
        tie(ca, cb) = q.front();
        q.pop();

        int depth = mp[{ca,cb}];

        // F(A)
        enque(a, cb, depth);
        // F(B)
        enque(ca, b, depth);
        // E(A)
        enque(0, cb, depth);
        // E(B)
        enque(ca, 0, depth);

        // M(A,B) : a -> b
        enque(max(ca + cb - b, 0), min(ca + cb, b), depth);

        // M(B,A) : b -> a
        enque(min(ca + cb, a), max(0, ca + cb - a), depth);
    }
}

int main(){

    cin >> a >> b >> c >> d;

    bfs();

    if(mp[{c,d}]){
        cout << mp[{c,d}] << '\n';
    }else{
        cout << -1 << '\n';
    }

    return 0;
}