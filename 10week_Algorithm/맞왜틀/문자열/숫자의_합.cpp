#include<bits/stdc++.h>

using namespace std;

int n,result = 0;
char ch;
string s;

int main(){

    cin >> n;
    
    for(int i = 0; i< n; i++){
        // scanf(" %c", &ch);
        cin >> ch;
        result += ch-'0';
        // result += s[i]-'0';
    }

    cout << result << '\n';
    return 0;
}