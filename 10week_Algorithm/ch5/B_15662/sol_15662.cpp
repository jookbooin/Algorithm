#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, k, a, b, ret;

string s[1004];

int findL(int pos) {
    for (int i = pos; i >= 1; i--) {
        if (s[i][6] == s[i - 1][2]) {  // 같은 극인 위치
            return i;
        }
    }

    // 왼쪽 끝까지
    return 0;
}

int findR(int pos) {
    for (int i = pos; i <= n - 2; i++) {
        if (s[i][2] == s[i + 1][6]) {
            return i;  // 같은 극인 위치
        }
    }

    // 오른쪽 끝 위치
    return n - 1;
}

void rot(int pos, int dir){ 

    if(!dir) rotate(s[pos].begin(), s[pos].begin()+ 1, s[pos].end());
    else rotate(s[pos].begin(), s[pos].begin() + s[pos].size() - 1, s[pos].end());
    
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];  // 숫자로 변환하지 않고 바로 "10101111" 입력
    }

    cin >> k;

    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        a--;

        // -1 1 -> 0 1 로 변환
        b = (b == -1 ? 0 : 1);

        // 어디까지 회전할 수 있는지 l,r 위치 찾기
        int l = findL(a);
        int r = findR(a);

        // 왼쪽 회전
        int cnt = 0;  // 초기 포지션
        for (int pos = a; pos >= l; pos--) {
            rot(pos, cnt % 2 == 0 ? b : !b);
            cnt++;
        }

        // 오른쪽 회전
        int cnt = 1;
        for (int pos = a + 1; pos <= r; pos++) {
            rot(pos, cnt % 2 == 0 ? b : !b);
            cnt++;
        }
    }

    for (int i = 0; i < n; i++) {
        if (s[i][0] == '1') ret++;
    }

    cout << ret << '\n';

    return 0;
}