/**
 * 특정 패턴과 일치하는 파일 이름을 적절히 출력하지 못하는 버그가 생겼다.
 * 패턴은 알파벳 소문자 여러 개와 별표(*) 하나로 이루어진 문자열이다.
 * 패턴에 있는 별표 -> 알파벳 소문자로 이루어진 임의의 문자열로 변환해 파일 이름과 같게 만들 수 있어야 한다.
 *   별표는 빈 문자열로 바꿀 수 있음
 * "abcd", "ad", "anestonestod" -> a*d
 *
 *
 * N = 150
 * 패턴 일치 : DA
 * 일치 X : NE
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
