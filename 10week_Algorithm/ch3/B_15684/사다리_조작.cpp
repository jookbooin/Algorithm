/**
 * i번 세로선의 결과가 i번으로 나오기 위해 추가해야하는 가로선 개수의 최소값
 *
 * N(10), H(30), M((N-1)*H)
 * N (세로선) M(가로선) H(세로선 마다 가로선을 놓을 수 있는 위치)
 *
 * 3보다 큰 값이면 -1, 불가능 -1
 * 300 C 10 은 완탐 불가
 * 개수가 300 C 3
 *
 * 완탐일까...?  백트래킹일까...?
 *
 *  a <= H, b <= N-1
 *
 */

#include <bits/stdc++.h>

using namespace std;
const int INF = 987654321;
int N, H, M, a, b,  ret = INF;
int line[34][34];  // row, col

bool check(){ // 시작 종료 i 번째 인 것

    for(int col = 1; col <= N; col ++){          // 시작점 결정
        int cur = col;
        for(int row = 1; row <= H; row ++){      // 아래로 내려감
            if(line[row][cur]) cur++;
            else if(line[row][cur-1]) cur --;
        }
        if(cur != col) return false;
    }
    return true;
}

void go(int here, int cnt) {

    if(cnt > 3 || cnt >= ret ) return ; // 최솟값 일때

    // 시작 <-> 끝점 일치하는지 확인
    if(check()){  
        ret = min(ret,cnt);
        return;
    }

    // 세로부터 라인을 그리는 작업
    for (int row = here; row <= H; row++) {
        for (int col = 1 ; col < N; col++) {
            if(line[row][col] || line[row][col-1] || line[row][col+1]) continue; // 라인 존재
            line[row][col] = 1;
            go(row, cnt+1);         // row 지점 부터 
            line[row][col] = 0;
        }
    }

}

int main(void) {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> H;  // 세로선, 가로선, 세로선 마다 사다리 놓을 수 있는 위치 개수 (높이)

    for (int i = 0; i < M; i++) {  // M개 가로선 개수

        cin >> a >> b;   // a번 줄
        line[a][b] = 1;  // b b+1 잇는 선
    }

    go(1, 0);
    cout << ((ret == INF) ? -1 : ret) << "\n";


    return 0;
}