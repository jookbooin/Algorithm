#include <bits/stdc++.h>

using namespace std;



/**
 *  A B
 *  B C 
 *  
 * 답 : A + C
 * 
 * (A + B + B + C ) - ( A + B + C) = B
 * (A+B - B ) + ( B + C - B)
 */


int a, b,input;
set<int> s;

int main() {
    cin >> a >> b;
    
    for(int i = 0; i< a+b; i++){
        cin >> input;
        s.insert(input);
    }

    int n = a + b - s.size();
    int C = (a + b) - 2*n;
    
    cout << C << endl;
}