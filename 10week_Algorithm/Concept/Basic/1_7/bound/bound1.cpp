#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
    vector<int> a {1,2,3,3,3,4};
    cout << lower_bound(a.begin(),a.end(),3) - a.begin() << "\n";  // 3 시작 지점
    cout << upper_bound(a.begin(),a.end(),3) - a.begin() << "\n";  // 3 마지막 지점
    return 0;

}

// lower_bound, upper_bound : 이터레이터