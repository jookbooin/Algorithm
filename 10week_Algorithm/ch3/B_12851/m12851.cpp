/**
 * N K 100 000
 *
 * 걸음 -1 +1
 * 순간이동  2*X
 *
 *  동생을 찾을수 있는 가장 빠른 시간
 * + 몇 가지 방법
 */

/**
 * - 1
 * + 1
 * * 2
 *
 * 횟 수 찾기
 * 가장 작은 순간 -> cnt = 0
 *               -> 같은 depth + 값 cnt ++
 *
 * 1. 3 재귀
 * 2. dp 2개?
 */

#include <bits/stdc++.h>

using namespace std;

int N, K, cur, depth, mi = 1e9;
int val[100004];      //
int visited[100004];  // 특정 depth 방문 처리

void check(int start) {
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = 1;

    while (q.size()) {
        tie(cur, depth) = q.front();
        q.pop();

        if(!visited[cur] )

        if(!visited[cur] && cur == K){ // 목적지에 첫 방문
            val[cur] = depth;   // 최소 시간
            visited[cur] = 1;
        }else if(cur == K && val[cur] == depth) { // 목적지 방문 o + 최소 거리 일때
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

    // 최소 횟수 찾아야 함.
    // 방법 수 찾아야 함

    cout << val[K] << endl;
    cout << visited[K] << endl;

    return 0;
}
