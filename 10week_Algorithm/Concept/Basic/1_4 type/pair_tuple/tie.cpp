#include <bits/stdc++.h>
using namespace std;

pair<int, int> pi;
pair<int, int> pi2;
tuple<int, int, int> tl;
tuple<int,int,int> tl2;

int a, b, c;
int main() {
    pi = {1, 2};
    pi2 = make_pair(3,4);
    tl = make_tuple(1, 2, 3);
    tl2 = make_tuple(4,5,6);

    tie(a, b) = pi;
    cout << a << " : " << b << "\n";

    cout << pi2.first << " : " << pi2.second << "\n";

    tie(a, b, c) = tl;
    cout << a << " : " << b << " : " << c << "\n";

    a = get<0>(tl2);
    b = get<1>(tl2);
    c = get<2>(tl2);

    cout << a << " : " << b << " : " << c << "\n";
    return 0;
}
