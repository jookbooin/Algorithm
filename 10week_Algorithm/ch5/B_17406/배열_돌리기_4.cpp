/**
 * 행 : N 50
 * 열 : M 50
 * K = 6
 * A[i][j] = 100
 * 1 <= r-s < r+s <= 50
 * 1 <= c-s < c+s <= 50
 *
 * 1. 회전 연산 (r,c,s) 순서 임의로 정함
 *    - 시계 방향 1칸
 *    - 가장 왼쪽 윗 칸 ( r-s, c-s )
 *    - 가장 오른쪽 아랫 칸 ( r+s, c+s )
 *
 * 2. 행들의 합 계산 -> 최소 구함
 *
 */

#include <bits/stdc++.h>

using namespace std;
int graph[54][54];
int temp[54][54];

int n, m, k, r, c, s;
const int INF = 987654321;
int mi = INF;

struct rot {
    int a, b, c;
    rot(int _a, int _b, int _c) : a(_a), b(_b), c(_c) {}
};

vector<rot> v;
vector<int> v_idx;  // permutaion 돌리기 위한 idx

void cal(int arr[54][54]) {
    for (int i = 1; i <= n; i++) {
        int sum = 0;
        for (int j = 1; j <= m; j++) {
            sum += arr[i][j];
        }
        mi = min(mi, sum);
    }
}

void go(int arr[54][54], int r, int c, int s) {
    for (int i = 1; i <= s; i++) {
        int top = r - i, bottom = r + i, left = c - i, right = c + i;
        int tmp = arr[top][left];

        // 왼쪽
        for (int j = top; j < bottom; j++) {
            arr[j][left] = arr[j + 1][left];
        }

        // 아래쪽
        for (int j = left; j < right; j++) {
            arr[bottom][j] = arr[bottom][j + 1];
        }

        // 오른쪽
        for (int j = bottom; j > top; j--) {
            arr[j][right] = arr[j - 1][right];
        }

        // 위쪽
        for (int j = right; j > left; j--) {
            arr[top][j] = arr[top][j - 1];
        }

        arr[top][left + 1] = tmp;
    }
}

int main() {
    cin >> n >> m >> k;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < k; i++) {
        cin >> r >> c >> s;
        v.push_back(rot(r, c, s));
        v_idx.push_back(i);
    }

    // 순열
    do {
        // 1. graph 원본 초기화
        memcpy(temp, graph, sizeof(graph));

        // 2. 회전 경우의 수
        for (int i : v_idx) {
            // 3. 회전 r c s
            go(temp, v[i].a, v[i].b, v[i].c);
        }

        // 4. 행별 합 계산
        cal(temp);

    } while (next_permutation(v_idx.begin(), v_idx.end()));

    cout << mi << '\n';

    return 0;
}