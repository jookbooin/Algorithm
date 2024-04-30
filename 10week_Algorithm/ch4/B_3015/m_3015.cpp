/**
 * 서로 볼 수 있으려면. A,B 사이에 AB 보다 큰 사람 없어야 함
 * n = 500 000 -> O(N), O(NlogN)
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, ret, now;
stack<ll> s;

int main(){
    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> now;

        while(s.size() && s.top() < now){ // 오름 차순 일때
            ret += 1;
            s.pop();
        }

        // 내림 차순일 때
        if(s.size()) ret++;
        s.push(now);

    }

    cout << ret<<'\n';

    return 0;
}