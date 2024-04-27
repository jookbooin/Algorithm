
#include <bits/stdc++.h>
using namespace std;

int t, n, temp;
string a, b, name;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        int cnt = 1;
        map<string, int> mp;

        cin >> n;

        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            mp[b]++;
        }
        
        for(auto it : mp){
            cnt *= (it.second+1);
        }

        cout << cnt-1 <<'\n';
    }
    return 0;
}