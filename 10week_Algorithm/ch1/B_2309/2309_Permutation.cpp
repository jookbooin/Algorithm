
/**
 * 1. 순열
 * 
 * do {
 * 
 * }while(next_permutation( start , end ));
 * 
 * permutation은 정렬 사용
 * 
*/

#include <bits/stdc++.h>
using namespace std;

int arr[9]; // 입력

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    
    for (int i = 0; i < 9; i++) {
        cin >> arr[i];
    }

    sort(arr,arr+9);  // 순열 사용할때 항상 오름 차순이어야한다.

    do{
        int sum = 0;
        for(int i =0; i<7; i++){            // 7개만 슬라이스 -> 조합이 바뀌는 구나
            sum += arr[i];
        }

        if (sum == 100)
            break;
    }while(next_permutation(arr,arr+9));
    
    for(int i =0; i<7; i++)
        cout << arr[i] << '\n';

    return 0;
}

