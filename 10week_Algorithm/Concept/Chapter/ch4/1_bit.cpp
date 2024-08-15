#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int a = 7; // 00000111
    
    cout << (a << 1) << '\n'; // 00001110 (14)
    cout << (a << 2) << '\n'; // 00011100 (28)
    cout << (a << 3) << '\n'; // 00111000 (56)


    cout << (1 << 3) << '\n'; // (8)
    cout << (1 << 5) << '\n'; // (32)

    cout <<'\n'<< "<XOR>" << endl;

    //  9 00001001
    // 10 00001010
    //  8 00001000
    cout << (9 ^ 10) << '\n'; // 00000011
    cout << (9 ^ 8) << '\n';  // 00000001

    cout << (1^1) << '\n';
    cout << (0^1) << '\n';

    cout <<'\n'<< "< ~ >" << endl;

    //  3 00000011
    // -4 11111100
    cout << ( ~ 3 ) << endl;        // ~ S = - ( S + 1 )

    int c = -1;
    c = ~c;
    cout << c << endl;
    if(c){
        cout << " hello" << endl;
    }
    
    c = ~c;
    cout << c << endl;
     if(c){
        cout << " hello" << endl;
    }

    c = ~c;
    cout << c << endl;
     if(c){
        cout << " hello" << endl;
    }
    return 0;

}