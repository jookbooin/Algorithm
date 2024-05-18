/**
 * n = 400 0000    , O(N)
 * 연속된 소수의 합
 *
 * 소수 : 3 5 7 11 13 17 19 23 29
 * 41 = 3 5 7 11 13 17
 *
 * n 입력 - n까지의 소수
 *
 * 1. n까지 소수들 list 알아야 함
 * 2. 합 -> dp ?
 * 3.
 */

#include <bits/stdc++.h>

using namespace std;

int n, idx = 1, cnt = 0;
int dp[4000004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    // 1. 가능한 소수
    vector<bool> isPrime(n + 1, 1);     // n+1 요소 1로 채움
    for (int i = 2; i * i <= n; i++) {  // i가 n의 제곱근까지 증가
        if (isPrime[i] == 0) continue;
        for (int j = i * 2; j <= n; j += i) {  // 
            isPrime[j] = 0;
        }
    }

    vector<int> prime;
    int idx = 1;
    // 2. 소수 모음
    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            prime.push_back(i);
        }
    }

    int s = 0, e = 0, sum = 0;
    while(1){
        if(sum >= n){
            sum -= prime[s];
            s++;
        }else if(e == prime.size()){ // 넘는 경우
            break;
        }else{          // sum < n
            sum += prime[e];
            e++;
        }

        if(sum == n) cnt ++;
    }

    cout << cnt << '\n';
    return 0;
}