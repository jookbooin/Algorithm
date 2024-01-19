#include <bits/stdc++.h>
using namespace std;


// 내림차순
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b) {
        return a.first > b.first;
    }
    
int main() {
    for (int i = 10; i >= 1; i--) {
        v.push_back({i, 10 - i});
    }
    sort(v.begin(), v.end(), cmp);
    for (auto it : v) cout << it.first << " : " << it.second << "\n";
    return 0;
}