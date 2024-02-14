
// 짝짓기 문제 : stack으로 되는지 먼저 생각해봐라

#include <bits/stdc++.h>
using namespace std;
int N, mx;
int val[1000004];
int ret[1000004];
stack<int> st;

int main(void) {
    cin >> N;
    memset(ret, -1, sizeof(ret));

    for (int i = 0; i < N; i++) {
        cin >> val[i];
        while (st.size() && val[st.top()] < val[i]) {  // st이 비어있지 않아야 top 탐색가능
            ret[st.top()] = val[i];
            st.pop();
        }
        st.push(i);
    }
    for (int i = 0; i < N; i++) cout << ret[i] << " ";
    return 0;
}


