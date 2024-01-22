#include <bits/stdc++.h>

using namespace std;

map<string, int> mp;
string a[] = {"林全枚", "捞铰枚", "冠辆急"};

int main() {
    for (int i = 0; i < 3; i++) {
        mp.insert({a[i], i + 1});
        mp[a[i]] = i + 1;
    }

    cout << mp["kundol"] << '\n';

    mp["kundol"] = 4;
    cout << mp.size() << '\n';
    mp.erase("kundol");
    auto it = mp.find("kundol");
    if (it == mp.end()) {
        cout << "给茫摆匙 惨部府\n";
    }
    mp["kundol"] = 100;
    it = mp.find("kundol");
    if (it != mp.end()) {
        cout << (*it).first << " : " << (*it).second << '\n';
    }

    for (auto it : mp) {
        cout << (it).first << " : " << (it).second << '\n';
    }

    for (auto it = mp.begin(); it != mp.end(); it++) {
        cout << (*it).first << " : " << (*it).second << '\n';
    }

    mp.clear();
    return 0;
}
