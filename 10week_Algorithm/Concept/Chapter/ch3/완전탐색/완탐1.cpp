#include <bits/stdc++.h>

using namespace std;
int cnt, n;

int main() {

    cin >> n;
    int i = 2400;

    while (true) {
        string a = to_string(i);
        if (a.find("2400") != string::npos) {
            cnt++;

            if (n == cnt) {
                cout << a << '\n';
                break;
            }
        }

        i++;
    }

    return 0;

}
