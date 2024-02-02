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
            if (input[i] >= '0' && input[i] <= '9') {  // ���� ������ �� ( 0 ����)
                if (i == 0 || !(input[i - 1] >= '1' && input[i - 1] <= '9')) {  // ������ 0 0r ���� �Ǵ� ������
                    flag = true;
                    sidx = i, lidx = i;
                } else {  // ���� ����
                    lidx++;
                }

                if (flag && i == input.size() - 1) {  // �������� ��
                    chstr.push_back(stoll(input.substr(sidx, lidx - sidx + 1)));
                }
            } else {  // ���� 0 or ����
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