#include<bits/stdc++.h>

using namespace std;
int n;
string s;

int main(){
    cin >> n;
    for(int i =0; i<n;i++){
        cin >> s;
        cout <<s[0] << s[s.size()-1] << '\n';
    }
    return 0;
}