#include <bits/stdc++.h>

using namespace std;
vector<int> v;

int main() {
    for (int i = 2; i <= 5; i++) v.push_back(i);
    v.push_back(7);
    cout << upper_bound(v.begin(), v.end(), 6) - v.begin() << "\n";
    // 2 3 4 5 7
    // 0 1 2 3 4 ���� �ٹ������� 4��° (7���� 6�� �� �����Ƿ�)
    cout << lower_bound(v.begin(), v.end(), 6) - v.begin() << "\n";
    // 2 3 4 5 7
    // 0 1 2 3 4 ���� �ٹ������� 4��° (7���� 6�� �� �����Ƿ�)
    cout << upper_bound(v.begin(), v.end(), 9) - v.begin() << "\n";
    // 2 3 4 5 7
    // 0 1 2 3 4 ���� �ٹ������� 5��°(7���� 9�� �� ũ�Ƿ�)
    cout << lower_bound(v.begin(), v.end(), 9) - v.begin() << "\n";
    // 2 3 4 5 7
    // 0 1 2 3 4 ���� �ٹ������� 5��°(7���� 9�� �� ũ�Ƿ�)
    cout << upper_bound(v.begin(), v.end(), 0) - v.begin() << "\n";
    // 2 3 4 5 7
    // 0 1 2 3 4 ���� �ٹ������� 0��°(0���� 2�� �� ũ�Ƿ�)
    cout << lower_bound(v.begin(), v.end(), 0) - v.begin() << "\n";
    // 2 3 4 5 7
    // 0 1 2 3 4 ���� �ٹ������� 0��°(0���� 2�� �� ũ�Ƿ�)
}