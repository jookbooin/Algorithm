#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;

int mov[14], n = 10;
int mal[4];  // 현재 말의 위치

vector<int> adj[54];
int val[104];

void add(int curIdx, int nextIdx) {
    adj[curIdx].push_back(nextIdx);
}

void setMap() {
    // map 인덱스
    for (int i = 0; i <= 19; i++) add(i, i + 1);  // i+1로 수정
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

    val[1] = 2;
    val[2] = 4;
    val[3] = 6;
    val[4] = 8;
    val[5] = 10;
    val[6] = 12;
    val[7] = 14;
    val[8] = 16;
    val[9] = 18;
    val[10] = 20;
    val[11] = 22;
    val[12] = 24;
    val[13] = 26;
    val[14] = 28;
    val[15] = 30;
    val[16] = 32;
    val[17] = 34;
    val[18] = 36;
    val[19] = 38;
    val[20] = 40;
    val[21] = 13;
    val[22] = 16;
    val[23] = 19;
    val[24] = 25;
    val[27] = 22;
    val[28] = 24;
    val[25] = 30;
    val[26] = 35;
    val[29] = 28;
    val[30] = 27;
    val[31] = 26;
}

int move(int mal_cur_idx, int moveCnt){
    
    if(mal_cur_idx == 100) return 100;

    if(adj[mal_cur_idx].size() >= 2){ // 파란색 위치
        mal_cur_idx = adj[mal_cur_idx][1];
        moveCnt --;
    }
    
    int next_mal_idx;

    if(moveCnt){
        queue<int> q;
        q.push(mal_cur_idx);

        while(q.size()){
            int x = q.front(); q.pop(); // 현재
            next_mal_idx = adj[x][0];  // 다음
            q.push(next_mal_idx);

            if(next_mal_idx == 100) break; // 
            moveCnt--;
            if(moveCnt == 0) break;
        }

        return next_mal_idx;
    }else{
        return mal_cur_idx;
    }

}

bool isMal(int mal_idx){
    if(mal_idx == 100) return false;

    for(int i = 0; i< 4; i++){
        if(mal[i] == mal_idx) return true;
    }
    return false;
}

int go(int depth){
    if(depth == 10) return 0;
    int ret = 0;
    for(int i = 0; i< 4; i++){
        int mal_cur_idx = mal[i];
        int moved_mal_idx = move(mal_cur_idx, mov[depth]); // 움직인 결과 
        if(isMal(moved_mal_idx)) continue;

        mal[i] = moved_mal_idx;
        ret = max(ret, go(depth+1) + val[moved_mal_idx]);
        mal[i] = mal_cur_idx;

    }

    return ret;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    setMap();
    for (int i = 0; i < n; i++) cin >> mov[i];

    cout << go(0) << "\n";
    return 0;
}
