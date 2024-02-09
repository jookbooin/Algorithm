/**
 * ( )
 * [ ]
 * 길이 100 보다 작다.
 */

#include <bits/stdc++.h>

using namespace std;

string input;

bool check(string input) {
    stack<char> stk;

    for (char ch : input) {
        if (ch == ')') {
            if (stk.empty() || stk.top() != '(') return false;
            stk.pop();
        }

        if (ch == ']') {
            if (stk.empty() || stk.top() != '[') return false;
            stk.pop();
        }

        if (ch == '(') stk.push(ch);
        if (ch == '[') stk.push(ch);
            
    }

    return stk.empty();
}

int main(void) {
    while (true) {
        getline(cin, input);

        if (input[0] == '.') break;

        if (check(input)) {
            cout << "yes" << '\n';
        } else {
            cout << "no" << '\n';
        }
    }

    return 0;
}