/**
 * 자두는 1번 나무에 위치하고 있다.
 * t : 1000 초
 * w : 30 ( 최대 움직이는 )
 * idx : ( 1, 2 ) 현재 위치
 */

#include <bits/stdc++.h>

using namespace std;

/**
 * dp[i][j][k]: i초에, j번 나무에 있을 때, k번 나무를 이동한 경우의 최대 과일 수
 * 
 * i: 시간 (1 ~ t)
 * j: 현재 자두 위치 (0: 1번 자두, 1: 2번 자두)
 * k: 이동한 횟수 (0 ~ w)
 */

int dp[1004][2][34];
int loc[1004];

int t, w, num;

int main() {
    cin >> t >> w;

    for (int i = 1; i <= t; i++) {
        cin >> loc[i];
    }

    for (int j = 0; j <= w; j++) {  // j번 위치 변경
        for (int i = 1; i <= t; i++) {

            if (j == 0) { // 위치 변경 x
                
                // 위치변경을 하지 않는다면, 항상 1번에만 위치한다.
                dp[i][0][j] = dp[i - 1][0][j] + (loc[i] == 1); 
            
            } else { // 위치 변경 O

                // 자두 1번에서 받을 때
                dp[i][0][j] = max(dp[i - 1][0][j] + (loc[i] == 1), dp[i - 1][1][j - 1] + (loc[i] == 1));

                // 자두 2번에서 받을 때
                dp[i][1][j] = max(dp[i - 1][1][j] + (loc[i] == 2), dp[i - 1][0][j - 1] + (loc[i] == 2));
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j <= w; j++) {

            // t초에 위치한 값으로 계산
            ans = max(ans, dp[t][i][j]);
        }
    }

    cout << ans << '\n';
    return 0;
}
