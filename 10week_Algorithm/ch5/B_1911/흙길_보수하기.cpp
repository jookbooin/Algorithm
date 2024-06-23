/**
 * n = 10,000 ( 웅덩이 개수)
 * l = 1,000,000 ( 널판지 길이 )
 * 
 * 물 웅덩이를 덮기 위해 필요한 최소 개수
 * 
 * 웅덩이 (시작, 끝) 10 이하
 * 웅덩이 겹치지 않음 
*/

#include<bits/stdc++.h>

using namespace std;

const int fin = 1000000000;
int n,l,a,b,st,en,cnt=0 ,temp = 0,nuls;
vector<pair<int,int>> v;

int main(){
    cin >> n >> l;

    for(int i = 0; i<n; i++){
        cin >>a >> b;
        v.push_back({a,b});
    }

    sort(v.begin(), v.end());

    for(int i =0; i<v.size(); i++){
        int st = v[i].first;
        int en = v[i].second;

        if(temp < st){
            temp = st;
        }
 
        while(temp < en){
            temp += l;
            cnt ++;
        }
        
    }

    cout << cnt <<'\n';

    return 0;
}