#include <bits/stdc++.h>

using namespace std;

vector<int> tree[51];
int N, root, ers;

int dfs(int idx){
    int child = 0;
    int ret = 0;

    for(int a : tree[idx]){
        if(a == ers) continue;
        ret += dfs(a);
        child ++;
    }
    
    if(child == 0 ) return 1;
    return ret;
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

    if(ers == root){
        cout << 0 << endl;
    }else{
        cout << dfs(root) << endl;
    }

    return 0;
}