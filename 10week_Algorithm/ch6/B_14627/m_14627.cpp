/***
 * 파의 개수 s = 100만
 * 주문 받은 파닭 개수 c = 100만
 * 파의 길이 l ( 1 ~ 10억 )
 * 
 * 각각 같은 양의 파를 넣는다.
 * 
 * s개의 파로 
 * 최대의 크기인 c개의 파로 자름
 * 전체 파의 개수 중 남은 파의 개수를 구함 
 *
 * pmax : c개의 파로 자를 수 있는 가장 큰 수 
 * ans = sum - ( c * pmax )
 * 
 * 100만개를 O(N) 시간으로 찾아야 하나?
 */

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll INF = 987654321;
ll s,c, st,en, mid, ans;
ll pmax = 0, pmin = INF, sum = 0;

bool check(ll mid, vector<ll>& v){
    // 개수 
    ll cnt = 0;

    for(ll a : v){
        cnt += (a / mid);
    }

    return cnt >= c;  // mid를 더 크게 할 수 있다.
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s >> c ;

    vector<ll> pv(s);
    for(ll i = 0; i<s; i++){
        cin >> pv[i];

        // 전체 pmax, pmin
        pmax = max(pmax, pv[i]);
        pmin = min(pmin, pv[i]);
        sum += pv[i];
    }

    sort(pv.begin(), pv.end());

    st = 1, en = pmax;

    while(st <= en){
        mid = (st + en) / 2;

        if(check(mid, pv)){
            st = mid + 1;
            ans = mid;
            
        }else{
            en = mid - 1;
        }

    }

    cout << sum - c*ans << '\n';

    return 0;
}

