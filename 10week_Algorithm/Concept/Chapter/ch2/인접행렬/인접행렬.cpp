// 1��.
// ������ 0�� ���� 9������ 10���� ��尡 �ִ�. 1 - 2 /  1 - 3 / 3 - 4 ��� ��ΰ� �ִ�. (1���� 2��, 1���� 3��, 3���� 4���� ����Ǿ��ִ�.) 
// �̸�  �̸� ������ķ� ǥ���Ѵٸ�? 

// 2��. 
// 0������ �湮���� ��带 ã�� �ش� ������ �湮, ����� ��带 �̾ �湮�ؼ� ����ϴ� ����Լ��� ����� �ʹٸ� ��� �ؾ��ұ�?
// ����, ������ �湮�ϰ� �ٽ� �湮���� �ʰ� ������� ��� �ؾ��ұ�? 

#include <bits/stdc++.h>

using namespace std;

const int V = 10;
bool graph[V][V], visited[V];

void go(int from) {
    visited[from] = 1;
    cout << from << '\n';
    for(int to = 0; to< V; to++){
        if(visited[to]) continue;
        if(graph[from][to]){ // 1-2 , 1-3 , 1-4 ����� ������ ����.
            go(to);
        }
    }
}

int main(void) {
    graph[1][2] = 1;
    graph[2][1] = 1;

    graph[1][3] = 1;
    graph[3][1] = 1;

    graph[3][4] = 1;
    graph[4][3] = 1;

    for (int row = 0; row < V; row++) {
        for (int col = 0; col < V; col++) {
            if (graph[row][col] && visited[row] == 0) {
                go(row);
            }
        }
    }
    
    return 0;
}