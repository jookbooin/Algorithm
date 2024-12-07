#include<bits/stdc++.h>
using namespace std; 
typedef pair<int, int> PI; 

int n, m, a, b, d, ret, here, cnt, dist[4001], dist_wolf[4001][2]; 

vector<PI> adj[4001];   
const int INF = 987654321;

struct ww{
    int cost, pos, tog;
};

struct compare{
    bool operator()(ww a, ww b){
        return a.cost > b.cost;
    }
};

void dikstra(){ 
    fill(dist, dist + 4001, INF);
    priority_queue<PI, vector<PI>, greater<PI>> pq; 

    dist[1] = 0; 
    pq.push(make_pair(0, 1));

    while(pq.size()){ 
        int here = pq.top().second; 
        int here_dist = pq.top().first; 
        pq.pop();   

		if(dist[here] < here_dist) continue;

        for(PI there : adj[here]){
            int next = there.second; 
            int d = there.first; 

            if(dist[next] > dist[here] + d){
                dist[next] = dist[here] + d; 
                pq.push(make_pair(dist[next], next));
            }
        }
    }
}  

void dikstra2(){ 
    fill(&dist_wolf[0][0], &dist_wolf[0][0] + 4001 * 2, INF);
    priority_queue<ww, vector<ww>, compare> pq; 
    
    dist_wolf[1][0] = 0;   
    pq.push({0,1,0});

    while(pq.size()){

        int here_cost = pq.top().cost;
        int here = pq.top().pos;
        int tog = pq.top().tog;

        pq.pop();    
		if(dist_wolf[here][tog] < here_cost) continue;

        for(PI there : adj[here]){
            int next = there.second; 
            // tog 0: 2v, 1: v/2
            int d = !tog ? there.first / 2 : there.first * 2;    

            if(dist_wolf[next][!tog] > dist_wolf[here][tog] + d){ 
                dist_wolf[next][!tog] = dist_wolf[here][tog] + d; 
                pq.push({d, next, !tog});
            } 
        }
    }       
} 


int main(){ 
    
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &a, &b, &d); 
        adj[a].push_back(make_pair(d * 2, b)); 
        adj[b].push_back(make_pair(d * 2, a)); 
    } 

    dikstra();  
    dikstra2();  

    for(int i = 2; i <= n; i++){   
        int d = min(dist_wolf[i][0], dist_wolf[i][1]); 
        if(d > dist[i]) ret++;  
    }

    printf("%d\n", ret);
} 
