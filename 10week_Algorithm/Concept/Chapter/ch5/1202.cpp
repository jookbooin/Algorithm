/**
 * 보석 N m v
 * 가방 k 최대 무게 c - 1개 넣을 수 있음 
 * 훔칠 수 있는 보석 최대 가격 
 * 
 * 
 * 보석 n, 가방 k 
*/

#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int n,m,v,k,c, ret = 0, last = 0;

vector<pair<int,int>> jv;
vector<int> bag;
priority_queue<ll> pq;

int main(){

    cin >> n >> k;
    for(int i = 0 ; i< n; i++){
        cin >> m >> v;
        jv.push_back({m,v});
    }
    
    for(int i = 0; i< k ; i++){
        cin >> c;
        bag.push_back(c);
    }

    sort(bag.begin(), bag.end()); // 무게순 정렬
    sort(jv.begin(), jv.end());   // 가방 

    // n 개수, k 개수    
    // 1. 용량이 적은 가방부터
    // 2. 담을 수 있는 보석중 , 가격이 가장 높은 것 

     int j = 0;
    for(int i = 0; i< k; i++){ // 가방 개수 

        while(j < n && jv[j].first <= bag[i]) pq.push(jv[j++].second); // for(k) 반복동안 총 n번 push -> O(N)

        if(!pq.empty()){
            ret += pq.top(); // 넣을 수 있는 최대값 
            pq.pop();
        }
    }

    cout << ret << '\n';

    return 0;
}