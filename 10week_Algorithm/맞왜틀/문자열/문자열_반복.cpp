#include<bits/stdc++.h>

using namespace std;

int n,a;
string s;


int main(){
    cin >> n;
    for(int i =0; i<n; i++){
        string ret;
        cin >> a >> s;
        for(int j = 0; j<s.size();j++){
            ret += string(a,s[j]);
        }
        cout << ret << '\n';
    }

    return 0;
}