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

    
    for (char in : a) { 
        st.push(in);

        if (st.size() >= sz && st.top() == b[sz - 1]) {
            string temp = "";
            for (int i = 0; i < sz; i++) {
                temp += st.top();
                st.pop();
            }

            reverse(temp.begin(), temp.end());

            if (temp != b) {
                for (auto a : temp) st.push(a);
            }
        }
    }

    if(st.empty()){
        cout << "FRULA" << '\n';
    }else{
        string temp ="";
        
        while(st.size()){
            temp += st.top();
            st.pop();
        }

        reverse(temp.begin(), temp.end());
        cout << temp << '\n';
    }

    return 0;
}
