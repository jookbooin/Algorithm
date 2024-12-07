/**
 *
 * <입력>
 * n (400)
 * k (50000)
 *  - 앞에 있는 사건이 뒤에 있는 사건 보다 먼저 일어 났음
 * s (50000)
 *  - 서로 다른 두 사건의 번호
 *
 * <출력>
 * s 줄 ->
 * - 앞 먼저 : -1
 * - 뒤 먼저 : 1
 * - 모름 : 0
 *
 *
 * visited
 */

#include <bits/stdc++.h>

using namespace std;

int n, k, s, a, b, c, d;
int visited[404];
int dist[404][404];
vector<int> adj[404];

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        dist[a][b] = -1;
        dist[b][a] = 1;
    }

    for(int k = 1; k<=n; k++){
        for(int i = 1; i<=n; i++){
            for(int j = 1; j<=n; j++){
                if(dist[i][k] == 1 && dist[k][j] ==1){
                    dist[i][j] = 1;
                }else if (dist[i][k] == -1 && dist[k][j] == -1){
                    dist[i][j] = -1;
                }
            }
        }
    }
    

    cin >> s;
    for (int i = 0; i < s; i++) {
        cin >> c >> d;
        cout << dist[c][d] << '\n';
    }

    return 0;
}