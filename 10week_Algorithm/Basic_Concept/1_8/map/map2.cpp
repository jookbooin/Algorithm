#include <bits/stdc++.h>
using namespace std;

map<int, int> mp;
map<string, string> mp2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // map은 [ ] 를 사용하면 map에 바로 추가된다.
    if (mp[2] == 0) {
        for (auto i : mp) cout << i.first << " " << i.second << '\n';
        mp[2] = 3;
    }

    for (auto i : mp) cout << i.first << " " << i.second << '\n';


    // 반환되는 '마지막 요소 다음'을 가리키는 반복자를 반환
    // 1인 요소가 없다는 것을 의미
    if (mp.find(1) == mp.end()) {
        mp[1] = 2;
    }

    for (auto i : mp) cout << i.first << " " << i.second << '\n';

    return 0;
}