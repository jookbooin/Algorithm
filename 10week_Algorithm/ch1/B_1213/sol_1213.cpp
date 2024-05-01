#include <bits/stdc++.h>
using namespace std;
string s, ret;
int alpha[26], flag;
char mid;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;

    for (char idx : s) alpha[idx]++;  // 알파벳 개수

    for (int i = 'Z'; i >= 'A'; i--) {  // char 형 -> 숫자로 반복문
        if (alpha[i]) {
            if (alpha[i] & 1) {  // 홀 수 일때
                mid = char(i);
                flag++;  // 홀수 개수 확인
                alpha[i]--;
            }

            if (flag == 2) break;

            for (int j = 0; j < alpha[i]; j += 2) {
                ret = char(i) + ret;   // 앞에 추가
                ret += char(i);        // 뒤에 추가
            }
        }
    }

    if (mid) ret.insert(ret.begin() + ret.size() / 2, mid); // 원하는 위치에 mid 추가
    if(flag == 2) cout << "I'm Sorry Hansoo\n";
    else cout << ret << "\n";

    return 0;
}