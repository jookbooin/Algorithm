/**
 * 수열의 마지막은 0
 * 수열의 길이 : 10만 
 * 
 * 중 상 좌 하 우 (0, 1, 2, 3, 4 )
 * 
 * 동일 위치 : 1
 * 0 -> (1, 2, 3, 4) : 2
 * 인접 -> (0, +1, -1) : 3 
 * (1 - 3), (2 - 4) : 4
 * 
 * 사용되는 최소의 합 : 
 * 
 * ( 0 1 2 3 ) % 4 + 1 
 *   0
 * 
 * 10만 * 4 * 4 
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 987654321;

vector<int> rv;
int n;
ll dp[100004][6][6]; // n라운드, (왼, 오) 위치 일 때 최솟값 

int point(int start, int end){

    if(start == end ) // 동일 
        return 1;
    if(start == 0)  // 중앙 
        return 2;
    if(abs(start - end) == 2) 
        return 4;
    return 3;
    
}

ll go(int round, int left, int right){
    // 종료조건 
    if(round == rv.size()) return 0;

    ll& ret = dp[round][left][right];
    if(ret != INF) return ret;

    // 기.왼 ->     
    ll val1 = go(round + 1, rv[round], right) + point(left, rv[round]);

    // 기.오 -> 
    ll val2 = go(round+1, left, rv[round]) + point(right, rv[round]);

    ret = min(val1, val2);

    return ret;
}

int main(){

    while(true){
        cin >> n;
        if(n == 0) break;
        rv.push_back(n);
    }

    fill(&dp[0][0][0], &dp[0][0][0] + 100004 * 6 * 6 , INF);
    cout << go(0, 0,0) << endl;

    return 0;
}
