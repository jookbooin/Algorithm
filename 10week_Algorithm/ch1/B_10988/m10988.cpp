
/**
 * 1 ~ 100
*/

#include <bits/stdc++.h>
using namespace std;

string input;
int a, b;
int main(void){

    cin >> input;
    b = input.size();

    int mid = ( b + 1 )/2;

    for (int i = 0 ; i< mid ; i++){
        if(input[i] != input[b-1-i]){
            cout << '0' << '\n';
            return 0;
        }
    }
    cout << '1' << '\n';

    // c++ 에서 종료시 return 0;을 자동으로 붙여준다.
    // return 0;
}