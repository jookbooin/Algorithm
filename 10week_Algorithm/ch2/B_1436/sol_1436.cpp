
#include <bits/stdc++.h>

using namespace std;


int N,cnt=0, num=666;
string numstr;
int main(void){

    cin >> N; // 10000

    while(true){
        if(to_string(num).find("666") != string::npos) N--;
        if(N == 0) break;
        num++;
    }

    cout << num << '\n';

return 0;
}
