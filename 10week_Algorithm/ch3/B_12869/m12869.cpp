/**
 * 9 3 1
 * 뮤탈리스크가 공격을 할 때, 한 번에 세 개의 SCV를 공격
 * 모든 scb 파괴하기위해 공격해야하는 최솟값
 */

/**
 * 9 1 3
 * 3 9 1
 */

#include <bits/stdc++.h>

using namespace std;

int N, cnt = 1e9;
int val[3], hp[64][64][64];
int a, b, c;

// vector<tuple<int,int,int>> 보다 다루기 쉽다고 한다
int graph[6][3] = {{9, 1, 3},
                   {9, 3, 1},
                   {1, 9, 3},
                   {3, 9, 1},
                   {1, 3, 9},
                   {3, 1, 9}};

struct HP {  // 3점을 다룰때 간단히 다루기 위해서
    int o, s, t;
};

// 0 0 0 인 점의 최소 값
void back(int one, int second, int third) {

    hp[one][second][third] = 1;     // 처음 
    queue<HP> q;
    q.push({one, second, third});

    while (q.size()) {
        int co = q.front().o;
        int cs = q.front().s;
        int ct = q.front().t;
        q.pop();

        if (hp[0][0][0]) break;    // 종료 조건

        for (int i = 0; i < 6; i++) {
            int no = max(0, co - graph[i][0]);
            int ns = max(0, cs - graph[i][1]);
            int nt = max(0, ct - graph[i][2]);

            if (hp[no][ns][nt]) continue;  // 해당 점을 지난적이 있다면 pass

            hp[no][ns][nt] = hp[co][cs][ct] + 1;
            q.push({no, ns, nt});
        }
    }
}

int main(void) {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> val[i];
    }

    back(val[0], val[1], val[2]);

    cout << hp[0][0][0] - 1 << endl;

    return 0;
}
