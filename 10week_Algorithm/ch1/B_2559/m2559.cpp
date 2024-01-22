/**
 * �������� ��ĥ ������ �µ��� ���� ���� ū ���� ����ϴ� ���α׷�
 *
 * N = 100 000
 * K = �������� ��¥�� ��
 *
 * ������ �µ��� �� ==> "�ִ�" �Ǵ� ��  = ������
 *
 */

#include <bits/stdc++.h>

using namespace std;

int N, K, input, psum[100004];
int result = -10000004;

int main(void) {
    //
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //

    cin >> N >> K;

    for (int i = 1; i <= N; i++) {
        cin >> input;
        psum[i] = psum[i - 1] + input;
    }

    // psum[1] psum[2] psum[3] psum[4] ... psum[N]
    for (int i = K; i <= N; i++) {
        result = max(result, psum[i] - psum[i - K]);
    }

    cout << result << '\n';

    return 0;
}
