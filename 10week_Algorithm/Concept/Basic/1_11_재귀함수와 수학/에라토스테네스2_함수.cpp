#include <bits/stdc++.h>
using namespace std;

bool check(int n){
    if(n <= 1) return 0;
    if(n == 2) return 1;
    // if(n % 2 == 0) return 0;

    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return 0;
    }

    return 1;
}

int main() {
    for (int i = 1; i <= 40; i++) {
        if (check(i)) {
            cout << i << "는소수입니다.\n";
        }
    }
    return 0;
}