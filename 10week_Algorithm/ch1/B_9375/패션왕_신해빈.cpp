/**
 * 테스트 : 100
 * n = 30
 * 
 * [리스트]
 * eyewear  : [  ]
 * headgear : [  ]
 * 
 * [개수]
 * 2^n - 1 개
 * a -> a.size
 * a, b -> a.size * b.size
 * a, b, c -> a.size * b.size * c.size
 * 
*/

#include <bits/stdc++.h>
using namespace std;


int t,n,temp;
string a, b,name;

int main(){
    cin >> t;
    for(int i =0; i<t; i++){
        int sum = 0;
        vector<string> cate;
        map<string, set<string>> mp;
        cin >> n;

        for(int i =0; i< n; i++){
            cin >> a >> b;
            if(find(cate.begin(),cate.end(),b) == cate.end()){
                cate.push_back(b);
            }
            mp[b].insert(a);
        }

        int n = cate.size();
        for(int i = 1 ; i <(1<<n);i++){ // 경우 초기화
            temp = 1;
            for(int j = 0; j < n; j ++){
                
                if(i & (1<<j)){
                    name = cate[j];
                    temp *= mp[name].size() ;
                }
            }
            sum += temp;
        }

        cout << sum << '\n';
    }
    return 0;
}