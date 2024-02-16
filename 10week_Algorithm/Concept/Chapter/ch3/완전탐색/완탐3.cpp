// Input:
// 10
// 24 35 38 40 49 59 60 67 83 98
// output:
// 10

#include <bits/stdc++.h>
using namespace std;
int n, temp, ret , cnt;
vector<int> v;
const int mod = 11;

void go(int idx, int sum) {
    if (idx == n) {
        ret = max(ret, sum % mod);
        cnt++;
        return;
    }
    go(idx + 1, sum + v[idx]);   // 포함
    go(idx + 1, sum);            // 포함 x
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    go(0, 0);
    cout << ret << "\n";
    return 0;
}
