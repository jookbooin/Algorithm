#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main() {
    for (int i = 1; i <= 5; i++) {
        v.push_back(i);
        v.push_back(i);
    }

    for (int i : v) cout << i << " ";
    cout << '\n';

    // �ߺ����� ���� ��ҷ� ä�� ��, �� ���� ���ͷ����͸� ��ȯ�Ѵ�.
    auto it = unique(v.begin(), v.end());
    cout << it - v.begin() << '\n';

    // �տ��� ���� �ߺ����� �ʰ� ä�� �� ������ ��ҵ��� �״�� �д�.
    for (int i : v) cout << i << " ";
    cout << '\n';

    return 0;
}
