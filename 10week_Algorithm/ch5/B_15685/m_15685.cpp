#include <bits/stdc++.h>

using namespace std;

int graph[104][104];
int visited[104][104];

int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};

int n, x, y, d, g, cnt = 0;

struct Code {
    int x, y, d, g;
    vector<int> directions;

    void makeDragon() {
        directions.push_back(d);
        for (int i = 0; i < g; i++) {
            int size = directions.size();
            for (int j = size - 1; j >= 0; j--) {
                directions.push_back((directions[j] + 1) % 4);
            }
        }
    }
};

vector<Code> vc;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        Code cc;
        cin >> cc.x >> cc.y >> cc.d >> cc.g;
        cc.makeDragon();
        vc.push_back(cc);
    }

    // 점 check
    for (Code ccd : vc) {
        int cx = ccd.x;
        int cy = ccd.y;
        visited[cy][cx] = 1;

        for (int dir : ccd.directions) {
            cx += dx[dir];
            cy += dy[dir];
            visited[cy][cx] = 1;
        }
    }

    // 사각형 개수 세기
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (visited[i][j] && visited[i + 1][j] && visited[i][j + 1] && visited[i + 1][j + 1]) {
                cnt++;
            }
        }
    }

    cout << cnt << '\n';

    return 0;
}