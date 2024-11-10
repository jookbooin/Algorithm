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


// false : mid (블루레이 크기가) 너무 작다
//                            = 조금 키워도 된다. 
// true : mid (블루레이 크기)가 충분히 크다 
//                            = 조금 줄여도 된다.
bool check(int mid) {
    
    // 블루레이 크기는 최대 강의 크기보다 커야한다.
    if(mid < mx ) return false;

    int cnt = 1;
    int msum = 0;

    for (int i = 0; i < n; i++) {

        if (msum + arr[i] > mid) {
            cnt++;          
            msum = arr[i];  
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
        if (check(mid)) { // 블루레이 크기를 줄인다.
            end = mid - 1;
            ans = mid;

        } else { // 블루레이 크기를 키운다.
            start = mid + 1;  
        }
    }


    cout << ans << endl;

    return 0;
}