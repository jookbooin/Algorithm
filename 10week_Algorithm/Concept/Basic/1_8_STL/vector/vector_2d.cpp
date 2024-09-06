#include <bits/stdc++.h>

using namespace std;

int main() {
    // 1. vector 안에 vector
    vector<vector<int>> v1;

    for(int i =0; i <10; i++){
        vector<int> temp;
        v1.push_back(temp);
    }

    // 2. 10 * 10 짜리 크기의 2차원 배열 생성
    vector<vector<int>> v2 (10, vector<int>(10,0));

    // 3. 10개 짜리 배열 선언
    vector<int> v3[10];




    return 0;
}