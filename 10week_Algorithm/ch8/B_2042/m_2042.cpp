 /**
  * n (수 개수) = 100만
  * m (변경 횟수) = 1만
  * k (구간합 구하는 횟수) = 1만
  * 
  * (n + 2) ~ (n + m + k + 1)
  * 1 : ( b -> c )
  * 2 : ( b ~ c ) 까지의 합 출력 
  * 
  * 
  * 1. 합을 구한다. O(N)
  * 2. update O(1)
  * 1만 * 100만 > 2억 
  * 13 * 100만 ? -> 1300 ?? 
  * `구간` -> 세그먼트 OR 펜윅?? 
  */

#include <bits/stdc++.h>

using namespace std;
typedef long long ll; // 64

ll n,m,k, a,b,c;

ll arr[1000004];
ll tree[1000004];

void update(int idx, ll val){
    while(idx <= n){
        tree[idx] += val;
        idx += (idx & -idx);
    }
}

ll sum(int idx){
    ll result = 0;
    while(idx > 0){
        result += tree[idx];
        idx -= (idx & -idx);
    }

    return result;
}

int main(){
    cin >> n >> m >> k;

    for(int i = 1; i<=n; i++){
        cin >> arr[i];
        update(i, arr[i]);
    }

    // 변경 m, 합 출력 k
    for(int i = 0; i< m + k ; i++){
        cin >> a >> b >> c;
        if(a == 1){

            // 차이 
            ll diff = c - arr[b];
            arr[b] = c;
            update(b,diff);
        }else{
            cout << sum(c) - sum(b-1) << endl;
        }
    }

    return 0;
}