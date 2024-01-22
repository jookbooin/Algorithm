/**
 * 연속적인 며칠 동안의 온도의 합이 가장 큰 값을 계산하는 프로그램
 *
 * N = 100 000
 * K = 연속적인 날짜의 수
 *
 * 연속의 온도의 합 ==> "최대" 되는 값  = 구간합
 *
 */

#include <bits/stdc++.h>

using namespace std;

int N, K, input, psum[100004];
int result = -10000004;

int main(void) {
    //
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //

    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> input;
        psum[i] = psum[i - 1] + input;
    }

    // psum[1] psum[2] psum[3] psum[4] ... psum[N]
    for (int i = K; i <= N; i++) {
        result = max(result, psum[i] - psum[i - K]);
    }

    cout << result << '\n';

    return 0;
}
