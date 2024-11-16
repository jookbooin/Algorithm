#include <bits/stdc++.h>
using namespace std;
#define max_n 200004
#define ll long long
const ll mod = 1e9 + 7;
int n, value;
ll ret = 1, _prev;

vector<ll> tree_cnt(max_n, 0), tree_sum(max_n, 0);

ll _sum(vector<ll> &tree, int value) {
    ll _ret = 0;
    int i = value;
    while (i) {
        _ret += tree[i];
        i -= (i & -i);
    }
    return _ret;
}
ll sum(vector<ll> &tree, int s, int e) {
    if (s > e) return 0;

    // e ~ s 까지의 합
    return (_sum(tree, e) - _sum(tree, s - 1));
}

void update(vector<ll> &tree, int s_idx, ll value) {

    // update 시작할 idx
    int idx = s_idx;

    while (idx <= max_n) {
        tree[idx] += value;
        idx += (idx & -idx);
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;


    for (int i = 1; i <= n; i++) {
        cin >> value;
        value++;

        if (i != 1) {
            
            // (n-1)*valn - sum(n-1)
            ll left = sum(tree_cnt, 1, value - 1)*value - sum(tree_sum, 1, value - 1);

            // sum(오른쪽) -  (오른쪽 개수) * val
            ll right = sum(tree_sum, value + 1, max_n) - sum(tree_cnt, value + 1, max_n) * value ;

            ret *= (left + right) % mod;
            ret %= mod;
        }
        update(tree_cnt, value, 1);

        // 
        update(tree_sum, value, value);
    }
    cout << ret << "\n";
}