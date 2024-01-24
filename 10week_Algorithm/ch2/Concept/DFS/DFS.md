#### 备泅 规过 1
``` cpp
void dfs(int here){
    visited[here] = 1;
    for(int there : adj[here]){
        if(visited[there]) continue;
        dfs(there);
    }
}

// 悼老 
void dfs(int here){
    for(int there : adj[here]){
        if(visited[there]) continue;
        visited[there] = 1;
        dfs(there);
    }
}
```

#### 备泅 规过 2
``` cpp
void dfs(int here){
    
    if(visited[here]) return;
    visited[here] = 1;
    
    for(int there : adj[here]){
        dfs(there);
    }
}

```