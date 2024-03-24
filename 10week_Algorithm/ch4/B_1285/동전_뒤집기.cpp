/**
 * N 20개 이하
 * 뒷면이 위를 향하는 동전의 개수가 최소가 되도록 
 * 위 H, 뒷면 T
 *  
*/
#include<bits/stdc++.h>

using namespace std;

// H : 0 
// T : 1
// 1이 적은 것 찾기
const int INF = 987654321;
int n,tcnt,ans = INF;
char h;
int graph[24][24]; // 원본
int cop[24][24];

void gcop(){ // 원본으로 초기화
    for(int r = 0 ; r<n ; r++){
        for(int c = 0; c<n; c++){
            cop[r][c] = graph[r][c];
        }
    }
}

void rchange(int row){  // row열 모든 점 반전
    for(int c = 0; c < n; c ++){
        cop[row][c] = ~cop[row][c];
    }
}

pair<int,int> ccount(int col){
    pair<int,int> res = {0,0};
    for(int r = 0; r< n ; r++){
        if(cop[r][col] & 1){  // T 라면 
            res.first ++;
        }else{
            res.second ++;
        }
    }
    return res;
}

int main(){

    cin >> n;
    for(int r = 0 ; r<n ; r++){
        for(int c = 0; c<n; c++){
            cin >> h;
            if(h == 'T'){
                graph[r][c] = 1;
            }else{
                graph[r][c] = 0;
            }
        }
    }

    for(int i = 0; i< (1 << n);i++){
        gcop(); // 원본 복사
        
        for(int j = 0; j<n; j++){
            if(i & (1 << j)){   // 행 선택
                rchange(j);     // 행 반전
            }
        }

        tcnt = 0; // 열에서 T 개수
        for(int c = 0; c<n ; c++){
            
            pair<int,int> ret =ccount(c);
            if(ret.first > ret.second){  // T 개수 > H 개수  // 반전
                tcnt += ret.second;
            }else{                       // T 개수 <= H 개수
                tcnt += ret.first;
            }
        }

        ans = min(ans,tcnt);

    }

    cout << ans;

    return 0;
}