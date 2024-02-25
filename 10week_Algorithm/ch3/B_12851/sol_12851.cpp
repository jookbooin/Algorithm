
#include <bits/stdc++.h>

using namespace std;

const int max_val = 200000;
int N, K, cur, depth, mi = 1e9;
int visited[max_val];  // �ּ� �湮 depth 
int val[max_val];      // depth�� �湮�� ��� ����

int main(void){

    cin >> N >> K;


    // 1. N == K �϶�
    if(N == K){
        cout << 0 << endl;
        cout << 1 << endl;
        return 0;
    }

    // 2. N != K �϶�
    queue<int> q;
    q.push(N);
    visited[N] = 1; 
    val[N] = 1;

    while(q.size()){

        int cur = q.front(); q.pop();

        // 3���� ��� 
        for(int next : {cur-1,cur+1,cur*2}){    

            if(next >= 0 && next < max_val){

                if(!visited[next]){                    // ó�� �湮������
                    visited[next] = visited[cur] + 1 ; // �ִ� �Ÿ�

                    val[next] += val[cur];             // ù �湮�ÿ��� ���� ��� ������ ����
                                                     
                    q.push(next);
                }else if(visited[next] == visited[cur] + 1){ // �湮������, �� �� �ִ� �ٸ� ����� ��
                    val[next] += val[cur];                   // 
                }

            }

        }

    }

    cout << visited[K] - 1 << endl;
    cout << val[K] << endl;


    return 0;
}