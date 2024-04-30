/**
 * 서로 볼 수 있으려면. A,B 사이에 AB 보다 큰 사람 없어야 함
 * n = 500 000 -> O(N), O(NlogN)
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, ret, now;
stack<pair<ll, ll>> s;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> now;
        int cnt = 1;
        while (s.size() && s.top().first <= now) {
            ret += s.top().second;

            if (s.top().first == now) {  // 같은 값일 때
                cnt = s.top().second + 1;
            } else {                    // 오름 차순일때
                cnt = 1;
            }

            cout << "top : " << s.top().first << " cnt : " << cnt << " now : " << now << '\n';

            s.pop();
        }

        // s.top > now : s.top보다 앞에 있는 사람 볼 수 없음
        if (s.size()) {
            ret++;
        }
        s.push({now, cnt});
    }

    cout << ret << '\n';

    return 0;
}