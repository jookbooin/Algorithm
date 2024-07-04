#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
const int pmax = 2000000;
int parr[1004], pbrr[1004];
int dpa[pmax + 4], dpb[pmax + 4];

int ps, m, n, ret = 0;
int asum = 0, bsum = 0;  // a, b 피자 총합

int main() {
    cin >> ps >> m >> n;

    // 피자 입력
    for (int i = 0; i < m; i++) {
        cin >> parr[i];
        asum += parr[i]; 
    }

    for (int i = 0; i < n; i++) {
        cin >> pbrr[i];
        bsum += pbrr[i];
    }

    // dpa 계산
    for (int i = 0; i < m; i++) {  // 시작점
        int dpsum = 0;
        for (int j = 0; j < m-1; j++) {  // 움직이는 i + j)
            dpsum += parr[(i + j) % m];  // 피자 크기
            dpa[dpsum]++;
        }
    }

    // dpb 계산
    for (int i = 0; i < n; i++) {
        int dpsum = 0;
        for (int j = 0; j < n-1; j++) {
            dpsum += pbrr[(i + j) % n];  // 피자 크기
            dpb[dpsum]++;
        }
    }

    // 피자 총합은 1번만 계산
    dpa[asum]++;
    dpb[bsum]++; 

    // 피자크기, 개수 ->  dpa, dpb 완성
    dpa[0] = 1, dpb[0] = 1;
    for (int i = 0; i <= ps; i++) {
        if (dpa[i] && dpb[ps - i]) {
            ret += dpa[i] * dpb[ps - i];
        }
    }

    cout << ret << '\n';
    return 0;
}
