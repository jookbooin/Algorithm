/**
 * 2 - 1
 * 3 - 7
 * 4 - 4
 * 5 - 5, 3, 2
 * 6 - 9, 6, 0  
 *      - 첫번째로 나올 수 있는 수는 6
 *      - 두번째부터 0 
 * 7 - 8
 * 
 * num[6] = 0;
 * dp[6] = 6;
 * 8 10 
 * 9 18
 * 10 11
 * 11 20
 * 12 28
 * 13 68
 * 14 88
 * 15 108
 */

#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;

// 최솟값 구할 때 사용하는 수
int t, n;
int num[10] = {0,0,1,7,4,2,0,8,10};
long long dp[104]; // 최솟값 

void getmin(){

    // 1 ~ 9
    for(int i = 1; i<9; i++){
        dp[i] = num[i];
    }

    dp[6] = 6;
    
    // 9 ~ 100  
    for(int i = 9; i < 101; i++){
        dp[i] = dp[i-2] * 10 + dp[2];
        for(int j = 3; j < 8; j++){ // 1 7 4 2 6 8
            dp[i] = min(dp[i], dp[i-j]*10 + dp[j]);
        }
    }

}

int main(){

    cin >> t;

    fill(&dp[0], &dp[0] + 104, INF);
    getmin();

    for(int i = 0; i<t; i++){
        cin >> n;

        // 띄어쓰기
        cout << dp[n] <<" ";

        // 2. 최대
        if(n%2 == 0) { // 짝수
            for(int i = 0; i< n/2; i++){
                cout << "1";
            }
        }else{
            cout << "7";
            for(int i = 0; i< (n-3)/2; i++){

                cout << "1";
            }
        }

        cout << endl;
    }

    return 0;
}
