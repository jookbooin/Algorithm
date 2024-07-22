/**
 * 강의 순서가 바뀌면 안된다.
 * i ~ j 사이 강의 모두 같은 위치
 *
 * 모두 같은 크기의 M개의 블루레이 녹화 가능 길이 최소
 *
 * 강의의 수 N
 * 블루레이 개수 M
 *
 * 각 강의의 수 = 10만
 * 각 강의의 길이 = 1만
 */

#include <bits/stdc++.h>

using namespace std;

const int INF = 100004;

int n, m, sum = 0, mx = 0, input,ans =0 ;
int arr[INF];

bool check(int mid) {
    if(mid < mx ) return false;

    int cnt = 1;
    int msum = 0;

    // 1. 블루레이 개수
    for (int i = 0; i < n; i++) {
        if (msum + arr[i] > mid) {
            cnt++;          // 새로운 블루레이
            msum = arr[i];  // 강의 1개 추가
        } else {
            msum += arr[i];
        }
    }

    return cnt <= m; // mid 늘려야 함
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mx = max(mx, arr[i]);
        sum += arr[i];
    }

    int start = mx, end = sum;
    // 블루레이 길이

    while (start <= end) {
        int mid = (start + end) / 2;

        // 2. 블루레이 길이 결정
        if (check(mid)) {
            end = mid - 1;
            ans = mid;
        } else {
            start = mid + 1;  // 더 큰 길이 탐색
        }
    }

    // 블루레이의 크기 최소로 한다...
    

    return 0;
}