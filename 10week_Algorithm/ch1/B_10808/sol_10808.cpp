/**
 * 1. Counting
 * - Map ( string )
 * - Arr ( int )
 *  
 * 2. 아스키 코드
 * - A : 65 + 25
 * - a : 97 + 25
 * 
 * 3. 
 */

#include <bits/stdc++.h>

using namespace std;

int arr[26];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    cin >> input;

    for(char c : input){
        arr[c - 'a'] ++;
    }

    for(int i : arr){
        cout << i <<" ";
    }

    return 0;
}