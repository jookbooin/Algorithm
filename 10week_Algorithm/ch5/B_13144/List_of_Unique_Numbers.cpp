/**
 * N = 100 000
 * 연속한 수 1개 이상 뽑았을때 -> 같은 수 여러번 등장 X
 * 
 * 구간 : 투포인터? 
 *
 * 확인 배열 필요
 *
 */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int INF = 100004;
int visited[INF];

ll cnt = 0;
int n, input, st, ed;
vector<int> vec;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> input;
        vec.push_back(input);
    }

    st = ed = 0;

    for (int st = 0; st < n; st++) {  // 시작점
        
        while(ed < n){
            if(visited[vec[ed]]){  // (다음) 중복된 수 만날때 중단
                break;
            }
        
            visited[vec[ed++]] =1;
        }

        cnt += ed - st;       // ed++ 되어 있음
        visited[vec[st]] = 0; // st가 포함되지 않을때
    }

    cout << cnt << '\n';

    return 0;
}
