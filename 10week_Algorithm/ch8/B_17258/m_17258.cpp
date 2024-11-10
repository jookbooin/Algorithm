/**
 * <욱제> 
 * t명 미만 : out
 * t명 이상 : in
 * 
 * <영선 친구 k>
 * 1. (욱제 + 영선 친구 제외) 파티 인원 t명 이상이 될 때
 *      - 전부 out 
 * 2. 인원 t명 이상일 때
 *      - 들어가지 않는다.
 * 3. (아직 들어오지 않았을 때) t명 미만
 *      - in
 * 
 * n (시간) : 300
 * m (초대 사람 수 ): 300
 * k (영선 친구): 300
 * t : 300
 * 
 * <출력> 
 * 우제 파티 머무를 수 있게 하는 `최대 시간`
 * 
 * wook 
 * yf 
 * f
 * 
 * 
 */
#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> v;

int f[304]; // 오가는 인원
int dp[304][304];
int n,m,k,t,in,out;
int wook, yf, f, ret = 0, cnt = 0;
vector<pair<int,int>> pv;

int go(int idx, int remain, int cur){
    
    if(idx == n + 1) return 0;
    if(dp[idx][remain]) return dp[idx][remain];

    int cost = max(0, t - f[idx]);
    int add_cost = (remain >= cur) ? remain - cur : 0;

    int& ret = dp[idx][remain];
    if(cost == 0) cur = 0;
    if(remain - add_cost >= 0){
        ret = max(go(idx + 1, remain - add_cost , cost) + 1, go(idx + 1, remain, cur));
    }else{
        ret = go(idx + 1, remain, cur);
    }   

}

int main(){

    cin >> n >> m >> k >> t;

    cin >> n >> m >> k >> t; 
    for(int j = 0; j < m; j++){
        cin >> in >> out; 
        for(int i = in; i < out; i++){
            f[i] = min(t, ++f[i]);
        }
    }

    int temp = f[1]; 
    int _count = 1; 
    for(int i = 2; i <= n; i++){  
        if(temp != f[i]){ 
            v.push_back({_count, temp});  
            _count = 0; 
            temp = f[i];
        }
        _count++;
    }

    go(0,k,0);

    return 0;
}