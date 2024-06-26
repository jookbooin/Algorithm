#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000001; 
int n, cnt, mx = -INF, mi = INF;
int arr[14];
int op[4];

void go(int depth, int cur, int plus, int minus, int mul, int div){
    if(depth == n-1){
        mx = max(mx, cur);
        mi = min(mi, cur);
        return;
    }

    if(plus){
        go(depth+1, cur + arr[depth+1], plus-1, minus, mul, div);
    }
    if(minus){
        go(depth+1, cur - arr[depth+1], plus, minus-1, mul, div);
    }
    if(mul){
        go(depth+1, cur * arr[depth+1], plus, minus, mul-1, div);
    }
    if(div){
        go(depth+1, cur / arr[depth+1], plus, minus, mul, div-1);
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < 4; i++) {
        cin >> op[i];
    }

    go(0, arr[0], op[0], op[1], op[2], op[3]);

    cout << mx << endl;
    cout << mi << endl;

    return 0;
}
