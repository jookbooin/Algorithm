
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;  // unsigned 부호 없는 정수 - 표현 범위 모두 +에 추가

const ll max_value = 1000000000;
int N, ni;
int input;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> input;

        int result = 0;

        for (int i = 5; i < input; i *=) {
            result += input / i;
        }

        cout << result << '\n';
    }

    return 0;
}

/**
 * 1 2 3 4 5
 *
 */