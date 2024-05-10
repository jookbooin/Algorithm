
#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> lv;
int n,s,e,ns,ne;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for(int i = 0; i< n; i++){
        cin >> s >> e;
        lv.push_back({s,e});
    }
    
    sort(lv.begin(), lv.end());
    s = lv[0].first;
    e = lv[0].second;
    int length = 0;

    for(int i = 1; i<n; i++){
        ns = lv[i].first;
        ne = lv[i].second;

        if(e < ns){
            length += e - s;
            s = ns;
            e = ne;
            
        }else if (ns <= e && ne >= e){
            e = ne;
        }
    }

    length += e - s;

    cout << length << '\n';

    return 0;
}