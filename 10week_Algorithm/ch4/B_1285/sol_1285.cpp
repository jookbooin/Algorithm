#include <bits/stdc++.h>

using namespace std;
const int INF = 987654321;
int n, a[44], ret = INF;
string s;

void go(int here) {

    if(here == n + 1){
        int sum = 0;
        for(int i = 1; i <= (1 << (n-1)); i *= 2){  // 열(↓) 의미 : 1 2 4 8
            int cnt = 0;
            for(int j = 1; j <= n; j ++) {          // 1 10 11 100 101 110 111 .. 
                if(i & a[j]){                       // a[j] : 행 전체 의미
                    cnt ++;                         // i & a[j] : 행 & 열 통해서 T(양수) 찾기
                }    
            }
            sum += min(cnt , n-cnt);
        }
        ret = min(ret, sum);
        return ;
    }

    go(here + 1);       // 행 : 안 뒤집는 경우
     
    // HHT : 4 (001) -> (110)
    // THH : 1 (100) -> (011)
    // THT : 5 (101) -> (010)
    a[here] = ~a[here]; 
    go(here+1);         // 행 : 뒤집는 경우
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    for (int i = 1; i <= n; i++) { 
        cin >> s;
        int value = 1;
        // HHT : 0 0 1 | 4
        // THH : 1 0 0 | 1
        // THT : 1 0 1 | 5
        for (int j = 0; j < s.size(); j++) {
            if (s[j] == 'T') a[i] |= value;  // 문자열 자체를 bit를 이용해 숫자로 만들었다.
            value *= 2;
        }
    }

    go(1); // 행을 의미하는 것임
    cout << ret << '\n';

    return 0;
}