#include <bits/stdc++.h>

using namespace std;

int main(){

    vector<int> v(3,0);

    for(int i = 0; i <3; i++){
        cout << v[i] << ' ';
    }
    cout << endl;

    v[0] = 1;
    for(int i =0; i< 3; i++){
        cout << v[i] << ' ';
    }
    cout << endl;
    
    return 0;
}