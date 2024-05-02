/**
 * n 15000
 * m 10 000 000
 * 
 * 배열 -> 1000만 
 * mid = M/2 
 * mid 까지 반복 -> 1000 - cur 이 mid 이상이면 중단
*/

#include <bits/stdc++.h>

using namespace std;

const int INF = 10000004;
int n,m,k,mid,cnt =0;
vector<int> arr;
int check[INF];

int main(){

    cin >> n >> m;
    mid = m/2;

    for(int i = 0; i< n; i++){
        cin >> k;
        arr.push_back(k);
        check[k] ++;
    }

    sort(arr.begin(), arr.end());

    for(int a : arr){
        if(a < mid+1 && check[m - a]){
            check[a]--;
            check[m-a] --;
            cnt ++;
        }
    }

    cout << cnt << '\n';

    return 0;
}