
#include <bits/stdc++.h>

using namespace std;

const int max_val = 200000;
int N, K, cur, depth, mi = 1e9;
int visited[max_val];  // 최소 방문 depth 
int val[max_val];      // depth로 방문한 방법 개수

int main(void){

    cin >> N >> K;


    // 1. N == K 일때
    if(N == K){
        cout << 0 << endl;
        cout << 1 << endl;
        return 0;
    }

    // 2. N != K 일때
    queue<int> q;
    q.push(N);
    visited[N] = 1; 
    val[N] = 1;

    while(q.size()){

        int cur = q.front(); q.pop();

        // 3가지 경우 
        for(int next : {cur-1,cur+1,cur*2}){    

            if(next >= 0 && next < max_val){

                if(!visited[next]){                    // 처음 방문했을때
                    visited[next] = visited[cur] + 1 ; // 최단 거리

                    val[next] += val[cur];             // 첫 방문시에는 이전 방법 개수랑 동일
                                                     
                    q.push(next);
                }else if(visited[next] == visited[cur] + 1){ // 방문했지만, 갈 수 있는 다른 방법일 때
                    val[next] += val[cur];                   // 
                }

            }

        }

    }

    cout << visited[K] - 1 << endl;
    cout << val[K] << endl;


    return 0;
}