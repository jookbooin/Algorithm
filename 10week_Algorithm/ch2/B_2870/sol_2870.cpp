/**
 * int : 9�ڸ�
 * long long : 18�ڸ�
 * 
 * 100 -> ������ �ȵǴ� string���� ó��
 * 
 * �ƽ�Ű�ڵ� 65 97
 * 
 * 
*/

#include <bits/stdc++.h>
using namespace std; 

int N;
string input, ret;
vector<string> vresult;

void zeroCheck(){
    while(true){
        if(ret.size() && ret.front() == '0'){  
            ret.erase(0,1);
        }else{
            break;
        }
    }

    if(!ret.size()){
        ret = "0";
    }

    vresult.push_back(ret);
    ret = "";
}

bool cmp(string a, string b){
    if(a.size() == b.size()) return a < b;

    return a.size() < b.size();
}

int main(){
    cin >> N;
    for(int i =0 ; i< N; i++){
        cin >> input;
        ret = "";

        for(int j = 0; j < input.size() ; j++){
            if(input[j] < 65){                 // ����
                ret += input[j];
            }else if(ret.size()){             // ����
                zeroCheck();
            }
        }

        if(ret.size()){
            zeroCheck();
        }
    }

         // vector �ϼ�
        sort(vresult.begin(), vresult.end(), cmp);

        for(string a : vresult){
            cout << a << '\n';
        }

    return 0;
}