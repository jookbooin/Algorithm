#include <bits/stdc++.h>
using namespace std;

const int dc = 3;
const int dr = 4;

int a[dr][dc];

int main() {

    for(int i = 0; i< dr ; i++){
        for(int j = 0; j < dc ; j++){
            a[i][j] = (i + j);
        }
    }

    for(int i = 0; i< dr ; i++){
        for(int j = 0; j < dc ; j++){
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }




    return 0;
}