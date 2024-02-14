
// ¦���� ���� : stack���� �Ǵ��� ���� �����غ���

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
        while (st.size() && val[st.top()] < val[i]) {  // st�� ������� �ʾƾ� top Ž������
            ret[st.top()] = val[i];
            st.pop();
        }
        st.push(i);
    }
    for (int i = 0; i < N; i++) cout << ret[i] << " ";
    return 0;
}


