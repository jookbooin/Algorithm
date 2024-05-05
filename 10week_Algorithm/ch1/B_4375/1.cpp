/**
 * 2와 5로 떨어지지 않는 정수 n (10000)
 * 각 자리수가 모두 1로만 이루어진 n의 배수를 찾는 프로그램
 *
 * 3 - 111
 * 7 - 1111111
 */
#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
int n; // 10000 까지 제한 

int main() {
    while (scanf("%d", &n) != EOF) {
        int cnt = 1, ret = 1;
        while (true) {
            if (cnt % n == 0) {
                printf("%d\n", ret);
                break;
            } else {
                cnt = ((cnt * 10) + 1) % n; // 계속 해서 커질 수 있다.
                ret++;
            }
        }
    }
    return 0;
}
