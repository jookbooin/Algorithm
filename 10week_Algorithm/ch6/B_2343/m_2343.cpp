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
const int III = 987654321;

int n, m, sum = 0, s = 0, input, mi = III;
int arr[INF];

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        s = max(s, arr[i]);
        sum += arr[i];
    }

    int start = s, end = sum;
     // 블루레이 길이

    while (start <= end) {
        int cnt = 1;
        int msum = 0;
        int mid = (start + end) / 2; 

        // 1. 블루레이 개수
        for (int i = 0; i < n; i++) {
            if (msum + arr[i] > mid) {
                cnt++;          // 새로운 블루레이
                msum = arr[i];  // 강의 1개 추가
            } else {
                msum += arr[i];
            }
        }

        // 2. 블루레이 길이 결정
        if (cnt <= m) { 
            mi = min(mi, mid); 
            end = mid - 1; 
        } else { 
            start = mid + 1; // 더 큰 길이 탐색
        }
    }


    // 블루레이의 크기 최소로 한다...
    cout << mi << '\n';

    return 0;
}