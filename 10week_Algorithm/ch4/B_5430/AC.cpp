/**
 * D : 첫번째 수 버리는 함수
 *     배열 비어있을때 사용 -> 에러 발생
 * R : 배열에 있는 수 뒤집는 함수
 *
 * t
 * p
 * n
 * [ ]
 *
 * 전체 테스트 케이스
 *   p 길이 합
 *   n 의 합   < 70
 */
#include <bits/stdc++.h>

using namespace std;

int t, n, ret;
string p, arr;


deque<string> split(string input, string delimiter) {
    deque<string> dq;
    auto start = 0;
    auto end = input.find(delimiter);
    while (end != string::npos) {
        dq.push_back(input.substr(start, end - start));
        start = end + delimiter.size();
        end = input.find(delimiter, start);
    }

    dq.push_back(input.substr(start));
    return dq;
}

void print(string p, deque<string>& deq) {
    bool rev = false;

    for (char ch : p) {
        if (ch == 'D') {
            if (deq.empty()) {
                cout << "error" << endl;
                return;
            }

            if(rev) deq.pop_back();
            else deq.pop_front();
            
        } else {  // R
            rev = !rev;
        }
    }

    if(rev) reverse(deq.begin(), deq.end());

    cout << "[";
    for (int i = 0; i < deq.size(); i++) {
        cout << deq[i];
        if (i < deq.size() - 1) {
            cout << ",";
        }
    }
    cout << "]" << endl;
}

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> p;
        cin >> n;
        cin >> arr;
        deque<string> deq;
        arr = arr.substr(1, arr.size() - 2);

        if (n == 0) {
            deq.clear();
        } else {
            deq = split(arr, ",");
        }

        print(p, deq);
    }

    return 0;
}