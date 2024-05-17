/**
 * 소 도착 시간, 검문 시간
 * 2 1
 * 5 7  // 6 7 8 9 10 11 12
 * 8 3  // 13 14 15
 */

#include <bits/stdc++.h>

using namespace std;

int n, a, w, start, arrive;
vector<pair<int,int>> vp;

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> w;
        vp.push_back({a,w});
    }
    sort(vp.begin(), vp.end());

    start = vp[0].first;
    arrive = start + vp[0].second;

    for(int i = 1; i<vp.size() ;i++){
        auto it = vp[i];
        if(arrive < it.first) {
            arrive = it.first + it.second;
        }else{
            arrive += it.second;
        }
    }

    cout << arrive - start << '\n';

    return 0;

}