/**
 * Ư�� ���ϰ� ��ġ�ϴ� ���� �̸��� ������ ������� ���ϴ� ���װ� �����.
 * ������ ���ĺ� �ҹ��� ���� ���� ��ǥ(*) �ϳ��� �̷���� ���ڿ��̴�.
 * ���Ͽ� �ִ� ��ǥ -> ���ĺ� �ҹ��ڷ� �̷���� ������ ���ڿ��� ��ȯ�� ���� �̸��� ���� ���� �� �־�� �Ѵ�.
 *   ��ǥ�� �� ���ڿ��� �ٲ� �� ����
 * "abcd", "ad", "anestonestod" -> a*d
 *
 *
 * N = 150
 * ���� ��ġ : DA
 * ��ġ X : NE
 */

#include <bits/stdc++.h>

using namespace std;

int N;
string pat, input;

int main(void) {
    cin >> N;
    cin >> pat;

    int pos = pat.find("*");
    string first = pat.substr(0, pos);
    string last = pat.substr(pos + 1);

    for (int i = 0; i < N; i++) {
        cin >> input;
        if (input.size() < first.size() + last.size()) {
            cout << "NE" << endl;
            continue;
        }

        string strFirst = input.substr(0, first.length());
        string strLast = input.substr(input.length() - last.length(), input.length());

        if (first == strFirst && last == strLast) {
            cout << "DA" << endl;
        } else {
            cout << "NE" << endl;
        }
    }

    return 0;
}
