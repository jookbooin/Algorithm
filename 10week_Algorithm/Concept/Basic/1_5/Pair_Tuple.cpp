#include <bits/stdc++.h>
using namespace std;
pair<int, int> pi;
tuple<int, int, int> tl;

int a, b, c;
int a1, b1, c1;

int main(void) {
    
    // pair, tuple ÃÊ±âÈ­
    pi = {1, 2};
    tl = make_tuple(1, 2, 3);

    // pair 1 
    tie(a, b) = pi;
    cout << a << " : " << b << "\n";

    // pair 2
    a1= pi.first;
    b1 = pi.second;
    cout << a1 << " : " << b1 << "\n";

    // tuple 1
    tie(a, b, c) = tl;
    cout << a << " : " << b << " : " << c << "\n";

    // tuple 2
    a1 = get<0>(tl);
    b1 = get<1>(tl);
    c1 = get<2>(tl);
    cout << a1 << " : " << b1 << " : " << c1 << "\n";

    return 0;
}