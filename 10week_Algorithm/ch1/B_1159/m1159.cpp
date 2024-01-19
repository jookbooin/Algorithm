/**
 * ���� ù ���ڰ� �������� 5�� ����
 * ���� ���� 5���� ���ٸ� -> ��� (PREDAJA)
 *
 * N ( 150 )
 *
 */

// map ���� ���� input[0] : 0

#include <bits/stdc++.h>

using namespace std;

int N, a;
string input;
map<char, int> mp;
int main(void) {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> input;
        auto it = mp.find(input[0]);
        if (it == mp.end()) {  // ��ã�´ٸ�
            mp.insert({input[0], 1});
        } else {
            mp[input[0]]++;
        }
    }

    for (auto it : mp) {
        if (it.second >= 5) {
            cout << it.first;
            a++;
        }
    }

    if (a == 0) {
        cout << "PREDAJA" << endl;
    }

    return 0;
}
