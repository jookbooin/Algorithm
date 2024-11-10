/**
 * n
 * 인구 1 ~ N
 * 구역의 수 /  구역의 번호들 a-b b-a 
 * 
*/ 

#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int mi, n,m,f,asidx, bsidx,sum = 0, ret = INF;

int peo[14];
vector<int> graph[14];

bool flag;

int gcheck[14];    // 그룹 색칠용
int visited[14]; // 방문 체크용

int dfs(int cidx, int group){ // cur 111000
    
    // 방문 처리
    visited[cidx] = 1;

    // 인원 값 
    int val = peo[cidx];

    for(int next : graph[cidx]){
        if(visited[next]) continue;
        if(gcheck[next] != group) continue; // 내 그룹이 아닐 때
        
        // 지날 수 있다면
        val += dfs(next,group);
    }

    return val;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> peo[i];
        sum += peo[i]; // 최종 합 ?
    }

    // 그래프 형성
    for(int i = 1; i<=n; i++){
        cin >> f;
        for(int j = 0; j< f; j ++){
            cin >> m;
            graph[i].push_back(m);
            graph[m].push_back(i);
        }
    }

    // 만들 수 있는 그룹 수
    for(int cur = 1; cur < (1<<n); cur++){

        // 초기화
        memset(gcheck, 0, sizeof(gcheck));
        memset(visited, 0, sizeof(visited));
        asidx = -1, bsidx = -1;

        // idx 방문 표시 
        for(int i = 0; i < n; i ++){
            
            if(cur & (1<<i)){
                gcheck[i+1] = 1;
                asidx = i + 1; // A 그룹 시작 위치
            }else{
                bsidx = i + 1; // B 그룹 시작 위치
            }
        }

        int aval = dfs(asidx, 1);
        int bval = dfs(bsidx, 0);

        // 영역 2개인지 확인
        if( aval + bval == sum){ // 
            flag = true;
            ret = min(ret, abs(aval - bval));
        }
    }

    if(flag){
        cout << ret << endl;
    }else{
        cout << -1 << endl;
    }

    return 0;
}