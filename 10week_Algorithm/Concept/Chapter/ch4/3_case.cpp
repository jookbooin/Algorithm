#include <bits/stdc++.h>
using namespace std;
const int n = 4;

int main() {
    string a[n] = {"���", "����", "����", "��"};

    for(int i =0; i< (1<<n); i++){   // �� ���� ( 0 ~ 10000 )
        string ret = "";
        for(int j =0; j < n; j++){   // �ڸ� ��

            if(i & (1<<j)){
                ret += (a[j] + " ");
            }
        }

        cout << ret << "\n";
        
    }
    
    return 0;
}

/**
 * i : 0000, 0001, 0010, 0011, 0100, 
 * j : 0000, 0010, 0100, 1000 ( �� �ڸ����� �����ϴ��� Ȯ�� )
 *     4C1, 4C2, 4C3, 4C4 ���հ� ���� ��� ����� �� ���� �� ����.
*/

