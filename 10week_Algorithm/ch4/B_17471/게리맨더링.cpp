/**
 * n
 * 인구 1 ~ N
 * 구역의 수 /  구역의 번호들 a-b b-a 
 * 
*/ 

#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int mi, n,m, cidx, oidx, ret = INF;
int peo[14];
vector<int> graph[14];
bool flag;

int comp[14];    // 영역 색칠용 -> 2영역인지 판단해야함
int visited[14]; // 방문 여부

pair<int,int> dfs(int start,int area){
    visited[start] = 1;
    pair<int,int> ret = {1,peo[start]};

    for(int next : graph[start]){
        if(visited[next]) continue;      // 방문했는지
        if(comp[next] != area) continue; // 같은 영역이 아니라면
        pair<int,int> temp = dfs(next,area);
        ret.first += temp.first;
        ret.second += temp.second;
    }

    return ret;
}


int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 1; i<=n; i++){
        cin >> peo[i];
    }

    for(int i =1; i<=n; i++){
        int f;
        cin >> f;
        for(int j = 0; j< f; j ++){
            cin >> m;
            // 양방향
            graph[i].push_back(m);
            graph[m].push_back(i);
        }
    }

    // 양쪽 진영 0 0일 때는 제외
    for(int i = 1; i< (1 << n) - 1; i++){ // 모든 경우의 수 

        fill(&visited[0],&visited[0]+14,0);
        fill(&comp[0],&comp[0]+14,0);

        for(int j = 0; j < n; j++){ // 점

            if(i & (1 << j)){   // 1 영역에 해당
                comp[j+1] = 1; 
                cidx = j+1;
            }else{              // 1 영역에 해당 x
                oidx = j+1;
            }
        }
        
        pair<int,int> compa =dfs(cidx,1);
        pair<int,int> outa = dfs(oidx,0);

        if(compa.first + outa.first == n){  // 영역이 2개일 때
            flag = true;
            ret = min(ret, abs(compa.second - outa.second));
        }

    }

    if(flag){
        cout << ret;
    }else{
        cout << -1;
    }

    return 0;
}