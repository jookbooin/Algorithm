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

    /** 2. next_pernutation은 오름차순이므로 213 보다 큰 경우만 나오게 된다.
     *     모든 경우를 전부 구하기 위해서는 sort를 사용해야 한다.
     * */
    vector<int> va = {2, 1, 3};
    sort(va.begin(), va.end());  

    do {
        for (int i : a) cout << i << " ";
        cout << "\n";

    } while (next_permutation(va.begin(), va.end()));

    return 0;
}