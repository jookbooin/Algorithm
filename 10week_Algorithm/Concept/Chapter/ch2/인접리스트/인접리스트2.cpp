#include<bits/stdc++.h>
using namespace std; 

const int V = 10;
vector<int> adj[V];
int visited[V];

void go(int idx){
    cout << idx << '\n';
    visited[idx] = 1;
    for(int there : adj[idx]){
        if(visited[there]) continue; // 방문
        go(there);// 방문 x
    }
}

int main(void){

    adj[1].push_back(2);
    adj[2].push_back(1);

    adj[1].push_back(3); 
    adj[3].push_back(1);

    adj[3].push_back(4); 
    adj[4].push_back(3);

    for(int i =0; i<V; i++){
        if(adj[i].size() && visited[i] == 0)  // adj[i].size() : 연결된 정점이 있을때 
            go(i);
    }


    return 0;
}



