#include <bits/stdc++.h>
using namespace std;
int n, ret = 1;

int main(){

    cin >> n;
    while(n != 1){  
        if(n & 1) ret ++;   // 마지막 비트가 1일때 = 홀 수 일때
        n /= 2;
    }
    cout << ret << '\n';
    return 0;
}

