/**
 * n개 ( 10000)
 * d일 ( 10000)
 * p원 ( 10000)
 */

#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;
int n, p, d, money = 0, cd, cp;
priority_queue<int, vector<int>, greater<int>> pq;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> p >> d;
        v.push_back({d, p});
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        pq.push(v[i].second);  // 현재 날짜에서 가능한 강의

        if (pq.size() > v[i].first) {  // v[i].first(일) 까지 하루에 1개씩
            pq.pop();                  // 가장 pay가 큰 v[i].first (개)
        }
    }

    while (!pq.empty()) {
        money += pq.top();
        pq.pop();
    }

    cout << money << '\n';

    return 0;
}
