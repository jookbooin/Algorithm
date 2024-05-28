#include <bits/stdc++.h>

using namespace std;

int n;
int graph[24][24];


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    // 비트마스킹
    for(int i = 0; i < ( 1 << n); i++){
        if(__builtin_popcount(i) != n/2) continue;
        vector<int> team1, team2;
        for(int j = 0; j<n; j++){
            if(i & (1<<j)) team1.push_back(j);
            else team2.push_back(j);
        }
    }



    return 0;
}