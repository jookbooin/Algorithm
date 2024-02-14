#include <bits/stdc++.h>

using namespace std;

const int max_n = 1004;
int a[max_n];
int a2[max_n][max_n];

int main() {
    cout << "sizeof(a)" << sizeof(a) << endl;
    cout << "sizeof(a2)" << sizeof(a2) << endl;

    memset(a, -1, sizeof(a));
    memset(a2, 0, sizeof(a2));

    for (int i = 0; i < 10; i++) cout << a[i] << " ";

    cout << endl;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << a2[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

/**
 * memset()은 바이트단위로 초기화를 하며 0,-1, char형의 하나의 문자(a, b, c, 등..)으로
 * 초기화를할때만사용
 * 
 * 0, -1 이외는 memset 초기화 못함
*/
