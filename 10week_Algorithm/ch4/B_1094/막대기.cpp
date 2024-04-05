/**
 * 초기 : 64
 * 
 * 막대 모두 더함
 * 가장 짧은 것을 절반으로 자른다.
 * ( 자른 막대 절반 중 1개 버림 ) -> 남아 있는 막대의 길이의 합이 X 보다 >= 
 * ( 자름 막대 절반 중 1개 버림 )
 * 
 * 남아 있는 막대 풀로 붙여서 X로 만듬
 * 
 * X <= 64
 * 
 * 64
 * 32 32 -> 32
 * 16 16 
 * 8 8 16 -> 8 16
 * 4 4 16
 * 2 2 4 16
 * 1 1 2 4 16 -> 1 2 4 16
 * 
 * (48)
 * 64                   // 01000000
 * 32 32                // 00100000 00100000
 * 16 16 32 -> 16 32    // 
*/

/**
 * a b
 * if a <= 64
 *    a b 
 * a/2 a/2 b 
*/
#include <bits/stdc++.h>
using namespace std;

int x;
vector<int> co = {64};

int getSum(vector<int>& co){
    int gsum = 0;
    for(int a : co){
        gsum += a;
    }
    return gsum;
}


int main(){
    cin >> x;
    
    while(getSum(co) > x){  // ret 대신 직접 getSum(co)를 호출하여 조건 검사
        int cback = co.back();
        co.pop_back();
        co.push_back(cback >> 1);
        if(getSum(co) < x){  // 마찬가지로 ret 대신 getSum(co)를 사용
             co.push_back(cback >> 1);
        }
    }

    cout << co.size() << '\n';  // 막대기의 개수 출력

    return 0;
}