#include <bits/stdc++.h>

using namespace std;

int a, b,input,cnt = 0;

map<int,int> mmap;

int main() {
    cin >> a >> b;
    
    for(int i = 0; i< a + b; i++){
        cin >> input;
        mmap[input] ++;
    }

    for(auto it : mmap){
        if(it.second == 1){
            cnt ++;
        }
    }

    cout << cnt << endl;
    
}