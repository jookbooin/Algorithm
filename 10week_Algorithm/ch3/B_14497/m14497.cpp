/**
 *  0�� �� ����, 1�� ģ��, *�� �ֳ�, #�� ����
 * 
 *  N M 300
 * 900 000
*/

// 0 �������鼭 -> 1 �ϳ��� ������ ������ �� �ߴ�

// 1#10111
// 1100001
// 000*011
// 1100111
// 0011001

#include <bits/stdc++.h>

using namespace std;
const int max_len = 304;
int N,M , jrow, jcol, trow,tcol,crow,ccol,cnt;
char graph[max_len][max_len];
int visited [max_len][max_len];
bool flag;


int dr[4] = {-1, 0, 1, 0};
int dc[4] = { 0, 1, 0, -1};

int main(void){

    cin >> N >> M;
    cin >> jrow >> jcol >> trow >> tcol;

    for(int row = 1; row <= N; row ++){
        for(int col = 1; col <=M; col++){
            cin >> graph[row][col];
        }
    }

    // �ܰ踶�� jrow, jcol �������� ���� -> trow, tcol ������ ����

    // 1 �ܰ�
    queue<pair<int,int>> q;

    while(!flag){   // # �������� ������
        fill(&visited[0][0] , &visited[0][0] + max_len*max_len,0);
        cnt ++;
        q.push({jrow,jcol});

        visited[jrow][jcol] = 1;

        while(q.size()){
            crow = q.front().first;
            ccol = q.front().second;
            q.pop();

            for(int i =0 ; i<4; i++){
                int nrow = crow + dr[i];
                int ncol = ccol + dc[i];

                if(nrow < 1 || nrow >N || ncol < 1 || ncol > M || visited[nrow][ncol]) continue;
                
                visited[nrow][ncol] = 1;

                if(graph[nrow][ncol] == '1'){
                    graph[nrow][ncol] = '0';
                    continue;
                }

                if(nrow == trow && ncol == tcol){
                    flag = 1;
                    break;
                }
                
                q.push({nrow,ncol});
            }

            if(flag) break;
        }
        if(flag) break;
    }
    
    cout << cnt << endl;
    
    return 0;
}