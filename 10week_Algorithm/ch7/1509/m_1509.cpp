/**
 *
 * 156 2500 0000 : 2500 * 2500 * 2500 = 156억
 * 문자열을 팰린드롬들로 구분해서 분할된 개수가 가장 작은 경우 찾기
 * - 긴 팰린드롬을 찾는다
 *
 * 1 : 1개
 * 2 : [BB]C[DD]ECAECBDABA[DD]CEBA[CCC]BDC[AA]BDBA[DD]
 * 3 : BBCDDECAECBDABADDCEBA[CCC]BDCAA[BDB]ADD
 * 4 : [BB]C[DD]ECAECB[DABAD]DCEBA[CCC]BDC[AA][BDB]A[DD]
 * 16 + 7
 *
 * [QWERTYTREWQ] W E R T : 5
 *
 */

#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;

string str;
int dp[2504][2504] , cp[2504] = {0};
int n, mmin = INF;

int main() {
    cin >> str;
    n = str.size();

    // 1. 각 위치 팰린드롬인지 체크
    // size = 0;
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 1;
    }

    // size = 1;
    for (int i = 1; i <= n; i++) {
        if (str[i-1] == str[i + 1-1]) dp[i][i + 1] = 1;
    }

    // size = 2 이상
    for (int size = 2; size < n; size++) {              // size
        for (int sidx = 1; sidx <= n - size; sidx++) {  // start
            if (str[sidx-1] == str[sidx + size-1] && dp[sidx + 1][sidx + size - 1]) {
                dp[sidx][sidx + size] = 1;
            }
        }
    }

    // 2. 팰린드롬 분리 -> 가장 작게
    fill(cp, cp+2504, INF);
    cp[0] = 0;

    for (int e = 1; e <= n; e++) {
        for (int s = 1; s <= e; s++) {
            if (dp[s][e]) {
                cp[e] = min(cp[e], cp[s - 1] + 1);
            }
        }
    }

    cout << cp[n] << endl;

    return 0;
}
