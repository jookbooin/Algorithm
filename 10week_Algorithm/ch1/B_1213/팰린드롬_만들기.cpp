#include <bits/stdc++.h>
using namespace std;

int alpha[26];  // 알파벳 등장 횟수를 저장할 배열
string input, front = "", mid = "";

int main() {
    cin >> input;

    for (char c : input) {
        alpha[c - 'A']++;
    }

    int flag = 0, n = input.size();

    for (int i = 0; i < 26; i++) {
        if (alpha[i]) {
            if (alpha[i] & 1) {
                mid += (i + 'A');
                flag++;
                alpha[i]--;
            }

            if (flag == 2) break;

            for (int j = 0; j < alpha[i]; j+= 2) {
                front += (i + 'A');
            }
        }
    }

    if (flag == 2) {
        cout << "I'm Sorry Hansoo" << '\n';
        return 0;
    }

    string ret = front + mid;
    reverse(front.begin(), front.end());
    ret += front;

    cout << ret << '\n';

    return 0;
}