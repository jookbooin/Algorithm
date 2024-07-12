
// O(N^2)

#include <bits/stdc++.h>

using namespace std;

int n ,ret= 0;
int arr[1004];
int carr[1004];

int main(){
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> arr[i];
    }

    for(int i = 0; i< n; i++){
        int mx = 0;
        for(int j = 0; j<i ; j++){
            // arr[i] 보다 작고 , 
            if(arr[j] < arr[i] && mx < carr[j]){
                mx = carr[j];
            }
        }
        carr[i] = mx + 1;
        ret = max(ret, carr[i]);
    }

    cout << ret << '\n';

    vector<int> v;

    for(int i = n-1; i>=0; i--){
        if(carr[i] == ret){
            v.push_back(arr[i]);
            ret --;
        }
         
    }

    reverse(v.begin(), v.end());
    for(int a : v){
        cout << a << ' ';
    }

    

    return 0;
}


