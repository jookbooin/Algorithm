#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6};

    for (int i : v) cout << i << ' ';
    cout << endl
         << endl;

    // [ 전체 이동 ]
    // 1. 반시계 방향 ( 1칸 - begin() + 1 )
    cout << "[ 반 시계 (1칸) ]" << endl;
    rotate(v.begin(), v.begin() + 1, v.end());

    for (int i : v) cout << i << ' ';
    cout << endl;
    cout << endl;

    cout << "[ 반 시계 (2칸) ]" << endl;
    v = {1, 2, 3, 4, 5, 6};
    rotate(v.begin(), v.begin() + 2, v.end());

    for (int i : v) cout << i << ' ';
    cout << endl;
    cout << endl;

    // [ 일부분 이동 ]
    v = {1, 2, 3, 4, 5, 6};

    /**
     * 시작 지점 : v.begin() + 1
     * 시작 지점 으로 부터 + 1 : v.begin() + 1 + 1
     * 끝 점 : v.begin() + 5
     */
    cout << "[ 반 시계 일부분 (1 ~ 4) ]" << endl;
    v = {1, 2, 3, 4, 5, 6};
    rotate(v.begin() + 1, v.begin() + 2, v.begin() + 5);

    for (int i : v) cout << i << ' ';
    cout << endl;
    cout << endl;

    cout << "[ 시계 (1칸) ]" << endl; 
    v = {1, 2, 3, 4, 5, 6};
    rotate(v.rbegin(), v.rbegin()+1, v.rend());
    
    for (int i : v) cout << i << ' ';
    cout << endl;
    cout << endl;

    return 0;
}