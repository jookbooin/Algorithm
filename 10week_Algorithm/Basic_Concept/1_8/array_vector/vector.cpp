#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main(void) {
    for (int i = 1; i <= 10; i++) v.push_back(i);
    for (int a : v) cout << a << " ";
    cout << "\n";
    v.pop_back();

    for (int a : v) cout << a << " ";
    cout << "\n";

    v.erase(v.begin(), v.begin() + 3);

    for (int a : v) cout << a << " ";
    cout << "\n";

    auto a = find(v.begin(), v.end(), 100);  // stl �Լ�

    if (a == v.end())
        cout << "not found" << "\n";

    fill(v.begin(), v.end(), 10);
    for (int a : v) cout << a << " ";
    cout << "\n";

    v.clear();
    cout << "�ƹ��͵� ������?\n";
    for (int a : v) cout << a << " ";
    cout << "\n";


    // pair
    vector<pair<int,int>> v2 = { {1,2},{3,4}};
    for(pair<int,int> a : v2) cout << a.first << " ";



    return 0;

}
