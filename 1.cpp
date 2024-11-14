/**
 * 2와 5로 나누어 떨어지지 않는 수 
 * 각 자리 1로만 이루어진 n의 배수 중 
 *  >> 가장 작은 수의 `자리수`
 * 
 * 3 : 111
 * 7 : 1111111
 * 9901 : 1111 1111 1111
 * 
 */

#include<bits/stdc++.h>

using namespace std;

int n, mul = 10;

int main(){

    while(cin >> n){ // 나누어야할 수
        int cnt = 0;
        int sum = 0; 

        // 반복 
        while(1){
            int temp = 1;
            for(int i = 0; i< cnt; i ++){
                temp *= 10;
                temp %= n;
            }

            sum += temp;
            sum %= n;

            if(sum == 0){
                break;
            }else{ 
                cnt ++;
            }
        }

        cout << cnt + 1 << endl;

    }
    return 0;
}