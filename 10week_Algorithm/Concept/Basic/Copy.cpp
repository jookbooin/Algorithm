#include <bits/stdc++.h>
using namespace std;


int n = 3;

int main() {

    vector<int> v = {1,2,3};
    vector<int> ret(3);

    copy(v.begin(),v.end(),ret.begin());
    cout << ret[1] << "\n";
    ret[1] = 100;
    cout << ret[1] << "\n";
    cout << v[1] << "\n";

    int va[n] = {4,5,6};
    int retv[n];

    copy(va,va+n,retv);
    cout << retv[1] << "\n";
    retv[1] = 600;
    cout << retv[1] << "\n";
    cout << va[1] << "\n";

    return 0;

}