#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;

int dp[64][64][64];
int hp[3];
int n;

int solve(int a, int b, int c) {
    
    

}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++) {
        cin >> hp[i];
    }

    solve(hp[0],hp[1],hp[2]);

    return 0;
}
