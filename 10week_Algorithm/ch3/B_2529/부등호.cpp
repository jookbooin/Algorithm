/**
 * 숫자는 { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }중에서 선택해야 하며
 * 선택된 숫자는 모두 달라야 한다.
 *
 *
 * 10! = 362 8800
 */

/**
 * 0 일때 push, pop
 *
 * 방문 x - 조건 해당
 */

#include <bits/stdc++.h>

using namespace std;
char ch[14];
int N;
int visited[14];

vector<int> inv;
vector<vector<int>> outv;

void check(int depth) {
    
    if(depth == N+1){          // 종료 조건
        outv.push_back(inv);
        return;
    }

    int ins = inv.size();

    for (int i = 0; i <= 9; i++) {
        if (visited[i]) continue;

        if (ins == 0) {

            visited[i] = 1;
            inv.push_back(i);
            check(depth + 1);
            inv.pop_back();
            visited[i] = 0;

        } else if (ins == depth) {
            int stop = inv.back();

            if (ch[depth] == '<') {
                if (stop < i) {

                    visited[i] = 1;
                    inv.push_back(i);
                    check(depth + 1);
                    inv.pop_back();
                    visited[i] = 0;

                }
            } else {
                if(stop > i){

                    visited[i] = 1;
                    inv.push_back(i);
                    check(depth + 1);
                    inv.pop_back();
                    visited[i] = 0;

                }
            }
        }
    }
}

int main(void) {
    cin >> N;
    for (int i = 1; i <= N; i++) {
        cin >> ch[i];
    }

    check(0);

    vector<int> ans = outv.back();
    for(int i : ans){
        cout <<i;
    }

    cout << endl;

    ans = outv.front();
    for(int i : ans){
        cout <<i;
    }

    return 0;
}