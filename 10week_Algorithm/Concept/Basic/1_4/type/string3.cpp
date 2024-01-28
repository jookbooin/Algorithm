#include <bits/stdc++.h>
using namespace std;
int main() {
    string a = "It's hard to have a sore leg";

    cout << a << '\n';
    reverse(a.begin(), a.end());
    cout << a << '\n';

    reverse(a.begin(), a.end());
    cout << a << '\n';

    reverse(a.begin() + 3, a.end());
    cout << a << '\n';

    return 0;
}