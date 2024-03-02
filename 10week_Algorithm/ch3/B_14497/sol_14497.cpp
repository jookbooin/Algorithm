// Q를 2개 사용한다????

#include <bits/stdc++.h>

using namespace std;
const int max_len = 304;
int N, M, jrow, jcol, trow, tcol, crow, ccol;
char graph[max_len][max_len];
int visited[max_len][max_len];
bool flag;

int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};



int main(void) {

    cin >> N >> M;
    cin >> jrow >> jcol >> trow >> tcol;

    for (int row = 1; row <= N; row++) {
        for (int col = 1; col <= M; col++) {
            cin >> graph[row][col];
        }
    }


    queue<int> q;               // 0 일때 쓰는 큐
    q.push(1000*jrow + jcol);
    visited[jrow][jcol] = 1;
    int cnt = 0;
    
    while (graph[trow][tcol] != '0') {      // 정답 위치가 0 이 되기 전까지
        
        cnt++;
        queue<int> temp;        // 1 만났을 때 쓰는 큐
        
        while(q.size()){

            int crow = q.front() / 1000;
            int ccol = q.front() % 1000;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nrow = crow + dr[i];
                int ncol = ccol + dc[i];

                if (nrow < 1 || nrow > N || ncol < 1 || ncol > M || visited[nrow][ncol]) continue;

                visited[nrow][ncol] = cnt;
                
                if(graph[nrow][ncol] != '0'){       // 1 만났을때 단계가 증가함. -> 다음 단계에서는 1 위치부터 시작 
                    graph[nrow][ncol] = '0';
                    temp.push(1000 * nrow + ncol);
                } else
                    q.push(1000 * nrow + ncol);     // 0일때
            }
        }

        q = temp;
    }

    cout << visited[trow][tcol] << endl;

}
