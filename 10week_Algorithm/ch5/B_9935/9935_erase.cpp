#include <bits/stdc++.h>

using namespace std;

int sz;
string a, b;
stack<char> st;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b;
    sz = b.size();

    string ret = "";
    for (char in : a) {
        ret += in;
        int rsize = ret.size();
        if (rsize >= sz && ret.substr(rsize - sz, sz) == b) {
            ret.erase(rsize - sz, sz);  // O(N)
        }
    }

    if (ret.empty()) {
        cout << "FRULA" << '\n';
    } else {
        cout << ret << '\n';
    }
}