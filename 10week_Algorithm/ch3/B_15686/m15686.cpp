/**
 * 0 : 빈 칸
 * 1 : 집
 * 2 : 치킨 집
 *
 * N = 50, M = 13
 * 집 개수 2N 개 존재
 *
 * 치킨 거리 : 집과 가까운 치킨집 사이의 거리
 * 도시 치킨 거리 : 모든 집의 치킨 거리의 합
 *
 * 도시의 치킨집 M개 고름
 * 도시의 치킨 거리가 얼마나 작게 될까
 *
 */

/**
 * 집(1)
 * 치(2) 따로 저장
 *
 */

#include <bits/stdc++.h>

using namespace std;

int N, M, mi = 1e9, rc, cc, rh, ch, inmi, sm;
int rt, ct;
int graph[51][51];

vector<pair<int, int>> chic;  // () () () ()
vector<pair<int, int>> home;

// 도시의 거리
void cal(vector<int> b) {
    sm = 0;
    for (int j = 0; j < home.size(); j++) {
        inmi = 1e9;
        for (int i = 0; i < b.size(); i++) {
            tie(rc, cc) = chic[b[i]];  // 0 , 1 , 2
            tie(rh, ch) = home[j];
            inmi = min(inmi, abs(rc - rh) + abs(cc - ch));
        }
        sm += inmi;
    }
    mi = min(mi, sm);
}

void combi(int idx, vector<int> b) {
    if (b.size() == M) {
        // cout << "( ";
        // for (int i : b) {
        //     cout << i << " ";
        // }
        // cout << " )" << endl;
        cal(b);
        return;
    }

    for (int i = idx + 1; i < chic.size(); i++) {  // () () ()
        b.push_back(i);
        combi(i, b);
        b.pop_back();
    }
}

int main(void) {
    cin >> N >> M;

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cin >> graph[row][col];
            if (graph[row][col] == 2)
                chic.push_back({row, col});
            else if (graph[row][col] == 1)
                home.push_back({row, col});
        }
    }

    vector<int> v;      // combi 생성할떄
    combi(-1, v);

    cout << mi << endl;

    return 0;
}