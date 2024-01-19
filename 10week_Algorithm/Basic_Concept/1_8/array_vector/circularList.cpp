#include <bits/stdc++.h>

using namespace std;
list<int> a;

void print(list<int> a){
    for(auto it : a) cout << it << " ";
    cout << '\n';
}

int main(){
    for(int i = 4; i<=6 ; i++) a.push_back(i);
    for(int i = 1; i<=3 ; i++) a.push_front(i);

    auto it = a.begin(); it++;
    a.insert(it, 1000);
    print(a);

    it = a.begin(); it++;
    a.erase(it);
    print(a);

    a.pop_front();
    a.pop_back();
    print(a);

    cout << a.front() << " : " << a.back() << '\n';
    a.clear();
    return 0;
}