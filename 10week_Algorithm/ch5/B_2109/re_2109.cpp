/***
 * d일 안에 강의를 와야한다.
 * 가장 p가 큰 강의를 찾으면 된다.
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

    // d, p 오름 차순
    sort(v.begin(), v.end());

    /**
     * 2일짜리가 3개 있을 수도 있음
     */

    
    for(int i = 0; i<n; i++){
        pq.push(v[i].second);

        if(pq.size() > v[i].first){ // 날짜 제한 
            pq.pop();
        }
    }

    int sum = 0;
    // 마지막 v[i].first 만큼 남아있을 것 
    while(pq.size()){
        sum += pq.top();
        pq.pop();
    }

    cout << sum << endl;

    
    return 0;
}