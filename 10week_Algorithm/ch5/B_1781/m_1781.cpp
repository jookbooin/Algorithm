/**
 * 라면 개수 최대
 * 오름 차순
 * 입력하면서 -> 데드라인 개수만큼 Q에 있어야 함 -> Q에 있는 것들 모두 최대여야함
 * n = 200 000 -> O(N)
 */

#include <bits/stdc++.h>

using namespace std;

int n, dd, cup, ret = 0;
vector<pair<int, int>> vp;
priority_queue<int, greater<int>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> dd >> cup;
        vp.push_back({dd, cup});
    }

    sort(vp.begin(), vp.end());

    for (auto it : vp) {
        dd = it.first;
        cup = it.second;

        ret += cup;
        pq.push(cup);

        if (pq.size() > dd) {
            ret -= pq.top();
            pq.pop();
        }
    }

    // while(!pq.empty()){
    //     ret += pq.top();
    //     pq.pop();
    // }

    cout << ret << '\n';

    return 0;
}