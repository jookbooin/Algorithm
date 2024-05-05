#include <bits/stdc++.h>

using namespace std;

int arr[26];
string s;
int result = 1;

int main() {
    getline(cin, s);
    
    for(int i =0 ; i<s.size();i++){
        if(s[i] == ' ') result ++;
    }
    cout << result <<'\n';
    return 0;
}