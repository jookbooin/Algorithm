/**
 *  9개 중 7개를 선택하는것 (a, a+7);
 */

#include <bits/stdc++.h>
using namespace std;
int a[9];
int n = 9, r = 7;
void solve() {
    int sum = 0;
    for (int i = 0; i < r; i++) {
        sum += a[i];
    }
    if (sum == 100) {
        sort(a, a + 7);
        for (int i = 0; i < r; i++) cout << a[i] << "\n";
        exit(0);
    }
}
void print() {
    for (int i = 0; i < r; i++) cout << a[i] << " ";
    cout << '\n';
}

void makePermutation(int n, int r, int depth) {
    if (depth == r) {
        return;
    }

    for (int i = depth; i < n; i++) {
        makePermutation(n, r, depth + 1);
    }
}

int main() {
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    makePermutation(n, r, 0);
    return 0;
}