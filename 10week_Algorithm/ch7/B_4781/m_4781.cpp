/**
 * 사탕 종류 n (5000)
 * 돈의 양 m (0.01 ~ 100.00) (1 ~ 10000원)
 * 
 * 사탕 칼로리 c (5000)
 * 가격 p (100.00)
 * 
 * 마지막줄 0 0.00
 * 
 * >> 같은 돈으로 구매한 사탕의 칼로리가 더 큰 사람이 이김
 * >> m으로 만들 수 있는 칼로리가 가장 높은 조합 
 * 
 * 1. dp 배열? -> 가격 기준 -> int (10000 - 800, 700, 200)
 * 2. 정렬 (200, 199),(300, 299)
 * 3. 
 */

#include <bits/stdc++.h>
using namespace std;

int dp[10004];
double p, m;
int n,c, money, price;  
int main(){

    while(1){
        cin >> n >> m;
        
        // 종료 조건
        if(n== 0 && m == 0.00) break;
        int max_price = 0;
        
        // 돈 int 변형
        money = (int)(100 * m +0.5);
        vector<pair<int,int>> pv(n);

        // 초기화 -1
        fill(&dp[0],&dp[0]+10004,-1);

        for(int i =0; i<n; i++){
            cin >> c >> p;
            pv.push_back({(int)(100*p+0.5), c});
        }
        
        // 가격으로 정렬 
        sort(pv.begin(), pv.end());

        dp[0] = 0;
        for(auto can : pv){
            int can_pc = can.first;
            int kcal = can.second;

            for(int i = can_pc; i <= money; i++){
                
                // 값이 존재한다면
                if(dp[i-can_pc] != -1){
                    dp[i] = max(dp[i], dp[i-can_pc] + kcal);
                    max_price = max(max_price, dp[i]);
                }
            }
        }

        cout << max_price << '\n';
    }

    
    return 0;
}