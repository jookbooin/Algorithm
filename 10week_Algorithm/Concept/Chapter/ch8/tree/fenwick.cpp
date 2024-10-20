#include <bits/stdc++.h>

using namespace std;

vector<int> fenwick_tree;
int n ;
int arr[5] = {1, 2, 3, 4, 5};

void update(int idx, int value){
    while(idx < fenwick_tree.size()){
        fenwick_tree[idx] = fenwick_tree[idx] + value;
        idx = idx + (idx & -idx);
    }
}

void make_penwickTree(){
    for(int i = 1; i<= n; i++){
        update(i, arr[i]);
    }
}

int sum(int idx){
    int result = 0;
    while(idx > 0){
        result = result + fenwick_tree[idx];
        idx = idx - (idx & -idx);
    }

    return result;
}

int main() {
    int a = 6;
    int neg_a = -a; // a의 음수값
    for (int i = 3; i >= 0; i--) { // 32비트 정수로 가정
        if (neg_a & (1 << i)) {
            cout << 1;
        } else {
            cout << 0;
        }
    }
    cout << endl; // 줄바꿈
    return 0;
}
