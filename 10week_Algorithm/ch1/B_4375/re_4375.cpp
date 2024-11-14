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

int n;

int main(){
    while(scanf("%d", &n) != EOF){
        int cnt = 1, ret = 1;
        while(1){
            if(cnt % n == 0){
                printf("%d\n", ret);
            }else{
                cnt = (cnt * 10) + 1;
                cnt %= n;
                ret++;
            }
        }
    }

    return 0;
}