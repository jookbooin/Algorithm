#include <bits/stdc++.h>
using namespace std;

map<int, int> mp;
map<string, string> mp2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // map�� [ ] �� ����ϸ� map�� �ٷ� �߰��ȴ�.
    if (mp[2] == 0) {
        for (auto i : mp) cout << i.first << " " << i.second << '\n';
        mp[2] = 3;
    }

    for (auto i : mp) cout << i.first << " " << i.second << '\n';


    // ��ȯ�Ǵ� '������ ��� ����'�� ����Ű�� �ݺ��ڸ� ��ȯ
    // 1�� ��Ұ� ���ٴ� ���� �ǹ�
    if (mp.find(1) == mp.end()) {
        mp[1] = 2;
    }

    for (auto i : mp) cout << i.first << " " << i.second << '\n';

    return 0;
}