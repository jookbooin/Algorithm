
#include <bits/stdc++.h>

using namespace std;


int N,cnt, num=666;
string numstr;
int main(void){

    cin >> N; // 10000

    while(true){

        numstr = to_string(num);

        for(int i = 0; i< numstr.size()-2; i++){
            if(numstr[i]=='6' && numstr[i+1]=='6' && numstr[i+2]=='6'){
                cnt ++;
                break;
            }
        }

        if(cnt == N){
            cout << numstr <<'\n';
            break;
        }


        num ++;
    }


return 0;
}
