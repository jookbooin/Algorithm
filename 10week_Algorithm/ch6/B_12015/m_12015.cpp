/**
 * n = 100만
 * 10 20 10 30 20 50
 * 10 20 30 50
 * 
 * O(nlogn) -> 이분 탐색 (logn)
 * 내부 수 (1 ~ 100만) -> 0으로 초기화
 */

#include <bits/stdc++.h>

using namespace std;

int n,num, len = 0;
int arr[1000004], lis[1000004];

int main(){

    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> num;

        auto lowerPos = lower_bound(lis, lis+len, num);
        if(*lowerPos == 0){
            len ++;
        }

        *lowerPos = num;
    }

    cout << len << endl;

    return 0;
}

