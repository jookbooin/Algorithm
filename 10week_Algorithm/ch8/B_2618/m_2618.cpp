/**
 * 2대의 경찰차
 * - 경1 : (1, 1)
 * - 경2 : (n, n)
 * 
 * 2개의 사건이 `발생한 순서대로` 2개의 경찰차에 맡긴다.
 * 두 대의 경찰차가 이동하는 거리의 합을 최소화 
 * 
 * <출력>
 * - 총 이동거리
 * - i번째 사건에 맡겨진 경찰차 번호 (1 ~ n)
 * 
 *
 * ar, ac, br, bc 저장 
 * 
 * 
 * 
 */
#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
int n, w, a, b;
int dp[1004][1004]; // 최솟값
int dist[1004];      // 경찰차 1, 2 저장 용도 
vector<pair<int,int>> v(1004);

// idx 차이값
int val(int prev, int next){
    return abs(v[prev].first - v[next].first) + abs(v[prev].second - v[next].second);
}

int go(int aidx, int bidx){ 

    // 마지막 사건 번호 w + 1
    if(aidx == w + 1 || bidx == w + 1){
        return 0; // 초기화
    }

    int& ret = dp[aidx][bidx];
    if(ret != -1) return ret;
    ret = 0;

    // 다음 사건 번호
    int next = max(aidx, bidx) + 1;

    // a로 갈 때
    int aret = go(next, bidx);
    int aval = val(aidx, next);

    // b로 갈 때
    int bret = go(aidx, next);
    int bval = val(bidx, next); 
    
    ret = min(aret + aval, bret + bval);
    
    return ret;
}

int main(){
    cin >> n >> w;

    v[0] = {1, 1}; // a의 위치
    v[1] = {n, n}; // b의 위치

    // 사건 : [2, w+1]에 위치
    for(int i = 2; i<= w+1 ; i++){
        cin >> a >> b;
        v[i] = {a,b};
    }

    memset(&dp[0][0], -1, sizeof(dp));

    // 사건 최솟값 
    cout << go(0,1) << endl; 

    // trace
    int a = 0, b = 1;
    for(int i = 2; i< w + 2; i++){
        if(dp[i][b] + val(a,i) < dp[a][i] + val(b,i)){ // a
            cout << 1 << endl;
            a = i;
        }else{ // b
            cout << 2 << endl;
            b = i;
        }
    }

    return 0;
}