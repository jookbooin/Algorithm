#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int INF = 987654321;

typedef struct info{
    int time,pay;
} info;

int n, k;
info w[104], b[104];
int dp[104][100004];

int go(int here, int time){
    if(here == n) return 0;
    int& ret = dp[here][time];
    if(ret) return ret;
    ret = -1e6;

    // w
    if(time - w[here].time >= 0){
        int val = go(here + 1, time - w[here].time) + w[here].pay;
        ret = max(ret, val);
    }

    // b
    if(time - b[here].time >= 0){
        int val = go(here + 1, time - b[here].time) + b[here].pay;
        ret = max(ret, val);
    }

    return ret;
}

int main(){
    cin >> n >> k;
    for(int i = 0; i<n; i++){
        cin >> w[i].time >> w[i].pay >> b[i].time >> b[i].pay;
    }

    return 0;
}