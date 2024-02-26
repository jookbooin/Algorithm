/**
 * 1. ���� ã�� ���� ���� ���
 * 2. ��� �̵��ؾ��ϴ��� �������� ������ ���
 *
 * �ִܰŸ� : bfs
 */

/**
 * // 1. �ִ� �Ÿ� ���ϱ�
 * // 2. 1 ���� ���
 *
 * (*2) - (-1) - (*2) - (+1)
 * (-1) - (*2) - (*2) - (+1)
 */

#include <bits/stdc++.h>

using namespace std;

int N, K , ret;
const int max_len = 200004;
int visited[max_len] , pre[max_len];

int main(void) {
    cin >> N >> K;

    queue<int> q;

    q.push(N);

    visited[N] = 1;

    while (q.size()) {
        int cur = q.front();
        q.pop();

        if (cur == K) {
            ret = K;
            break;
        }

        for(int next : {cur - 1 , cur + 1, cur * 2}){
            if(next < 0 || next >= max_len || visited[next]) continue;

            pre[next] = cur;
            visited[next] = visited[cur] + 1;
            q.push(next);
        }

    }

    cout << visited[K] - 1 << endl;
    vector<int> v;

    for(int i = K; i != N; i = pre[i]){
        v.push_back(i);
    }

    v.push_back(ret);

    reverse(v.begin(),v.end());
    for(int a : v) cout << a << " ";

    return 0;

}
