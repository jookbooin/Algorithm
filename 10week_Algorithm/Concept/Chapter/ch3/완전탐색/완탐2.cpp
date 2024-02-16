// ��ö�̴� ���� ���� ���� �������� �ö��ִ�.
// �� ������ �״�� �������θ� ������ ������ 100������ ����ڰ� �߻��Ѵ�.
// ������ ���ߴ� ����� ������ Ư�� ��ġ�� �伮�� ������ �ȴ�.
// �ش� ��ġ���� ���ڰ� ǥ�Ⱑ �Ǿ��ְ� �� ���� ��� ������ ���� ���Ҽ����� �� �� ������ �����.
// �� �� ���� ����� ���� �ִ��� ���϶�.
// N���� �伮 �ĺ��� ���ڿ� ���� �ٿ� �ش� ���ڵ��� ���´�. N <= 100

// input:
// 10
// 24 35 38 40 49 59 60 67 83 98

// output:
// 176


#include <bits/stdc++.h>

using namespace std;
int n, temp;
vector<int> v;

bool check(int n) {
    if (n <= 1) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;
    for (int i = 3; i * i <= n; i++) {    // i �� n�� ������ ������ �����ؾ���
        if (n % i == 0) return 0;
    }
    return 1;
}

int go(int idx, int sum) {
    if (idx == n) {
        // cout << "SUM " << sum << "\n";
        return check(sum);
    }
    return go(idx + 1, sum + v[idx]) + go(idx + 1, sum);   // ���� or ���� x
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
    }

    cout << go(0, 0) << "\n";

    return 0;
    
}
