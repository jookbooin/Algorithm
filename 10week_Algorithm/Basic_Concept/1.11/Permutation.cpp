#include <bits/stdc++.h>

using namespace std;

int main() {
    // 1
    int a[] = {1, 2, 3};

    do {
        for (int i : a) cout << i << " ";
        cout << "\n";

        // }while(next_permutation(&a[0],&a[0]+3));
    } while (next_permutation(a, a + 3));

    cout << "\n";

    /** 2. next_pernutation�� ���������̹Ƿ� 213 ���� ū ��츸 ������ �ȴ�.
     *     ��� ��츦 ���� ���ϱ� ���ؼ��� sort�� ����ؾ� �Ѵ�.
     * */
    vector<int> va = {2, 1, 3};
    sort(va.begin(), va.end());  

    do {
        for (int i : a) cout << i << " ";
        cout << "\n";

    } while (next_permutation(va.begin(), va.end()));

    return 0;
}