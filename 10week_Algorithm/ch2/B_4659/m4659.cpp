/**
 * 20 글자
 *
 */

// 모음 포함 되었는가?
// 모음 3개 연속 , 자음 3개 연속 X   // 자자 모모 자자 모 자 모 자
// 같은 글자 연속 있는가? (ee , oo)

// 3개의 조건 판별 변수

#include <bits/stdc++.h>

using namespace std;

string input;
vector<char> cv{'a', 'e', 'i', 'o', 'u'};
int con, vow;  // 연속 자음 , 연속 모음
bool vflag;    // 모음 존재
int result;

int main(void) {
    while (true) {
        cin >> input;
        result = 0;
        vflag = 0;
        con = 0;
        vow = 0;

        if (input == "end") {
            break;
        }

        for (int i = 0; i < input.size(); i++) {
            auto it = find(cv.begin(), cv.end(), input[i]);

            if (it != cv.end()) {  // 모음일때
                vflag = 1;
                vow++;
                con = 0;

            } else {  // 자음 일때
                con++;
                vow = 0;
            }

            if (con == 3 || vow == 3) {
                result = 1;
                break;
            }

            if (i > 0 && input[i - 1] == input[i] && !(input[i] == 'e' || input[i] == 'o')) {
                result = 1;
                break;
            }
        }

        if ( vflag == 0) {  // 다른 조건 만족 but 모음 포함 x
            result = 1;
        }

        if (result == 0) {
            cout << "<" << input << ">"
                 << " is acceptable." << '\n';
        } else {  // result = 1
            cout << "<" << input << ">"
                 << " is not acceptable." << '\n';
        }
    }

    return 0;
}
