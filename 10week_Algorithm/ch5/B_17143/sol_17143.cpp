#include <bits/stdc++.h>
#define max_n 100

using namespace std;

struct Shark {
    int y, x, s, dir, z, death;
};
Shark a[max_n * max_n];
const int dx[] = {0, 0, 1, -1};
const int dy[] = {-1, 1, 0, 0};

int R, C, M, ret;
int shark[max_n][max_n], temp[max_n][max_n];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> R >> C >> M;

    for (int i = 1; i <= M; i++) {
        cin >> a[i].y >> a[i].x >> a[i].s >> a[i].dir >> a[i].z;

        // 시작점 0,0
        a[i].y--;
        a[i].x--;

        // 방향 0 1 2 3 4로 조정
        a[i].dir--;

        if (a[i].dir <= 1) {  // 위 아래
            a[i].s %= (2 * (R - 1));
        } else {  // 좌 우
            a[i].s %= (2 * (C - 1));
        }

        // 번호 저장
        shark[a[i].y][a[i].x] = i;
    }

    for (int t = 0; t < C; t++) {
        // 1. 상어 잡음
        for (int y = 0; y < R; y++) {
            if (shark[y][t]) {
                a[shark[y][t]].death = 1;
                ret += a[shark[y][t]].z;

                // 상어 제거
                shark[y][t] = 0;
                break;
            }
        }

        memset(temp, 0, sizeof(temp));
        for (int i = 1; i <= M; i++) {
            if (a[i].death) continue;  // 죽은 상어는 확인하지 않는다.

            int y = a[i].y;
            int x = a[i].x;
            int s = a[i].s;
            int d = a[i].dir; 
			int ny, nx; 

            while (1) {  
                // 현재 위치로부터 이동
                ny = y + s * dy[d];
				nx = x + s * dx[d]; 

                if (nx < C && ny < R && ny >= 0 && nx >= 0)break;

                if(d <= 1){
                    
                }else{ 

                }
            }
            
        }

    }

    return 0;
}
