#include <bits/stdc++.h>

using namespace std;

int a, b;

double pa, pb;
int sosu[] = {2, 3, 5, 7, 11, 13, 17};
double dp[22][22][22];

bool era(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;

    for (int i = 2; i * i <= n; i++) { // i * i <= n으로 수정
        if (n % i == 0) return false;
    }

    return true;
}

bool check(int a, int b) {
    return era(a) || era(b);
}

double go(int round, int a, int b) {
    if (round == 18) {
        return check(a, b) ? 1.0 : 0.0; // 조건을 간소화
    }

    double& ret = dp[round][a][b];
    if (ret > -0.5) return ret;

    ret = 0.0;
    ret += go(round + 1, a, b) * (1 - pa) * (1 - pb);
    ret += go(round + 1, a + 1, b) * pa * (1 - pb);
    ret += go(round + 1, a, b + 1) * (1 - pa) * pb;
    ret += go(round + 1, a + 1, b + 1) * pa * pb;

    return ret;
}

int main() {
    cin >> a >> b;

    pa = (double)a / 100;
    pb = (double)b / 100;

    // 초기화
    memset(dp, -1, sizeof(dp));

    cout << fixed << setprecision(10) << go(0, 0, 0) << '\n'; // 소수점 10자리까지 출력

    return 0;
}