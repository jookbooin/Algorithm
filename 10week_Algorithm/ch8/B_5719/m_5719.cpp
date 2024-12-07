#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int n, m, x, y, z, s, e;
int a[504][504], dist[504];
const int INF = 987654321; 

void di(){
    fill(&dist[0], &dist[0] + 504, INF);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    dist[s] = 0;
    pq.push({s,0});

    while(!pq.empty()){
        int here = pq.top().first;
        int here_cost = pq.top().second;
        pq.pop();

        for(int i = 0; i<n; i++){

            if(a[here][i] == -1) continue; // 지날 수 없음 
            int val = a[here][i];
            
            if(dist[i] > dist[here] + val){ // 최솟값 갱신 
                dist[i] = dist[here] + val;
                pq.push({i, dist[i]});
            }
        }
    }
}

void re(){ // 지난점 제거해야함
    queue<int> q;
    q.push(e);

    while(!q.empty()){
        int cv = q.front();
        q.pop();

        for(int i = 0; i<n; i++){ // 지나는 점 확인 

            // 지날 수 없다면 
            if(dist[i] == dist[cv] + a[cv][i] && a[cv][i] != -1){ 
                a[cv][i] = -1;
                q.push(i);
            }
        }    
    }

}

int main(){
    while(1){
        scanf("%d%d", &n, &m);
        if(n == 0 && m == 0) break;
        memset(a, -1, sizeof(a));
        for(int i = 0; i<m; i++){
            scanf("%d%d%d", &x, &y, &z);
            a[x][y] = z;
        }

        di(); // 
        re();
        di();

        printf("%d\n", dist[e] == INF ? -1 : dist[e]);

    }
    return 0;
}