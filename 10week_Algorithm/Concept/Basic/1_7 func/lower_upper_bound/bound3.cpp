#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    
    vector<int> a{1, 2, 3, 3, 3, 4, 100};
    cout << &*lower_bound(a.begin(), a.end(), 3) - &*a.begin() << "\n";

    vector<int> b{0, 0, 0, 0};
    cout << &*(b.begin() + 3) - &*b.begin() << "\n";

    return 0;
}