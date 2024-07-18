/**
 * 교차하는 전깃줄 모두 없애야함
 * 없애야 하는 전깃줄의 최소 개수
 * ㅁ
 * n = 100 ( 전깃줄 개수 )
 * A B 입력
 * 위치 번호 500이하
 * 같은 위치 2개 불가
 *
 * 개수 100
 * 위치가 500이하
 */

#include <bits/stdc++.h>

using namespace std;

int n, a, b;
int arr[504], pos[104], cnt[104];
vector<pair<int, int>> v;
int main() {
    // fill(&pos[0], &pos[0] + 104, 1); // 모든 개수는 1부터 시작

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end());  // a 위치 - b 위치

    int mmx = 0;
    for (int i = 0; i < v.size(); i++) {
        int mx = 0;
        for (int j = 0; j < i; j++) {
            if (v[j].second < v[i].second) {  // b 위치 순서 비교
                mx = max(pos[j], mx);
            }
        }

        pos[i] = mx + 1; // LIS 갱신

        cnt[mx+1] ++; // 중복되는 개수 구해야함 
    }

    int sum = 0;
    for(int i = 0; i< n; i++){
        if(cnt[i] > 0){
            sum += (cnt[i]-1);
        }
    }

    cout << sum << '\n';
    return 0;
}
