
#include <bits/stdc++.h>
using namespace std;


int t,n,temp;
string a, b,name;

int main(){
    cin >> t;
    for(int i =0; i<t; i++){
        int sum = 0;
        vector<string> cate;
        map<string, int> mp;
        cin >> n;

        for(int i =0; i< n; i++){
            cin >> a >> b;
            if(find(cate.begin(),cate.end(),b) == cate.end()){
                cate.push_back(b);
            }
            mp[b]++;
        }

        
        cout << sum << '\n';
    }
    return 0;
}