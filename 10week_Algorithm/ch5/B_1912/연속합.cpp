/**
 * 연속된 수를 선택해서 구할 수 있는 합중 가장 큰 합
 * n = 100000
 * -1000 < 수 < 1000
 * 투포인터 (left, right)
 *  - 언제 left > 
 *  - 언제 right > 하는지..?
 * 
*/

#include <bits/stdc++.h>

using namespace std;
const int INF = 987654321;
int n,a,m = -INF;
int arr[100004];
int dp[100004];
int main(){
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> a;
        if(i == 0) { 
            dp[i] = a;
        } else {
            dp[i] = max(dp[i-1] + a, a);
            
        }
        m = max(m,dp[i]);
    }

    cout << m << endl;
    return 0;
}
