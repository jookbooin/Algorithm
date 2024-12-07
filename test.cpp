#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, k, cur, depth, mi = 1e9;
int val[100004];      //
int visited[100004];  // 특정 depth 방문 처리

int main(){
    cin >> n >> k;

    if(n == k){
        cout << 0 << '\n';
        cout << 1 << '\n';
    }

    queue<int> q;
    q.push(n);
    visited[n] = 1; // 최단거리
    val[n] = 1; // 갈 수 있는 방법의 수

    while(q.size()){

        int cur = q.front();
        q.pop();

        for(int next : {cur-1, cur+1, cur*2}){
            if(next < 0 || next > 100000) continue;

            if(!visited[next]){  // 첫 방문일 때
                visited[next] = visited[cur] + 1; // 최단거리
                val[next] += val[cur];

                q.push(next);
            } else if(visited[next] == visited[cur] + 1 ){ // 다음번에 갈 수 있는 위치일 때
                val[next] += val[cur];
            }
        }

    }

    cout << val[k] << endl;
    return 0;
}