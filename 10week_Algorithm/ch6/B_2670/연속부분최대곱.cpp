#include<bits/stdc++.h>

using namespace std;

int n;
double ans = 0.0;
double dp[10004];

int main(){
    cin >> n;
    vector<double> v(n);

    for(int i = 0; i< n; i++){
        cin >> v[i];
    }

    dp[0] = v[0];
    ans = dp[0];

    for(int i = 1; i< n; i++){
        dp[i] = max(dp[i-1] * v[i], v[i]);
        ans = max(ans,dp[i]);
    }

    printf("%0.3lf", ans);


    return 0;
}
