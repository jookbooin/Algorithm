/**
 * 
 * <입력>
 * - 좌석 개수
 * - 고정석 개수
 * - 고정석 번호 m 개
 * 
 *  a-1, a, a+1 가능 
 */

#include <bits/stdc++.h>

#define prev ff
#define cur ff

using namespace std;

typedef long long ll;

ll n, m, a, prev = 0, sum = 1 ;
vector<int> v;

ll dp[44];

int main(){

    cin >> n >> m;
    
    dp[1] = 1;
    dp[2] = 2;

    for(int i = 0; i< m; i++){
        cin >> cur;
        v.push_back(cur -prev - 1);
        prev = cur;
    }

    for(int i = 3; i<=40; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }

    for(auto i : v){
        sum *= dp[i];
    }


    cout << sum << endl;
    return 0;
}