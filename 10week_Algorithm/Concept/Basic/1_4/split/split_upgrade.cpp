#include <bits/stdc++.h>

using namespace std;

/**
 * �Ź� erase�ϴ� �κ� ����
 * */

vector<string> split(const string& input, string delimiter) {
    vector<string> result;
    auto start = 0;
    auto end = input.find(delimiter);
    while (end != string::npos) {
        result.push_back(input.substr(start, end - start));
        start = end + delimiter.size();
        end = input.find(delimiter, start);
    }
    result.push_back(input.substr(start));
    return result;
}

int main() {
    string s = "�ȳ��ϼ��� ū���̴� ŷ�����ʷ� õ���Դϴ� �����̿���!", d = " ";
    vector<string> a = split(s, d);
    for (string b : a) cout << b << "\n";
}
