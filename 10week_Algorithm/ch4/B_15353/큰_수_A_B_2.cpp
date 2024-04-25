/**
 * A + B
 * 
*/

#include<bits/stdc++.h>

using namespace std;

int ac, bc;
int ne;
string A, B;
int flag = 0;

int main(){
    cin >> A >> B;
    int asize = A.size(), bsize = B.size();
    
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());

    int misize = (asize > bsize) ? bsize : asize;
    int mxsize = (asize > bsize) ? asize : bsize;

    string ret = "";
    for(int i = 0; i< misize; i++){
        ac = A[i] -'0';
        bc = B[i] - '0';
        ne = ac + bc + flag;
        if(ne >= 10){
            flag = 1;
        }else{
            flag = 0;
        }
        ret += to_string(ne%10);
    }

    /**
     * a == b
     * a > b
     * a < b
    */

    if(asize == bsize){
        if(flag) ret += to_string(flag);
    }else if(asize > misize){
        for(int i = misize; i < mxsize; i++){
            ne = (A[i]-'0') + flag;
            ret += to_string(ne%10);
            if(ne >= 10) flag = 1;
            else flag = 0;
        }
        if(flag) ret += to_string(flag);
    }else{
        for(int i = misize; i < mxsize; i++){
            ne = (B[i]-'0') + flag;
            ret += to_string(ne%10);
            if(ne >= 10) flag = 1;
            else flag = 0;
        }
        if(flag) ret += to_string(flag);
    }

    reverse(ret.begin(),ret.end());
    cout << ret << endl;

    return 0;
}

/**
 * 1
 * 2
 * 
 * 1 3 4 5  (4)
 *     2 2  (2)
 * 
 *   2 2
 * 1 3 4
 * 
 * 한개씩 자를까..? or 한번에 할까?? 
*/