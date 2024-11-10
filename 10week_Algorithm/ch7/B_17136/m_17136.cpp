/**
 * 1x1 ~ 5x5 : 각각 5개씩
 * color = { 0, 5, 5, 5, 5, 5 };
 * 
 * 1을 모두 덮는 것이 불가능 : -1
 *      - 종이 개수가 부족할 때
 * 
 * 
 * 정사각형인지 판단
 * 
 * n = 10
 * 
 * - 1만나면 (5, 4, 3, 2, 1) 붙일 수 있는지 확인 
 *   색종이 붙어있는지 확인 (cr, cc, size)
 * 
 * - 색종이 붙인다.         (cr, cc, size)
 * - 색종이 제거           (cr, cc, size)
 */
#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
int graph[14][14], paper[14][14];
int ret = INF;
int ptype[6] = {0,5,5,5,5,5};

bool check(int cr, int cc, int size) {
    if (cr + size > 10 || cc + size > 10) return false;
    
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (graph[cr + i][cc + j] == 0 || paper[cr + i][cc + j] != 0) return false;
        }
    }
    return true;
}

void attach(int cr, int cc, int size) {
    ptype[size]--;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            paper[cr + i][cc + j] = size;
        }
    }
}

void detach(int cr, int cc, int size) {
    ptype[size]++;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            paper[cr + i][cc + j] = 0;
        }
    }
}

void dfs(int cr, int cc, int pcnt){

    // 최솟값 구해야 함
    if(pcnt >= ret) return;

    if(cc == 10){
        dfs(cr+1,0,pcnt);
        return;
    }

    if(cr == 10){
        ret = min(ret, pcnt);
        return ;
    }

    if(graph[cr][cc] == 0){ 
        dfs(cr, cc+1, pcnt);
        return ;
    }

    // 5, 4, 3, 2, 1 종이 붙이기
    for(int size = 5; size>=1; size--){ 
        if(ptype[size] <= 0) continue ;

        if(check(cr,cc,size)){  
            attach(cr,cc,size); // 붙인다. cnt + 1

            // size만큼 이동 
            dfs(cr ,cc + size , pcnt+1);

            detach(cr,cc,size); // 뗀다.   cnt
        }
    }

}

int main(){

    int graph_cnt= 0;
    for(int i = 0; i< 10; i++){
        for(int j = 0; j<10; j++){
            cin >> graph[i][j];
        }
    }

    dfs(0,0,0);

    if(ret == INF){
        cout << -1 << '\n';
    }else{
        cout << ret << '\n';
    }

    return 0;
}


