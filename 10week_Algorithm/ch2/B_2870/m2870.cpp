#include <bits/stdc++.h>

using namespace std;

int N, sidx, lidx;
string input;
vector<long long> chstr;

int main(void) {
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> input;
        sidx = 0, lidx = 0;
        bool flag = false;

        for (int i = 0; i < input.size(); i++) {
            if (input[i] >= '0' && input[i] <= '9') {  // 현재 숫자일 때 ( 0 포함)
                if (i == 0 || !(input[i - 1] >= '1' && input[i - 1] <= '9')) {  // 이전이 0 0r 문자 또는 시작점
                    flag = true;
                    sidx = i, lidx = i;
                } else {  // 숫자 연속
                    lidx++;
                }

                if (flag && i == input.size() - 1) {  // 마지막일 때
                    chstr.push_back(stoll(input.substr(sidx, lidx - sidx + 1)));
                }
            } else {  // 현재 0 or 문자
                if (flag) {
                    flag = false;
                    chstr.push_back(stoll(input.substr(sidx, lidx - sidx + 1)));
                }
            }
        }
    }

    sort(chstr.begin(), chstr.end());

    for(long long a : chstr){
        cout << a << endl;
    }

    return 0;
}