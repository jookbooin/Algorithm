
#include <bits/stdc++.h>

using namespace std;

/**
 * �ǹ� ���� -> Map�� ���÷ȴ�.
 * ������ map�� ��ȸ�ϱ� ���ؼ��� mp.find(c) != mp.end()�� ����ؾ��ϴ� ����
*/

map<char, int> mp;
int main(void) {
    for (int i = 97; i < 123; i++) {
        mp.insert({(char)i, 0});
    }

    string input;
    cin >> input;
    for (char c : input) {
        if (mp.find(c) != mp.end()) mp[c]++;
    }

    for (auto i : mp) cout << i.second << " ";
    return 0;
}