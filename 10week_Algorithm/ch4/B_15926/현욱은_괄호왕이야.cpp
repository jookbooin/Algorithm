
#include <bits/stdc++.h>

using namespace std;

int n, cnt = 0,ret = 0;
string input;

stack<int> st;
int dp[200004];

int main() {
    cin >> n;
    cin >> input;

    for (int i = 0; i < n; i++) {
        if (input[i] == '(') {
            st.push(i);
        }else{// )
            if(st.empty()){
                continue;
            }

            // 올바른 위치 파악 
            dp[st.top()] = 1;
            dp[i] = 1;
            st.pop();

        }
    }

    for(int i = 0; i< n; i++){
        if(dp[i]){
            cnt ++;
            ret = max(ret , cnt);
        }else cnt = 0;
    }

    cout << ret << '\n';
    return 0;
}