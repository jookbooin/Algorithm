/**
 * N K 500 000
 *
 * K ��ġ
 * K
 * K + 1
 * K + 1 + 2
 * K + 1 + 2 + 3
 * K + 1 + 2 + 3 + 4
 *
 * ���� ���� �ð� -> Queue???
 *
 * 1. K max_len ������ �ȵ�
 * 2. ¦�� [0][], Ȧ�� [1][]
 * 3.
 */

#include <bits/stdc++.h>

using namespace std;

const int max_len = 500000;

int N, K, turn = 1, cur;
bool flag;

int visited[2][max_len + 4];  // ¦�� �� : [0][], Ȧ�� �� : [1][]

int main(void) {
    cin >> N >> K;

    if (N == K) {
        cout << 0 << endl;
        return 0;
    }

    queue<int> q;
    visited[0][N] = 1;  // 0�� �� N ��ġ
    q.push(N);

    while (q.size()) {
        K += turn;  // K+1 K+1+2 K+1+2+3 K+1+2+3+4

        if (K > max_len) break;

        if (visited[turn % 2][K]) { // -1 +1 -1 +1 �� ��� 
            flag = 1;
            break;
        }

        int qsize = q.size();

        for (int i = 0; i < qsize; i++) {  // 1 3 9 27

            cur = q.front();
            q.pop();

            for (int next : {cur - 1, cur + 1, cur * 2}) {  // ������ �����̴� ��

                if (next < 0 || next > max_len || visited[turn % 2][next]) continue;

                visited[turn % 2][next] = visited[(turn + 1) % 2][cur] + 1;

                if (next == K) {
                    flag = 1;
                    break;
                }

                q.push(next);
            }
            if (flag) break;
        }
        if (flag) break;
        turn++;  // ���� ���� 0 1 2 3
    }

    if (flag) {
        cout << turn << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}