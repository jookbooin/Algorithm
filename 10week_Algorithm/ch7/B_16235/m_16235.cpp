
#include <bits/stdc++.h>

using namespace std;

int dr[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dc[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

typedef struct _block {
    // true, 나이
    deque<int> dq;
} block;

deque<int> brr[14][14];
int n, m, k, r, c, age, cnt = 0;
int food[14][14], a[14][14];

void spring_summer() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int live = 0;

            // dq 존재할 때
            if (brr[i][j].size()) {
                for (int& a : brr[i][j]) {
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
                int dq_size = brr[i][j].size();
                for (int o = dq_size - 1; o >= live; o--) {
                    // 양분 추가
                    food[i][j] += (brr[i][j][o] / 2);

                    // 제거
                    brr[i][j].pop_back();
                }
            }
        }
    }
}

void fall_winter() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // dq가 존재한다면
            if (brr[i][j].size()) {
                for (int a : brr[i][j]) {
                    if (a % 5 == 0) {
                        for (int o = 0; o < 8; o++) {
                            int nr = i + dr[o];
                            int nc = j + dc[o];

                            if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;

                            // front로 1 추가
                            brr[nr][nc].push_front(1);
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

            sum += brr[i][j].size();
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
        brr[r][c].push_back(age);
    }

    for (int i = 0; i < k; i++) {  // k년
        spring_summer();
        fall_winter();
    }

    cout << tree_count() << endl;

    return 0;
}