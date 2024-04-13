/**
 *  N인 조각은 N자리 수
 *
 */

#include <bits/stdc++.h>

using namespace std;

int graph[5][5];
int visited[5];  // row -> 기준
int n, m, ret = 0;
string row;

int count() {
    int ans = 0;
    for (int r = 0; r < n; r++) { // row
        int sum = 0;
        for (int c = 0; c < m; c++) { // col

            if(visited[r] & (1<<c)){  // 가로 영역 
                sum = sum*10 + graph[r][c]; 
            }else{                    // 세로 영역
                ans += sum;
                sum = 0;
            }
        }
        ans += sum;
    }

    for(int c = 0; c < m; c++){
        int sum = 0;
        for(int r = 0; r < n; r ++){
            if(!(visited[r] & (1 << c))){
                sum = sum*10 + graph[r][c];
            }else{
                ans += sum;
                sum = 0;
            }
        }
        ans += sum;
    }
    return ans;
}   

void go(int depth) {
    if (depth == n) {
        ret = max(ret, count());
        return;
    }

    for (int c = 0; c < (1 << m); c++) {  // col
        visited[depth] = c;              // 가로로 지나는 점 check
        go(depth + 1);
    }
}

int main() {
    cin >> n >> m;

    for (int r = 0; r < n; r++) {
        cin >> row;
        for (int c = 0; c < m; c++) {
            graph[r][c] = row[c] -'0';
        }
    }

    go(0) ;
    cout << ret <<'\n';

    return 0;
}