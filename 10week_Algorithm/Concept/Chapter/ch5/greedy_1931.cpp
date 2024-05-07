
/**
    11
    1 4
    3 5
    0 6
    5 7
    3 8
    5 9
    6 10
    8 11
    8 12
    2 13
    12 14



*/

#include <bits/stdc++.h>
using namespace std;
int from, to, n, idx = 0, ret = 1;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++) {
        cin >> from >> to;
        v.push_back({to, from});
    }

/** 끝나는 시간 기준으로 정렬한다. */
    sort(v.begin(), v.end());
   
   from = v[0].second;
   to = v[0].first;
   
   for(int i = 1; i< n; i++){
    
        if(v[i].second < to) continue;
        from = v[i].second;
        to = v[i].first;
        ret ++;
   }

   cout << ret << '\n';
   
    return 0;
}
