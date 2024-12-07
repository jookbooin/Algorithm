/***
 * 연속된 소수의 합으로 나타낼 수 있는지 확인 
 * 7 (11) 13
 * 소수는 반드시 한번만 덧셈에 사용될 수 있다.
 * 
 * n = 400만 
 * 
 * 반드시 `연속된` 소수의 합으로 나타내야 한다
 * 1. 소수 판단 (에스토스테레스 체 )
 * 2. 소수 합?
 * 
 */

#include <bits/stdc++.h>

using namespace std;

int n;

bool check(int n){
    if(n <= 1) return 0;
    if(n == 2) return 1;
    if(n % 2 == 0) return 0;
    for(int i = 3; i * i <= n; i++){
        if(n % i == 0) return 0;
    }

    return 1;
}

int main(){
    cin >> n;
    vector<int> v;

    for(int i = 1; i<=n; i++){
        if(check(i)){
            v.push_back(i);
        }
    }

    for(int a : v){
        cout << a << " ";
    }

    // v 소수 집합

    int sp = 0, ep = 0, sum = 0, cnt = 0;

    while(1){
        
        if(sum >= n){
            sum -= v[sp];
            sp++;
        } else if(ep == v.size()){
            break;
        } else { // sum > n
            sum += v[ep];
            ep++;
        }

        if(sum == n) cnt++;
    }

    cout << cnt << '\n';
    
    return 0;
}