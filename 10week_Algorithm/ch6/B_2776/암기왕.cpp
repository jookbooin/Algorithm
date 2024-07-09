#include <bits/stdc++.h>

using namespace std;

int t, m, n, k;

// arr2에 있는 수가 arr1에 존재하는지 확인
int search(int input, vector<int>& v) {
    int start = 0, end = n - 1;  // 시작점 끝점
    int mid;
    while (start <= end) {
        mid = (start + end) / 2;
        if (v[mid] == input) {
            return 1;
        } else if (v[mid] > input) {
            end = mid - 1;
        } else {  // v[mid] <= input
            start = mid + 1;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    for (int i = 0; i < t; i++) {
        vector<int> v; 

        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> k;
            v.push_back(k);
        }

        // arr1 정렬
        sort(v.begin(), v.end());

        cin >> m;
        for (int j = 0; j < m; j++) {
            cin >> k;
            cout << search(k, v) << '\n';
        }
    }

    return 0;
}
