#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    vector<int> a {1,2,3,3,3,4,100};
    cout << &*lower_bound(a.begin(),a.end(),3) << "\n"; // 8
    cout << &*a.begin() << "\n";                        // 0
    cout << &*(a.begin() + 1) << "\n";                  // 4
    cout << *lower_bound(a.begin(), a.end(), 100)<< "\n";
    cout << upper_bound(a.begin(),a.end(),3) - lower_bound(a.begin(),a.end(),3) << "\n"; // °³¼ö
    
    return 0;
}