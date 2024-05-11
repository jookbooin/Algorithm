/**
 * n = 100000
 * x = 2000000
 * a = 1000000
 * 
 * 1. 정렬 
 * 2. l, r
 * 2. 크다면  r--
 * 3. 같, 작 l++
*/

#include<bits/stdc++.h>

using namespace std;
int n, l,r,x,input,cnt = 0;
vector<int> v;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i =0; i<n;i++){
        cin >> input;
        v.push_back(input);
    }
    cin >> x;

    // 1 2 3 5 7 9 10 11 12

    sort(v.begin(),v.end());
    l = 0, r = n-1;

    while(l<r){
        int hab = v[l] + v[r];
        if(hab > x){
            r--;
        }else if (hab == x){
            cnt ++;
            l++;
        }else {
            l ++;
        }
    }

    cout << cnt << '\n';
    return 0;
}