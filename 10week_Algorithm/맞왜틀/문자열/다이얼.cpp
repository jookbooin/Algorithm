/**
 * 전화번호를 각 숫자에 해당하는 문자로 외움
 * [0, 9, 8, 7, 6, 5, 4, 3, 2, 1, , ]
 *
 * 1 :
 * 2 : [A,B,C]
 * 3 : [D,E,F]
 * 4 : [G,H,I]
 * 5 : [J,K,L]
 * 6 : [M,N,O]
 * 7 : [P,Q,R,S]
 * 8 : [T,U,V]
 * 9 : [2,X,Y,Z]
 * 0 :
 *
 * 1 = 2, 2 = 3, ... 9
 * 
 */

#include <bits/stdc++.h>

using namespace std;

int cnt = 0;
int alpha[26] = {2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 7, 8, 8, 8, 9, 9, 9, 9};
// 1 = ' '
// 
string str;

int main() {

    cin >> str;

    for(int i = 0; i<str.size();i++){
        cnt += alpha[str[i]-'A'] + 1;
    }

    cout << cnt << endl;
    
    return 0;
}
