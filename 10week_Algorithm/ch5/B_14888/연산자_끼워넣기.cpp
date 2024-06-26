#include <bits/stdc++.h>
using namespace std;

const int INF = 1000000000;
int n, cnt, mx = -INF, mi = INF;
int arr[14];
vector<int> op;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < 4; i++) {
        cin >> cnt;
        for (int j = 0; j < cnt; j++) {
            op.push_back(i);
        }
    }

    do {
        int sum = arr[0];
        for (int i = 0; i < op.size(); i++) {
            if (op[i] == 0) {
                sum += arr[i + 1];
            } else if (op[i] == 1) {
                sum -= arr[i + 1];
            } else if (op[i] == 2) {
                sum *= arr[i + 1];
            } else {
                sum /= arr[i + 1];
            }
        }
        mx = max(mx, sum);
        mi = min(mi, sum);

    } while (next_permutation(op.begin(), op.end()));

    cout << mx << endl;
    cout << mi << endl;

    return 0;
}
