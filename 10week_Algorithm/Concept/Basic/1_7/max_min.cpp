#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int a = *max_element(v.begin(), v.end());  // ÃÖ´ñ°ª
    auto b = max_element(v.begin(), v.end());  // ÀÎµ¦½º
    cout << a << '\n';
    cout << (int)(b - v.begin()) << '\n';

    int c = *min_element(v.begin(), v.end());
    auto d = min_element(v.begin(), v.end());
    cout << c << '\n';                     // 1
    cout << (int)(d - v.begin()) << '\n';  // 0

    return 0;
}