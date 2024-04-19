/**
 * pi / ka / chu
 *
 * 길이 5000
 *
 * s[0] = 'p', 'k'  substr(0,2)
 * s[0] = 'c        substr(0,3)
 *
 */

#include <bits/stdc++.h>

using namespace std;

string s = "chu";
int idx = 0;
int ssize;
string input;
bool flag;

int main() {
    cin >> input;
    ssize = input.size();

    for(int i = 0; i< ssize ;){
        if(input.substr(i,2) == "pi"){
            i += 2;
        }else if (input.substr(i,2) == "ka"){
            i +=2;
        }else if(input.substr(i,3) == "chu"){
            i += 3;
        }else{
            cout <<"NO" << '\n';
            return 0;
        }
    }
    
    cout << "YES" << '\n';

    return 0;
}