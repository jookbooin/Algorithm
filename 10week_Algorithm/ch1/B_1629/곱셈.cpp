#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll a, b, c;

/**
 * b가 너무 큼
 * dp, 이분탐색, 분할 정복
 *
 * 1. for 문
 * 2. 재귀/분할 정복
 * 8 = 4 * 4
 * 4 = 2 * 2
 * 2 = 1 * 1
 *
 * 7 = 3 * (3 + 1 )
 * 3 = 2 * 1
 */

int go(int k, int n) {
    if (n == 1) return k % c;

    ll result = go(k, n / 2);       // 절반 값
    result = (result * result) % c; // 원본 값 

    if (n % 2 == 1)                 // 홀 수 일때
        result = (result * a) % c;

    return result;
}

int main() {
    cin >> a >> b >> c;

    cout << go(a, b) << '\n';

    return 0;
}
