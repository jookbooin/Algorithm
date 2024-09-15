#include <bits/stdc++.h>

using namespace std;

int n, ret = 0;
int l[24], m[24];

void go(int cur, int power, int happy) {

    // 불가능 
    if(power <= 0) return;
    
    // 가능
    if (cur >= n) {
        // 체력이 0 이하가 되거나 모든 사람에게 말을 했을 경우
        ret = max(ret, happy); // 최대 기쁨 업데이트
        return;
    }
    
    // 포함
    go(cur + 1, power - l[cur], happy + m[cur]);

    // 미포함
    go(cur + 1, power, happy);
}

int main() {
    cin >> n;
    
    // 체력
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }

    // 기쁨
    for (int i = 0; i < n; i++) {
        cin >> m[i];
    }

    go(0, 100, 0); // 초기 체력 100, 초기 기쁨 0

    cout << ret << endl; // 최대 기쁨 출력
    return 0;
}
