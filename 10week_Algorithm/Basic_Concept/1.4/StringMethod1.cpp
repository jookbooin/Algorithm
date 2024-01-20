#include <bits/stdc++.h>

using namespace std;

int main(void) {
    string a = "first second";
    a += " third!";

    cout << a << " : " << a.size() << "\n";

    // begin(), end() 는 iterator
    cout << endl;
    cout << char(*a.begin()) << '\n';
    cout << char(*(a.end() - 1)) << '\n';

    // insert , erase , size ( = length)
    cout << endl;
    a.insert(0, "zero ");
    cout << a << " : " << a.size() << "\n";
    a.erase(0, 2);
    cout << a << " : " << a.size() << "\n";
    a.erase(0, 3);
    cout << a << " : " << a.size() << "\n";

    // find
    cout << endl;
    int pos = a.find("r");
    cout << pos << endl;

    auto it = a.find("second");
    if (it != string::npos) {
        cout << "second -> "
             << "포함" << endl;
    }

    auto it2 = a.find("fifth");
    if (it2 == string::npos) {
        cout << "fifth ->"
             << "포함 x " << endl;
    }

    cout << "auto it : " << it << '\n';
    cout << "auto it2 : " << it2 << '\n';
    cout << "string::npos : " << string::npos << '\n';

    // substr
    cout << endl;
    string posLeft = a.substr(0, pos);
    string posRight = a.substr(pos + 1);
    cout << "posLeft : " << posLeft << "\n"
         << "posRight : " << posRight << '\n';
    cout << "a[pos] : " << a[pos] << '\n';

    // [STL] reverse
    cout << endl;
    cout << "a : " << a << endl;

    reverse(a.begin(), a.end());
    cout << a << '\n';
    reverse(a.begin(), a.end());
    cout << a << '\n';
    
    reverse(a.begin(), a.begin() + 5);
    cout << a << '\n';
    reverse(a.begin(), a.begin() + 5);
    cout << a << '\n';


    return 0;
}