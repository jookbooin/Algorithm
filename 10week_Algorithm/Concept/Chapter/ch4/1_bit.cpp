#include <bits/stdc++.h>

using namespace std;

int main(){
 
    int a = 7;

    cout << (a << 1) << '\n'; // a * 2^1
    cout << (a << 2) << '\n'; // a * 2^2
    cout << (a << 3) << '\n'; // a * 2^3

    cout << (1 << 3) << '\n';
    cout << (1 << 5) << '\n';

    cout <<'\n'<< "<XOR>" << endl;
    cout << (9 ^ 10) << '\n';
    cout << (9 ^ 8) << '\n';

    cout <<'\n'<< "< ~ >" << endl;
    cout << ( ~ 3 ) << endl;        // ~ S = - ( S + 1 )
    




    return 0;

}