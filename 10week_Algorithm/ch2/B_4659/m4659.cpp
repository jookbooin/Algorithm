/**
 * 20 ����
 *
 */

// ���� ���� �Ǿ��°�?
// ���� 3�� ���� , ���� 3�� ���� X   // ���� ��� ���� �� �� �� ��
// ���� ���� ���� �ִ°�? (ee , oo)

// 3���� ���� �Ǻ� ����

#include <bits/stdc++.h>

using namespace std;

string input;
vector<char> cv{'a', 'e', 'i', 'o', 'u'};
int con, vow;  // ���� ���� , ���� ����
bool vflag;    // ���� ����
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

            if (it != cv.end()) {  // �����϶�
                vflag = 1;
                vow++;
                con = 0;

            } else {  // ���� �϶�
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

        if ( vflag == 0) {  // �ٸ� ���� ���� but ���� ���� x
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
