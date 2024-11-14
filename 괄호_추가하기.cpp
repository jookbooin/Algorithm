#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int n, ret = -INF;
string str;
vector<int> num;
vector<char> op_str;

int cal(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    return 0; // 기본적으로 올바른 연산자만 들어온다고 가정
}

void recur(int here, int cur) {
    // 종료 조건 
    if (here == num.size() - 1) {
        ret = max(ret, cur);
        return;
    }

    // 1. 현재 연산자 사용
    recur(here + 1, cal(cur, num[here + 1], op_str[here]));

    // 2. 다음 숫자와 함께 괄호를 사용
    if (here + 2 <= num.size() - 1) {
        int temp = cal(num[here + 1], num[here + 2], op_str[here + 1]);
        recur(here + 2, cal(cur, temp, op_str[here])); // 현재 숫자와 temp를 연산
    }

    return;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> str;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) num.push_back(str[i] - '0');
        else op_str.push_back(str[i]);
    }

    recur(0, num[0]);
    cout << ret << endl;

    return 0;
}
