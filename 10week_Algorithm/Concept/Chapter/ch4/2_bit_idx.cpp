#include <bits/stdc++.h>

using namespace std;

int main() {
    // 1 0 0 1 0
    // 1<<1 = 00010
    cout << "<1. bit - off>" << endl;
    int S = 18;        // 1 0 0 1 0
    int idx = 1;

    S &= ~(1 << idx);  // 1 0 0 0 0
    cout << S << '\n';

    cout << '\n' << "<2. bit - XOR>" << endl;
    S = 18;            // 1 0 0 1 0
    idx = 1;

    S ^= (1 << idx);   // 0 0 0 1 0
    cout << S << '\n';
     
    cout << '\n' << "<3. find min bit >" << endl;
    S = 18;            // 1 0 0 1 0
    idx = (S & -S);    // -S = ~(S) + 1
                       // 0 1 1 1 0
    cout << idx << '\n';

    cout << '\n' << "<4. bit on >" << endl;
    int n = 4;
    cout << (1 << n) -1 << '\n'; 
    // (1 << n) : 1 0 0 0 0 
    // (1 << n) -1 : 0 1 1 1 1 


                    
}