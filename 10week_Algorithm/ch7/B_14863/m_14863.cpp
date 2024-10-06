#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 987654321;
int n, k;
typedef struct info{
    int time, pay;
}info;

info w[104], b[104];
ll dp[104][100004];

int go(int here, int time){
    
    // 유효성
    if(time > k) return -INF;

    // 종료 조건 0 ~ n-1
    if(here == n){
        return 0;
    }

    ll& ret = dp[here][time];
    if(ret != -INF) return ret;

    // 현재 w일 경우
    int ww =  go(here+1, time + w[here].time) + w[here].pay;

    // 현재 b일 경우 
    int bb =  go(here+1, time + b[here].time) + b[here].pay;

    ret = max(ww, bb);

    return ret;
}

int main(){
    cin >> n >> k;
    for(int i = 0; i<n; i++){
        cin >> w[i].time >> w[i].pay >> b[i].time >> b[i].pay;
    }

    // dp 초기화 
    fill(&dp[0][0], &dp[0][0] + 104 * 100004, -INF);
    cout << go(0,0) << endl;

    return 0;
}