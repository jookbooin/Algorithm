/**
 * 반조각 O
 * 한조각 -> 반조각 O, 반조각 다시 집어 넣음 
 * 
 * 한조각 꺼냈을때 : W
 * 반조각 꺼냈을 때 : H 
 * 
 * 2N일 지났을 때 가능한 문자열의 개수 : 2^(2N)
 * - 병에 들어 있는 약의 개수 
 */

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll n;
ll dp[34][34];

ll dfs(int w, int h){

    if(w==0 && h==0) return 1;

    ll& ret = dp[w][h];
    if(ret) return ret;
    
    if(w > 0){ // 알약 1개 먹음 
        ret += dfs(w-1, h+1);
    }

    if(h > 0){ // 알약 반개 먹음
        ret += dfs(w,h-1);
    }

    return ret;
}

int main(){
    
    while(1){
        cin >> n;
        if(n == 0) break;
        cout << dfs(n,0) << endl;
    }

    return 0;
}