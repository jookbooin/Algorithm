#include <bits/stdc++.h>
using namespace std;

#define end ff
const int INF = 1000000000;
const int SIZE = 300000;
int n, m, end = 0, start = 1, ret = INF;
int arr[SIZE];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        cin >> arr[i];
        end = max(end, arr[i]);
    }

    while (start <= end) {
        int sum = 0;
        int mid = (start + end) / 2;

        for (int i = 0; i < m; i++) {
            sum += arr[i] / mid; // 올림 처리
            if(arr[i] % mid) sum++; 
        }

        if (sum > n) {
            start = mid + 1;
        } else {
            ret = min(ret, mid);
            end = mid - 1;
        }
    }

    cout << ret << '\n';
    return 0;
}
