#include <bits/stdc++.h>
using namespace std;  
typedef long long ll;
int N, C, arr[1004];

map<int, int> mp, mp_idx; // mp : ( 값 , 개수 ) mp_idx : ( 값 , 인덱스 )
vector<pair<int,int>> vmp;  // map -> 

bool cmp(pair<int,int> a, pair<int,int> b){ 
    if(a.second == b.second){ 
        return mp_idx[a.first] < mp_idx[b.first]; 
    }
    return a.second > b.second;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> C;

    for(int i = 0; i<N ; i++){
        cin >> arr[i];
        mp[arr[i]] ++;

        if(mp_idx.find(arr[i]) == mp_idx.end()){
            mp_idx[arr[i]] = i + 1;
        }
    }

    for(auto it : mp){
        vmp.push_back({it.first,it.second}); // 값 , 개수 
    }

    sort(vmp.begin(), vmp.end(), cmp);

    for(auto it : vmp){
        for(int i = 0 ; i< it.second ; i++){
            cout << it.first << " ";
        }
    }

    return 0;
}