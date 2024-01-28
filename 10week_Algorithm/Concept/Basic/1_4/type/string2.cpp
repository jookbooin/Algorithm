#include <bits/stdc++.h>
using namespace std;
int main() {
    string a = "love is";
    a += " pain!";
    a.pop_back();
    cout << a << " : " << a.size() << "\n";

    cout << char(*a.begin()) << '\n';      // ù ���
    cout << char(*(a.end() - 1)) << '\n';  // ������ ��� ����

    a.insert(0, "test ");
    cout << a << " : " << a.size() << "\n" << endl;  // O(1)

    a.erase(0, 5);
    cout << a << " : " << a.size() << "\n" << endl;

    auto it = a.find("is");  // O(N)
    if (it != string::npos) {
        cout << "���ԵǾ� �ִ�." << '\n';
    }
    cout << it << '\n';
    cout << string::npos << endl << endl;  // �� ���� �ǹ��Ѵ�.

    cout << a.substr(5, 2) << '\n' << endl;  // O(N)

    string s = "123";
    s[0]++;                   // ���ڿ��� �̷�� ���� ���� ( ���� �ƽ�Ű �ڵ� )
    cout << s << endl;
    s[2]++;
    cout << s << endl << endl;


    return 0;
}