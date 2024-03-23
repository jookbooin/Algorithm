#include <bits/stdc++.h>
using namespace std;
const int n = 4;

int main() {
    string a[n] = {"사과", "딸기", "포도", "배"};

    for(int i =0; i< (1<<n); i++){   // 총 개수 ( 0 ~ 10000 )
        string ret = "";
        for(int j =0; j < n; j++){   // 자릿 수

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
 * j : 0000, 0010, 0100, 1000 ( 각 자리수가 존재하는지 확인 )
 *     4C1, 4C2, 4C3, 4C4 조합과 같은 모든 경우의 수 구할 수 있음.
*/

