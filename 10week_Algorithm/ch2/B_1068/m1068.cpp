/**
 * N = 50
 * -1 : root
 */
/**
 *  0  1  2  3  4  5  6
 * -1  0  0  1  1
 */

#include <bits/stdc++.h>

using namespace std;

vector<int> tree[51];
int visited[51];

int N, root, ers;

void dfs(int idx){
    visited[idx] = 1;
    
    for(int a : tree[idx]){
        dfs(a);
    }
}

int main(void) {
    cin >> N;

    for (int i = 0; i < N; i++) {
        int input;
        cin >> input;

        if (input == -1) {
            root = i;
        } else {
            tree[input].push_back(i);
        }
    }

    cin >> ers;

    if (ers == root) {
        cout << 0 << endl;
    } else {

        dfs(ers);       // 트리 형태가 root 부터 내려오는데
                        // ers 밑에만 visited 처리를 하려했는듯..?
                        
        int count = 0;
        for(int i =0 ; i < N; i++){
            if(tree[i].size() ==0 && visited[i] == 0){
                count ++;
            }
        }
        cout << count <<endl;
    }

    return 0;
}