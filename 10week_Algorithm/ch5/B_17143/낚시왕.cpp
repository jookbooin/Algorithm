
#include <bits/stdc++.h>

using namespace std;

// 위:1, 아래:2, 오:3, 왼:4
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int R, C, M, sum;

struct shark {
    int r, c, s, d, z;

    pair<int, int> mov() {

        // '최종적으로' 이동해야하는 칸수로 줄이기
        int movs = s;
        if(d==1 ||d==2) movs %= 2 * (R-1);
        else if(d == 3 || d ==4 ) movs %= 2 * (C-1);

        // '최종적으로' 이동해야하는 칸수만큼 반복
        for (int i = 0; i < movs; i++) {
            if(d==1 && r==1) d =2;
            else if(d == 2 && r == R) d =1;
            else if (d== 3 && c == C) d = 4;
            else if (d == 4 && c == 1) d = 3;

            r += dr[d-1];
            c += dc[d-1];
        }

        return {r, c};
    }
};

int graph[104][104];  // 해당 위치에 존재하는 상어 번호 저장
shark sharr[10004];  // 상어 전체 정보


void cat(int cc) {
    for (int r = 1; r <= R; r++) {
        if (graph[r][cc]) {  // 해당 위치 상어 존재

            // 상어 잡음
            sum += sharr[graph[r][cc]].z;

            // 상어 삭제
            graph[r][cc] = 0;
            break;
        }
    }
}

int main() {
    // graph (1,1) -> ( r,c) 까지
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

    cin >> R >> C >> M;
    for (int i = 1; i <= M; i++) {
        // sharr에 상어 정보 저장 
        cin >> sharr[i].r >> sharr[i].c >> sharr[i].s >> sharr[i].d >> sharr[i].z;

        // graph에 상어 번호 저장
        graph[sharr[i].r][sharr[i].c] = i;
    }

    // 1.사람 한칸 이동 
    for (int i = 1; i <= C; i++) {
        
        // 2. 상어 잡음
        cat(i);

        // 그래프에 존재하는 상어
        vector<int> shv;
        for (int j = 1; j <= R; j++) {
            for (int k = 1; k <= C; k++) {
                // 상어 번호 저장
                if (graph[j][k]) {
                    shv.push_back(graph[j][k]);

                    // 그래프 초기화
                    graph[j][k] = 0;
                }
            }
        }

        // 3. check된 상어 이동
        for (int num : shv) {
            auto shpos = sharr[num].mov();

            int shr = shpos.first;
            int shc = shpos.second;

            // 4. 상어 먹음
            if (graph[shr][shc]) {
                int curnum = graph[shr][shc];
                graph[shr][shc] = (sharr[curnum].z > sharr[num].z) ? curnum : num;
            } else {
                graph[shr][shc] = num;
            }
        }
    }

    cout << sum << '\n';
    return 0;
}