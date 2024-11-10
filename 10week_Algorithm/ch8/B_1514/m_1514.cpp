/***
 * n개 
 * 0 ~ 9 : 10개
 * 
 * - 최대 3칸 시계 or 반시계 
 * - 최대 3개의 인접한 디스크 
 * 
 * 
 * 1. 어떤 조건에 n칸 돌리는지 
 * 
 * <조건>
 * 1. 모두 같을 때
 * 2. 1개 다를 때
 * 3. 2개 다를 때
 * 
 * 
 * < flag > 
 * 0 : 반시계 방향 → -1 
 * 1 : 시계 방향 -> 1 
 */

#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int dp[104][14][14][14][4];

int ans[104], in[104];
int n;
string in_str, ans_str;

int mod(int cur){
    return (cur < 0) ? cur + 10 : cur % 10;
}

int go(int idx, int a, int b, int c, int flag){

    if(idx == n) return 0;
    
    int& ret = dp[idx][a][b][c][flag];
    if(ret != -1) return ret;
    ret = INF; 

    // a가 정답이 되었을 때
    if(mod(a + in[idx]) == ans[idx]){
        int f = go(idx + 1, b, c, 0, 0);
        int s = go(idx + 1, b, c , 0, 1);
        ret = min(f, s);
        return ret;
    }

    int _flag = flag ? 1 : -1;

    // 경우의 수 9가지 >> 모두 같은 depth 
    for(int i = 1; i <= 3; i++){  
        // a
        ret = min(ret, 1 + go(idx, mod(a + i * _flag) , b, c, flag));
        // a b
        ret = min(ret, 1 + go(idx, mod(a + i * _flag) , mod(b + i * _flag), c, flag));
        // a b c 
        ret = min(ret , 1 + go(idx, mod(a + i * _flag) , mod(b + i * _flag), mod(c + i * _flag), flag));
    }

    return ret;
}

int main(){
    cin >> n;
    cin >> in_str;

    for(int i = 0; i<n; i++){
        in[i] = in_str[i] - '0';
    }

    cin >> ans_str;
    for(int i = 0; i<n; i++){
        ans[i] = ans_str[i] - '0';
    }

    memset(dp, -1, sizeof(dp));

    // 시계 방향
    int f = go(0,0,0,0  ,0);

    // 반시계 방향으로 돌릴때                                 
    int s = go(0,0,0,0, 1);

    cout << min(f, s) << endl;

    return 0;
}