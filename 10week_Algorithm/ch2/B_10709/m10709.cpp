/**
 * N 명
 * 1. 1명 타겟
 * 2. 타겟 - 자기자신 
 * 3. 타겟 = 1점, 맞춘 사람 1점 
 * 4. 예상 빗나간 사람 수 x명 타겟 = (1 + x)점
 * 
 * 게임 횟수 M번
 * 1 번째 게임에서 친구 idx 가 Bij번 친구를 썼다.
 * 
*/

#include <bits/stdc++.h>

const int MAX_VALUE = 101;
using namespace std;

int N, M;
int target[MAX_VALUE];
int write[MAX_VALUE][MAX_VALUE];
int result[MAX_VALUE];

void check(int round){
    int rtarget = target[round];

    for(int i = 1 ; i<= N ; i++){
        if(write[round][i] == rtarget){ // 맞출때
            result[i] += 1;
        }else{
            result[rtarget]++;  // 못 맞추면 타겟 + 1
        }

    }

}

int main(void){
    cin >> N;
    cin >> M;

    for(int i = 1; i<=M ; i++)
        cin >> target[i];
    
    for(int row =1 ; row<=M; row++){
        for(int col = 1; col<=N ; col ++){
            cin >> write[row][col];  // row 번째 게임, col번 친구는 [row][col]번 친구를 썼다.

            
        }
        check(row);
    }

    for(int i =1 ; i<=N ; i++){
        cout << result[i] << '\n';
    }


    return 0;
}
// 2 1 0
// 0 2 1
// 0 0 3
// 1 1 1

// 3 4 5