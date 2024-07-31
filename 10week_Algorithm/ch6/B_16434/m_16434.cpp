#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef struct block {
    ll t, atk, hp;
} bl;

typedef struct warrior {
    ll mhp, chp, atk;

    void recover(ll rhp, ll ratk) {
        atk += ratk;
        chp = min(mhp, chp + rhp);
    }
} wari;

ll n, atk, ans;

bl brr[123460];
bl trr[123460];

// trr 초기화
void trrinit() {
    for (int i = 0; i < n; i++) {
        trr[i].t = brr[i].t;
        trr[i].atk = brr[i].atk;
        trr[i].hp = brr[i].hp;
    }
}

bool check(wari& wr) {
    for (int i = 0; i < n; i++) {
        if (trr[i].t == 1) {  // 몬스터
            ll cnt = trr[i].hp / wr.atk + (trr[i].hp % wr.atk ? 1 : 0) ; // 몬스터가 죽기까지 필요한 공격 횟수
            // 몬스터가 공격하는 횟수는 cnt - 1
            wr.chp -= (cnt - 1) * trr[i].atk; 

            // 몬스터가 죽었는지 확인
            if (wr.chp <= 0) return false;
        } else {  // 포션
            wr.recover(trr[i].hp, trr[i].atk);
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> n >> atk;

    for (int i = 0; i < n; i++) {
        cin >> brr[i].t >> brr[i].atk >> brr[i].hp;
    }

    ll left = 1, right = 1e18 + 4;

    while (left <= right) {
        trrinit();  // 1. 맵 초기화

        ll mid = (left + right) / 2;  // 용사 초기 체력

        wari wr = {mid, mid, atk};  // 2. 용사 초기화

        if (check(wr)) {  // 용사 성공했을 때
            ans = mid;
            right = mid - 1;
        } else {  // 용사 죽었을 때
            left = mid + 1;
        }
    }

    cout << ans << '\n';

    return 0;
}
