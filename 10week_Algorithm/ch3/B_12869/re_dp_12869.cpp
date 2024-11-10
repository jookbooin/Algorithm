#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int dp[64][64][64];
int hp[3];
int n;

struct AA{
    int a,b,c;
};

vector<AA> av = {{9,3,1}, {9,1,3}, {3,9,1}, {3,1,9}, {1,9,3},{1,3,9}};

int go(int a, int b, int c) {

    // 종료 조건
    if(a<=0 && b <=0 && c<=0 ){
        return 0;
    }
    
    int& ret = dp[a][b][c];
    if(ret != INF) return ret; // 메모제이션 

    for(AA t : av){
        int na = max(0, a-t.a);
        int nb = max(0, b-t.b);
        int nc = max(0, c-t.c);
        ret = min(ret, go(na, nb, nc) + 1 );
    }

    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    fill(&dp[0][0][0], &dp[0][0][0] + 64 * 64 * 64, INF);

    for (int i = 0; i < n; i++) {
        cin >> hp[i];
    }

    cout << go(hp[0],hp[1],hp[2]) << endl;

    return 0;
}