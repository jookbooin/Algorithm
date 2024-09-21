#include <bits/stdc++.h>

using namespace std;

int a, b;

double pa, pb;
int sosu[] = {2,3,5,7,11,13,17};
double dp[22][22][22] ;

double  go(int round, int a, int b){
    if(round == 18){ // 90분 지났을 때
        // 소수라면 
        for(int c : sosu){
            if(a == c || b == c){
                return 1.0;
            }
        }

        
        return 0.0;
    }

    if(dp[round][a][b]) return dp[round][a][b];

    dp[round][a][b] += go(round + 1, a,b) * (1-pa) * (1-pb);
    dp[round][a][b] += go(round + 1, a + 1,b) * pa * (1 - pb);
    dp[round][a][b] += go(round + 1, a,b + 1) * (1 - pa) * pb;
    dp[round][a][b] += go(round + 1, a + 1,b + 1) * pa * pb;

    return dp[round][a][b];

}

int main() {
    cin >> a >> b;

    pa = (double)a / 100;
    pb = (double)b / 100;

    cout << go(0,0,0) << '\n';

    return 0;
}