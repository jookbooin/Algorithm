/**
 * n
 *
 * 남으면 안된다.
 * 교차되면 안된다.
 *
 */

#include <bits/stdc++.h>

using namespace std;
int n, cnt = 0;
string s;

int main() {
    cin >> n;

    for(int i = 0; i<n;i++){
        cin >> s;
        stack<char> st;

        for(char c : s){
            if(!st.empty() && st.top() == c) st.pop();
            else st.push(c);
        }

        if(st.empty()) cnt ++;
    }

    cout << cnt << '\n';
   return 0;
}