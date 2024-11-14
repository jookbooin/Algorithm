/**
 * - 연산자 우선 순위 동일
 * - 괄호 안에 `연산자 1개` (a + b)
 * - 중첩 괄호 x
 * 
 * 
*/


#include<bits/stdc++.h>

using namespace std;
const int INF = 987654321;
int n, ret = -INF;
string str;
vector<int> num;
vector<char> op_str;

int cal(int a, int b, char op){
    if(op == '+') return a + b;
    if(op == '-') return a - b;
    if(op == '*') return a * b;
}

void recur(int here, int cur){

    // 종료 조건 
    if(here == num.size() - 1){
        ret = max(ret, cur);
        return;
    }

    // 1.
    recur(here + 1, cal(cur, num[here+1], op_str[here]));

    // 2.
    if(here + 2 <= num.size() - 1){
        int temp = cal(num[here+1], num[here+2], op_str[here+1]);
        recur(here + 2, cal(temp, num[here], op_str[here]));
    }

    return;
}

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);   

    cin >> n;
    cin >> str;

    for(int i = 0; i< n; i++){
        if(i % 2 == 0) num.push_back(str[i] - '0');
        else op_str.push_back(str[i]);
    }

    recur(0,num[0]);

    cout << ret << endl;

    return 0;
}