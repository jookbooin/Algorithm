/**
 * che 배열을 사용하기 때문에
 * 배열의 크기가 일정 수준 이상 벗어나면 쓰기 힘들다 ( 1000 만 )
 */
#include <bits/stdc++.h>
using namespace std;
const int max_n = 40;
bool che[max_n + 1];

vector<int> era(int mx_n) {
    vector<int> v;
    for (int i = 2; i <= mx_n; i++) {
        if (che[i]) continue;

        // i읭 배수 제거
        for (int j = 2 * i; j <= mx_n; j += i) {
            che[j] = 1;
        }
    }

    // 소수 모음
    for (int i = 2; i <= mx_n; i++)
        if (che[i] == 0) v.push_back(i);
    return v;
}

int main() {
    vector<int> a = era(max_n);
    for (int i : a) cout << i << " ";
}