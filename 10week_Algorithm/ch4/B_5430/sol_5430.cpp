#include <bits/stdc++.h>
using namespace std;
int t, n, x;
string p, order;

int main(){ 
    cin >> t;
    for(int i= 0; i<t; i++){
        deque<int> deque;
        cin >> p >> n >> order;
        x = 0;

        for(char c : order){
            if(c == ']' || c == '[') continue;
            if(c >= '0' && c <='9') x = 10*x + c-'0';
            else{ // , 일 때
                if(x > 0) deque.push_back(x);
                x = 0;
            }
        }

        // 마지막 , __ ] 남는다.
        if(x > 0) deque.push_back(x);

        bool error = false , rev = false;
        for(char a : p){
            if(a == 'R') {
                rev = !rev;
            }else{  // D
                if(deque.empty()){
                    error = true;
                    break;
                }
                if(rev) deque.pop_back();
                else deque.pop_front();
            }
        }

        if(error) {
            cout << "error" << '\n';
        }else{
            if(rev) reverse(deque.begin(), deque.end());
            cout << "[";
            for(int i = 0; i<deque.size(); i++){
                cout << deque[i];
                if(i<deque.size()-1) cout << ",";
            }
            cout << "]"<<'\n';
           
        }
        

    }

    return 0;
}