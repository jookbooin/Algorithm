#include <bits/stdc++.h>
using namespace std;
int main() {
    string a = "love is";
    a += " pain!";
    a.pop_back();
    cout << a << " : " << a.size() << "\n";

    cout << char(*a.begin()) << '\n';      // 첫 요소
    cout << char(*(a.end() - 1)) << '\n';  // 마지막 요소 다음

    a.insert(0, "test ");
    cout << a << " : " << a.size() << "\n" << endl;  // O(1)

    a.erase(0, 5);
    cout << a << " : " << a.size() << "\n" << endl;

    auto it = a.find("is");  // O(N)
    if (it != string::npos) {
        cout << "포함되어 있다." << '\n';
    }
    cout << it << '\n';
    cout << string::npos << endl << endl;  // 끝 값을 의미한다.

    cout << a.substr(5, 2) << '\n' << endl;  // O(N)

    string s = "123";
    s[0]++;                   // 문자열을 이루는 것은 문자 ( 개별 아스키 코드 )
    cout << s << endl;
    s[2]++;
    cout << s << endl << endl;


    return 0;
}