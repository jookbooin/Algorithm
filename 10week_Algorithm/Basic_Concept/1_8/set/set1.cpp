#include <bits/stdc++.h>

using namespace std;

int main() {
    set<pair<string, int>> st;
    st.insert({"test", 1});
    st.insert({"test", 1});
    st.insert({"test", 1});
    st.insert({"test", 1});
    st.insert({"test", 1});

    cout << st.size() << "\n";
    set<int> st2;
    st2.insert(1);
    st2.insert(1);
    st2.insert(2);
    st2.insert(2);
    st2.insert(2);

    for (auto it : st2) {
        cout << it << '\n';
    }

    multiset<int> ss;
    for (int i = 5; i >= 1; i--) {
        ss.insert(i);
        ss.insert(i);
    }

    for (int it : ss) cout << it << " ";
    cout << '\n';
    return 0;
}