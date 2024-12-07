/***
 * 보석 n개 (m, v) ( 100만, )
 * 가방 k개  = 30만 
 *  - ci : 각 가방에 담을 수 있는 최대 무게 
 * 
 * 가방에 최대 1개의 보석 넣을 수 있음 
 * 훔칠 수 있는 보석의 최대 가격 
 * 
 * < 입력>
 * - n개
 *      * (m, v)
 * - k개
 *      * ci : i번 가방 넣을 수 있는 최대 무게 
 * 
 * <출력>
 * - 상덕이가 훔칠 수 있는 보석 가격의 최댓 값 
 */

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<pair<ll, ll>> tre;
vector<ll> bag;
ll n, k,m,v, c, sum = 0, temp = -1;

// 최대 힙
priority_queue<ll> pq; // 무게 최대 

int main(){
    cin >> n >> k;
    for(int i = 0; i<n; i++){
        cin >> m >> v;
        tre.push_back({m,v});
    }

    for(int i = 0; i<k; i++){
        cin >> c;
        bag.push_back(c);
    }
    
    sort(tre.begin(), tre.end());
    sort(bag.begin(), bag.end());

    ll j = 0;
    for(int i = 0; i< bag.size(); i++){
    
        while(j < n && tre[j].first <= bag[i]){
            pq.push(tre[j++].second);
        }

        if(!pq.empty()){
            sum += pq.top();
            pq.pop();
        }
    }

    cout << sum << endl;

    return 0;
}