#include <bits/stdc++.h>

using namespace std;

int n, cnt, ret;
string str;
stack<int> s;

int main() {
    cin >> n;
    cin >> str;

    s.push(-1);                 // -1
    for (int i = 0; i < n; i++) {
        if (str[i] == '(') s.push(i);
        if (str[i] == ')') {
            s.pop();            // 우선 pop 

            if (!s.empty()) {
                ret = max(ret, i - s.top());    // 거리 재기 
            } else {
                s.push(i); // 분기점을 만들기 위해서  ) ( ) 7 -(5) = 2
            }
        }
    }

    cout << ret << '\n';

    return 0;
}