/**
 * N x N 크기의 땅
 * 가장 처음 모든 칸 양분 5 : food[r][c]
 * 각 칸에 추가되는 양분 : A[r][c]
 *
 * <봄>
 * - 나무 자신 나이 만큼 양분 먹음
 * - 나이 1 증가
 * - 여러개의 나무가 있다면 어린 나무부터 양분을 먹음
 * - 칸에 ( 양분 < 나이 ) 인 나무는 죽는다.
 *
 * <여름>
 * - 죽은 나무 양분이 된다.
 * - 죽은 나무 나이 / 2 한 값이 양분으로 추가
 *
 * <가을>
 * - 나무 나이 5의 배수면 나무 8방향 번식
 *
 * <겨울>
 * - 땅에 양분 추가 A[r][c]
 *
 * k년 지난 후 살아있는 나무 개수
 *
 * <입력>
 * n (n줄 A배열), m (나무 정보), k(년)
 *
 * 1000 * 4 * [ 10 * 10 * (100) ]
 *
 * 나무가 죽는 것 어떻게 표현
 * 나무가 생기는 것 어떻게 표현
 *
 * 삭제할 때
 * 1. 정렬 ( 0, )
 *
 */
#include <bits/stdc++.h>

using namespace std;

int dr[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dc[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

typedef struct _block {
    // true, 나이
    deque<int> dq;
} block;

block brr[14][14];
int n, m, k, r, c, age, cnt = 0;
int food[14][14], a[14][14];

void spring_summer() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int live = 0;

            // dq 존재할 때
            if (brr[i][j].dq.size()) {
                for (int& a : brr[i][j].dq) {
                    // 양분 >= 나이
                    if (food[i][j] >= a) {
                        // 나무가 나이만큼 양분 먹음
                        food[i][j] -= a;

                        // 나이 증가
                        a++;

                        live++;
                    } else {  // 죽은 것들
                        break;
                    }
                }

                // 여름
                int dq_size = brr[i][j].dq.size();
                for (int o = dq_size - 1; o >= live; o--) {
                    // 양분 추가
                    food[i][j] += (brr[i][j].dq[o] / 2);

                    // 제거
                    brr[i][j].dq.pop_back();
                }
            }
        }
    }
}

void fall_winter() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // dq가 존재한다면
            if (brr[i][j].dq.size()) {
                for (int a : brr[i][j].dq) {
                    if (a % 5 == 0) {
                        for (int o = 0; o < 8; o++) {
                            int nr = i + dr[o];
                            int nc = j + dc[o];

                            if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;

                            // front로 1 추가
                            brr[nr][nc].dq.push_front(1);
                        }
                    }
                }
            }

            // 겨울
            food[i][j] += a[i][j];
        }
    }
}

int tree_count() {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // 나무 개수

            sum += brr[i][j].dq.size();
        }
    }

    return sum;
}

int main() {
    cin >> n >> m >> k;

    // 칸 양분
    fill(&food[0][0], &food[0][0] + 14 * 14, 5);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    // 나무 입력
    for (int i = 0; i < m; i++) {
        cin >> r >> c >> age;
        brr[r][c].dq.push_back(age);
    }

    for (int i = 0; i < k; i++) {  // k년
        spring_summer();
        fall_winter();
    }

    cout << tree_count() << endl;

    return 0;
}