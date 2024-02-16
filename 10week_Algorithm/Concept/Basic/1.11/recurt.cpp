#include <bits/stdc++.h>

using namespace std;

int n = 5, k = 3, a[5] = {1, 2, 3, 4, 5};


void combi(int idx, vector<int> v){

    if(v.size() == k){
        
        return;
    }

    for(int i = idx + 1 ; i< n ; i++){
        v.push_back(i);
        combi(i,v);
        v.pop_back();
    }

}

int main(void){

    vector<int> b;
    combi(-1,b);

    return 0;
}