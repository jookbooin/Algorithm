/**
 * N K 100 000
 *
 * ���� -1 +1
 * �����̵�  2*X
 *
 *  ������ ã���� �ִ� ���� ���� �ð�
 * + �� ���� ���
 */

/**
 * - 1
 * + 1
 * * 2
 *
 * Ƚ �� ã��
 * ���� ���� ���� -> cnt = 0
 *               -> ���� depth + �� cnt ++
 *
 * 1. 3 ���
 * 2. dp 2��?
 */

#include <bits/stdc++.h>

using namespace std;

int N, K, cur, depth, mi = 1e9;
int val[100004];      //
int visited[100004];  // Ư�� depth �湮 ó��

void check(int start) {
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = 1;

    while (q.size()) {
        tie(cur, depth) = q.front();
        q.pop();

        if(!visited[cur] )

        if(!visited[cur] && cur == K){ // �������� ù �湮
            val[cur] = depth;   // �ּ� �ð�
            visited[cur] = 1;
        }else if(cur == K && val[cur] == depth) { // ������ �湮 o + �ּ� �Ÿ� �϶�
            visited[cur] ++;
        }

        visited[cur] = 1;

        if(cur * 2 <= 100000)

    }
}

int main(void) {
    cin >> N >> K;
    fill(&val[0], &val[0] + 100004, 1e9);

    check(N);

    // �ּ� Ƚ�� ã�ƾ� ��.
    // ��� �� ã�ƾ� ��

    cout << val[K] << endl;
    cout << visited[K] << endl;

    return 0;
}
