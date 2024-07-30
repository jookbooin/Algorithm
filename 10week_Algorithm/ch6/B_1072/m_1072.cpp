/**
 *  x 
 *  y = 10억
 *  
 * (y/x) * 100 했을 때 몇번을 더해야 z가 변하는지 
 * z가 절대 변하지 않는다면 -1
 * 
 * 
 * ( y+1 ) / ( x+1 )
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll ;
const int rmax = 1000000000;
ll x, y,z,ans = rmax;
bool flag = false;

bool check(int m){
    ll val = (y+m)* 100 / (x+m);
    
    if(val > z) return true;
    return false;
}

int main(){
    cin >> x >> y;

    z = y * 100 / x; // 초기 값

    int s = 0, e = rmax;

    while(s <= e){
        ll mid = (s + e) / 2;
        
        if(check(mid)){ // 변했다.
            flag = true;
            ans = min(ans, mid);    
            e = mid - 1;
        }else{ // 변하지 않았다. -> 더 많이 시도해야한다..?
            s = mid + 1;
        }

    }

    if(flag){
        cout << ans<< '\n';
    }else{
        cout << -1 << '\n';
    }

    return 0;
}