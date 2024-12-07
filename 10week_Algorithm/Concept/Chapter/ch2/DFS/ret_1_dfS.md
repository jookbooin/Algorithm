
## 4-H 2234

### dp와 같이 `ret=1`로 두고 돌아오는 방식을 꼭 기억해야 한다.ㄴ

int dfs(int cr, int cc, int cnt){  // cnt : 영역을 의미함

    if( visited[cr][cc]) return 0; // 방문시 ret += 0 이 되어야 하므로

    int ret = 1;
    int visited[cr][cc] = 1

    for(int i = 0; i< ; i++){

        int nr = cr + dr[i];
        int nc = cc + dc[i];
        ret += dfs(nr,nc, cnt);
    }
}


