#include <bits/stdc++.h>
using namespace std;

// counting -> map or 배열

int N, arr[26];
string s, result;
int main(void) {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> s;
        arr[s[0] - 'a']++;  // string[0] = char 형
    }

    for (int i = 0; i < 26; i++) {
        if (arr[i] >= 5) result += i + 'a';  // 문자열을 더하는 것
    }

    if (result.size())
        cout << result << "\n";
    else
        cout << "PREDAJA" << "\n";

    return 0;
}