#include <bits/stdc++.h>

using namespace std;

int a, b;

double pa, pb;
int sosu[] = {2, 3, 5, 7, 11, 13, 17};
bool isP[20];
double dp[22][22][22];

double go(int round, int a, int b) {
    if (round == 18) {
        return isP[a] || isP[b] ? 1.0 : 0.0; // 조건을 간소화
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

void era(){
    fill(isP, isP + 20, 1);
    isP[0] = 0; isP[1] = 0;  
    for(int i = 2; i <= 20; i++){ 

        // i의 배수 제거
        for(int j = i + i; j <= 20; j += i){
            isP[j] = 0; 
        }
        
    }
}

int main() {
    cin >> a >> b;

    pa = (double)a / 100;
    pb = (double)b / 100;

    // 초기화
    era();
    memset(dp, -1, sizeof(dp));

    cout << fixed << setprecision(10) << go(0, 0, 0) << '\n'; // 소수점 10자리까지 출력

    return 0;
}