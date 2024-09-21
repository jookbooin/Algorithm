/**
 * 한팀이 골을 소수로 득점할 확률
 * 90분 -> 경기 5분씩 나눔 -> 18번?
 * a 팀 득점할 확률,
 * b 팀 득점할 확률
 *
 * 적어도 한팀이 골을 소수로 득점할 확률
 * 소수 : 2, 3, 5, 7, 11, 13, 17
 * 최대 18점 득점할 수 있음
 *
 * 두팀은 각각 많아야 한골 득점할 수 있다 -> round 정보 필요?
 * (0,0)
 * (1,0)
 * (0,1)
 * (1,1)
 *
 *
 *
 */

#include <bits/stdc++.h>

using namespace std;

int a, b;

double pa, pb;
double dp[22][22][22];

void go(int round, int aa, int bb, int type) {
    if (round > 18) return;

    if (aa == 0 && bb == 0) {
        dp[0][0][0] = 1.0;
    } else {
        if (type == 0) {
            dp[round][aa][bb] += dp[round - 1][aa][bb] * (1 - pa) * (1 - pb);
        } else if (type == 1) {
            dp[round][aa][bb] += dp[round - 1][aa - 1][bb] * pa * (1 - pb);
        } else if (type == 2) {
            dp[round][aa][bb] += dp[round - 1][aa][bb - 1] * pb * (1 - pa);
        } else if (type == 3) {
            dp[round][aa][bb] += dp[round - 1][aa - 1][bb - 1] * pa * pb;
        }
    }
    // 이번 라운드
    go(round + 1, aa, bb, 0);          // aa, bb
    go(round + 1, aa + 1, bb, 1);      // aa*pa, bb
    go(round + 1, aa, bb + 1, 2);      // aa, bb*pb
    go(round + 1, aa + 1, bb + 1, 3);  // aa * pa, bb * pb
}

bool check(int r, int c){
    if(r == 2 || r == 3 || r==5 || r == 7 || r == 11 || r == 13 || r == 17) return true;
    if(c == 2 || c == 3 || c==5 || c == 7 || c == 11 || c == 13 || c == 17) return true;

    return false;
}

int main() {
    cin >> a >> b;

    pa = (double)a / 100;
    pb = (double)b / 100;

    // memset(dp, -1, sizeof(dp));
    go(0, 0, 0, 0);

    double ans_sum = 0.0;

    for(int i =0; i<=18; i++){
        for(int j =0; j<=18; j++){
            // i 랑 j 둘중 하나라도 소수라면?
            if(check(i,j)){
                ans_sum += dp[18][i][j];
            }
        }
    }

    cout << ans_sum << '\n';

    return 0;
}
