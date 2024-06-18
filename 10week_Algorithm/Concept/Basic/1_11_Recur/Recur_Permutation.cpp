#include <bits/stdc++.h>

using namespace std;
int a[3] = {1, 2, 3};

int n = 3, r = 3;

void print() {
    for (int i = 0; i < r; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
} 

// depth : 트리의 높이
// 
void makePermutation(int n, int r, int depth) {

    cout << n << "  " << r << " - " << depth  << '\n';
    if (r == depth) {
        print();
        return;
    }

    for (int i = depth; i < n; i++) {
        swap(a[i],a[depth]); // 1
        makePermutation(n,r,depth+1);
        swap(a[i],a[depth]); // 1 에서 바꾼 상태 -> 다시 이전 상태로 원복 
    }

    return;

}

int main(void) { 

    makePermutation(n,r,0);

    return 0;
}
