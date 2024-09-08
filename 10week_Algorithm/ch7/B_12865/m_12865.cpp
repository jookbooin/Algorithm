/**
 * n (100), k : 배낭 무게 (100 000)
 * w : 물건 무게 (100 000), v : 가치 (1000)
 * 
 * 무게 마다 가치 최대 저장 필요 (메모제이션)
 * dp - 가치 기준 
 * 
 * 3 6
 * 4 7
 * 4 8
 * 5 12
 * 6 13
 * 
 * 한번만 넣을 수 있다? -> 오른쪽부터 dp
 * 
 * 0 1 2 3 4 5 6 7 
 *       6 6 6 6 6
 *         8 8 8 14
 *           12 12 14   
 */

#include <bits/stdc++.h>

using namespace std;

int n, k, w, v, max_n = 0;
int dp[100004];
vector<pair<int,int>> pv;

int main(){
    cin >> n >> k;
    for(int i =0; i<n; i++){
        cin >> w >> v;
        pv.push_back({w,v});
    }

    sort(pv.begin(), pv.end());

    for(auto pro : pv){
        int wei = pro.first;
        int val = pro.second;  

        for(int i = k; i >= wei ; i-- ){
            dp[i] = max(dp[i], dp[i-wei] +val);
            max_n = max(max_n, dp[i]);
        }
        
    }

    cout << max_n << '\n';
    return 0;
}
