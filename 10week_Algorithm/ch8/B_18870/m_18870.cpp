#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

vector<int> v, pv;
int n, p, sum = 0;
map<int, int> m;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p;
        v.push_back(p);
        m.insert({p,0});
    }

// -10 -9 2 4
    // pv 중복 삭제
    int i = 0;
    for(auto &p : m){
        p.second = i++;
    }

    for(int i : v){
        cout << m[i] << " ";
    }

    return 0;
}