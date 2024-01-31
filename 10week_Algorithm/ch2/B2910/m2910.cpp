#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll max_n = 1e9;  // 최대 입력 갯수

int N;
ll C;
int arr[1001];
map<int,pair<int,int>> mp;  // <값 , < 처음나온 idx , value> > 

bool comp(pair<int, pair<int,int>> &a, pair<int, pair<int,int>> &b){

    if(a.second.second == b.second.second){
        return a.second.first < b.second.first;  // 인덱스 작은 것이 앞으로 
    }

    return a.second.second > b.second.second; // 횟수 많은 것이 앞으로
}

int main(void) {
    cin >> N >> C;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];

        if(mp[arr[i]].second == 0 ){
            mp[arr[i]] = make_pair(i,1);
        }else{
            mp[arr[i]].second +=1;
        }
    }

    vector<pair<int, pair<int,int>>> vmp(mp.begin(),mp.end());
    sort(vmp.begin(),vmp.end(),comp);

    for(auto result : vmp){
        for(int i = 0 ; i< result.second.second ; i ++){
            cout << result.first << " ";
        }
    }


    return 0;
}

