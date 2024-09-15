/**
 * L[i] 만큼 체력 잃고
 * j[i] 만큼 기쁨을 얻는다.
 * 각각의 사람에게 최대 1번만 말함
 * 
 * 체력 100, 기쁨 0
 * 
 */

#include <bits/stdc++.h>

using namespace std;

int n, input, ret = 0;
int l[24], m[24];

int main(){
    cin >> n;
    
    for(int i = 0; i< n; i++){
        cin >> l[i];
    }

    for(int i = 0; i<n; i++){
        cin >> m[i];
    }

    for(int i = 1 ; i< (1<<n); i++){
        int heart = 100 , happy = 0;

        for(int j = 0; j < n; j++){
            if(i & (1<<j)){
                heart-= l[j];
                happy += m[j];
            }
        }

        if(heart > 0){
            ret = max(ret, happy);
        }
    }

    cout << ret << endl;

    return 0;
}