
#include <bits/stdc++.h>

using namespace std;

/**
 * 의미 없이 -> Map을 떠올렸다.
 * 하지만 map을 순회하기 위해서는 mp.find(c) != mp.end()를 사용해야하는 구나
*/

map<char, int> mp;
int main(void) {
    for (int i = 97; i < 123; i++) {
        mp.insert({(char)i, 0});
    }

    string input;
    cin >> input;
    for (char c : input) {
        if (mp.find(c) != mp.end()) mp[c]++;
    }

    for (auto i : mp) cout << i.second << " ";
    return 0;
}