
#include <bits/stdc++.h>

using namespace std;

int T;
string input;


bool check(string input){
    stack<char> stk;

    for(char s : input){
        if(s == '('){
            stk.push(s);
        }else{   // ')'
            if(!stk.empty()){
                stk.pop();
            }else{
                return false;
            }

        }
    }

    return stk.empty();

}

int main(void){
    cin >> T;

    for(int i = 0; i< T ;i ++){
        cin >> input;

        if(check(input))            // 메서드를 통해서 이조건을 만족하는지 판단
            cout << "YES" << '\n';
        else    
            cout << "NO" << '\n';
    }
    return 0;
}