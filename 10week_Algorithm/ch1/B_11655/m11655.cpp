#include <bits/stdc++.h>

using namespace std;

/**
 * 65 ~ 90
 * 97 ~ 122
 * 
 * �빮�� -> �빮��
 *      (((input - 'A') + 13 ) % 26 ) + 'A'
 * �ҹ��� -> �ҹ���
 *      (((input - 'a') + 13 ) % 26 ) + 'a'
 * 
*/

string input;
int main(void){

    getline(cin, input);

    for(int i =0; i<input.size(); i++){
        if('A'<=input[i] && input[i]<='Z'){
            input[i] = (((input[i] - 'A') + 13 ) % 26 ) + 'A';
        }else if('a'<=input[i] && input[i]<='z'){
            input[i] = (((input[i] - 'a') + 13 ) % 26 ) + 'a';
        }
    }

    cout << input << '\n';
    return 0;

}