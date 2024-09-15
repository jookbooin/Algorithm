#include <bits/stdc++.h>

using namespace std;

int n, ret = 0;
int lose[24], joy[24], dp[24][104];


int main() {
    cin >> n;
    
    // 체력
    for (int i = 0; i < n; i++) {
        cin >> lose[i];
    }

    // 기쁨
    for (int i = 0; i < n; i++) {
        cin >> joy[i];
    }

    for(int i = 1; i<= n; i++){
        for(int j = 100; j>= lose[i]; j--){
                          // 넣지 않을 때, 넣을 때
            dp[i][j] = max(dp[i-1][j], joy[i] + dp[i-1][j - lose[i]]);
        }
    }

    cout << dp[n][100] << endl; // 최대 기쁨 출력
    return 0;
}
