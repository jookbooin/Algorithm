#include <algorithm>
#include <cstdio>
#include <iostream>
int n, m, a, b, c, dist[104][104];
const int INF = 987654321;
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;

    fill(&dist[0][0], &dist[0][0] + 104 * 104, INF);

    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        dist[a][b] = dist[a][b] ? min(dist[a][b], c) : c;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) {
                cout << 0 << " ";
            } else {
                int ret = dist[i][j] == INF ? 0 : dist[i][j];
                cout << ret << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
