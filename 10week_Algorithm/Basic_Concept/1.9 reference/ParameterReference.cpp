#include <bits/stdc++.h>
using namespace std;

int add(int &a, int b) {
    a += 10;
    cout << a << '\n';
    return a + b;
}

vector<int> v(3, 0);

void go(vector<int> &v) { v[1] = 100; }

int main() {
    int a = 1;
    int b = 2;

    cout << a << '\n';

    int sum = add(a, b);
    cout << a << '\n';

    cout << '\n';

    go(v);
    for(int i : v) cout << i << '\n';

    return 0;
    
}