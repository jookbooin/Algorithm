#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;

int a[14],  n = 10;
int mal[4]; // 현재 말의 위치

vector<int> adj[54];
int v[104];

void add(int here, int there) {
    adj[here].push_back(there);
}

void setMap() {
    // map 인덱스
    for (int i = 0; i <= 19; i + 1) add(i, i + 1);
    add(5, 21);
    add(21, 22);
    add(22, 23);
    add(23, 24);
    add(15, 29);
    add(29, 30);
    add(30, 31);
    add(31, 24);
    add(10, 27);
    add(27, 28);
    add(28, 24);
    add(24, 25);
    add(25, 26);
    add(26, 20);
    add(20, 100);

    v[1] = 2;
    v[2] = 4;
    v[3] = 6;
    v[4] = 8;
    v[5] = 10;
    v[6] = 12;
    v[7] = 14;
    v[8] = 16;
    v[9] = 18;
    v[10] = 20;
    v[11] = 22;
    v[12] = 24;
    v[13] = 26;
    v[14] = 28;
    v[15] = 30;
    v[16] = 32;
    v[17] = 34;
    v[18] = 36;
    v[19] = 38;
    v[20] = 40;
    v[21] = 13; v[22] = 16; v[23] = 19;  v[24] = 25; 
    v[27] = 22; v[28] = 24; v[25] = 30; v[26] = 35;
    v[29] = 28; v[30] = 27; v[31] = 26;

}

int move(int here, int moveCnt){
    if(here == 100) return 100;

    if(adj[here].size() >=2){
        here = adj[here][1];  // 파란쪽으로 이동
        moveCnt --;
    }

    if(moveCnt){
        queue<int> q;
        q.push(here);
        int there;
        while(q.size()){
            int x = q.front(); q.pop();
            there = adj[x][0]; // idx
            q.push(there);
            
            if(there == 100) break; // 도착
            moveCnt--;
            if(moveCnt == 0) break; // 횟수 끝
            
        }

        return there;
    }else{
        return here; 
    }
}

bool isMal(int mal_idx){
    if(mal_idx == 100) return false;
    for(int i = 0; i<4 ; i++){
        if(mal_idx == mal[i]) return true;
    }
}

int go(int here){
    if(here == 10) return 0;
    int ret = 0;
    for(int i =0; i< 4; i++){
        int temp_idx = mal[i]; // 현재말 위치
        int mal_idx = move(temp_idx, a[here]); 

        if(isMal(mal_idx)) continue;
        
        mal[i] = mal_idx;
        ret = max(ret, go(here + 1) + v[mal_idx]);
        mal[i] = temp_idx;

    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);setMap(); 
	for(int i = 0; i < n; i++) cin >> a[i]; 

	cout << go(0) << "\n"; 
    return 0;
}
