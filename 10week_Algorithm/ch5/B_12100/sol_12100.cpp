/**
 * 4방향으로 이동 : 1방향 * rotate90
 *
 *
 */

#include <bits/stdc++.h>

using namespace std;

int n, mx;

struct Board {
    int graph[24][24];

    void rotate90() {
        int temp[24][24];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                temp[i][j] = graph[n - j - 1][i];  // temp는 a 를 90 rotate한 배열
            }
        }
        memcpy(graph, temp, sizeof(graph));
    }

    void move() {
        int temp[24][24] ={0};

        for (int i = 0; i < n; i++) {
            int c = -1;
            bool flag = false;

            for (int j = 0; j < n; j++) {
                if (graph[i][j] == 0) continue;  // 0 패스

                // 마지막 위치 c와 비교
                if (flag && temp[i][c] == graph[i][j]) {  
                    temp[i][c] *= 2;
                    flag = false;  
                } else {
                    temp[i][++c] = graph[i][j];
                    flag = true;    
                }
            }

        }

        // board 내부의 graph에 temp 복사
        memcpy(graph, temp, sizeof(graph));
    }

    void get_max() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mx = max(mx, graph[i][j]);
            }
        }
    }
};

void go(Board b, int here) {
    if (here == 5) {
        b.get_max();
        return;
    }

    // 4방향
    for (int i = 0; i < 4; i++) {
        // 복사
        Board tmp = b;

        // 이동
        tmp.move();

        // 이 형태에서 다음 단계로
        go(tmp, here + 1);

        // 원본 회전
        b.rotate90();
    }

    return ;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    Board b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> b.graph[i][j];
        }
    }

    go(b, 0);
    b.get_max();

    cout << mx <<'\n';

    return 0;
}