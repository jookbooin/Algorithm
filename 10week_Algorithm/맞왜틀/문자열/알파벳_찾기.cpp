#include <bits/stdc++.h>

using namespace std;

int alpha[26];
string s;

int main() {
    cin >> s;
    fill(&alpha[0], &alpha[0] + 26, -1);

    for (int i = 0; i < s.size(); i++) {
        if (alpha[s[i] - 'a'] != -1) continue;
        alpha[s[i] - 'a'] = i;
    }

    for (int i = 0; i < 26; i++) {
        cout << alpha[i] << " ";
    }

    return 0;
}