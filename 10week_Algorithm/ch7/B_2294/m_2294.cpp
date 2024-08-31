/**
 * 동전 종류 : n ( 100 )
 * 가치 합 : k   ( 10000 )
 * 동전 개수가 최소가 되도록
 *
 * 각각의 동전은 몇개라도 사용할 수 있다.
 * 가치가 같은 동전이 여러번 주어질 수 있다 -> set?
 *
 * 합 dp
 * 동전 크기 arr, vector
 * 동전
 */

#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
int dp[10004];
int n, k, input;
vector<int> dv;

void make(int val) {
    if (dp[val] == 1) return;
}

int main() {
    cin >> n >> k;
    
    fill(&dp[0], &dp[0] + 10004, INF);

    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> input; // 코인 

        for(int i = input; i<= k; i++){
            dp[i] = min(dp[i], dp[i - input] + 1);
        }

    }

    if(dp[k] == INF){
        cout << -1 << '\n';
    }else{
        cout << dp[k] << '\n';
    }

    return 0;
}
