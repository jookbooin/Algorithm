/***
 * 보석 개수 n : 13
 * 가방 개수 m : 10
 * 한계 무게 c : 20
 * 보석 무게 w : 20
 * 
 * 
 * >> 가져갈 수 있는 [최대] 보석 개수 
 * 
 * 1. w > c pass
 * 2. 남은 무게 >= w
 * 3. 넣는다.
 * 4. 안넣는다. 
 * 
 * '훔친 보석 최대 개수'
 * 
 * 
 * 가방별 남은 용량(상태) -> 가방, 용량
 * 몇번째 보석인지 -> check
 * 
 * 1. O X
 * 2. 어디에 넣느냐에 따라 달라질 수 있음 -> 모든 가방 확인?????
 *      - 새 가방
 *      - 사용한 가방?
 * 
 * <현재 문제>
 * - 물건을 어느 가방에 넣을지
 * - 가방의 상태를 어떻게 관리할 지???
 * - 용량과 개수 
 * 
 */

#include<bits/stdc++.h>
using namespace std;

int n,m,c,w;
int tr[17]; // 보석의 크기

// [가방 번호][남은 용량][확인한 보석]
int dp[17][24][1<<15]; //

int go(int bidx, int cap, int visited){
    
    // 종료 조건 
    if(bidx == m) return 0;

    // 메모제이션 
    int& ret = dp[bidx][cap][visited];
    if(ret) return ret;

    // 1. 현재 가방에 담는다.
    for(int i =0; i<n; i++){ // 보석
        if(visited & (1<<i)) continue; // 이미 방문 했다면
        if(cap < tr[i]) continue; // 담을 수 없다면

        ret = max(ret, go(bidx, cap - tr[i], visited | (1<<i)) + 1);
    }

    // 2. 다른 가방에 담는다.
    ret = max (ret, go(bidx + 1, c, visited));

    return ret;
}

int main(){
    cin >> n >> m >> c;

    for(int i = 0; i<n; i++){
        cin >> tr[i];
    }

    cout << go(0,c,0) << endl;

    return 0;
}