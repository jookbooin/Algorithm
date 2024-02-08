/**
 * 괄호 짝이 맞아야 할듯?
 *
 * N = 2 or 50
 *
 * ( : push
 * ) : pop
 */

#include <bits/stdc++.h>

using namespace std;

int T;
string input;
int main(void) {
    cin >> T;

    for (int i = 0; i < T; i++) {
        bool flag = false;
        stack<char> st;
        cin >> input;
        for (int i = 0; i < input.size(); i++) {
            if (input[i] == '(') {
                st.push(input[i]);
            } else if(st.size() && input[i]==')') {
                st.pop();
            }else if( st.size() ==0 && input[i]==')'){
                flag = true;
                break;
            }
        }

        if (!flag && st.size()==0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}