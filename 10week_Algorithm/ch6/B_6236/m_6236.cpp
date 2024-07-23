/**
 * n일
 * k원
 * m번만 빼서 쓴다
 *
 * 1. 하루를 보낼 수 있으면 그대로 사용하고, 
 *    모자라게 되면 남은 금액은 통장에 집어넣고 다시 K원을 인출
 * 
 * 2. M이라는 숫자를 좋아하기 때문에, 
 *    정확히 M번을 맞추기 위해서 남은 금액이 
 *    그날 사용할 금액보다 많더라도 남은 금액은 통장에 집어넣고 
 *    다시 K원을 인출
 *
 *
 * 1. 최소 max 와 합 사이
 * 2.
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, m,sum = 0, mi= 0,ans;
ll arr[100004];

bool check(int k){
    int cnt = 1;
    int mon = k;

    for(int i = 0; i< n ; i++){
        if(arr[i] > mon){
            cnt++;
            mon = k;
        }

        mon -= arr[i];
    }

    return cnt <= m;  // m 보다 작다면 mid가 크다는 것 의미
}

int main() {

    cin >> n >> m;

    for(int i = 0; i< n; i++){
        cin >> arr[i];
        mi = max(mi, arr[i]);
        sum += arr[i];
    }

    int start = mi, end = sum;

    while(start <= end){
        int mid = (start + end ) / 2;

        // mid가 작아지면 횟수는 늘어남
        // mid가 커지면 횟수가 줄어듬

        if(check(mid)){  // 이 경우에 mid는 작아져야 함 
            end = mid - 1;
            ans = mid;
        }else{           // mid 가 커져야 함
            start = mid + 1;
        }

    }

    cout << ans << '\n';

    return 0;
}