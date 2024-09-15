#include <bits/stdc++.h>

using namespace std;

int n, ret = 0;
int lose[24], joy[24], dp[104];


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
        for(int j = lose[i] + 1; j<=100 ; j++){
            dp[j] = max(dp[j], dp[j - lose[i]] + joy[i]);
        }
    }


    cout << dp[100] << endl; // 최대 기쁨 출력
    return 0;
}
