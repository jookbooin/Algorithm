/**
 * N = 64
 *
 * N/2 ·Î ºÐ¸®
 */

#include <bits/stdc++.h>

using namespace std;

const int max_n = 65;

int N;
char graph[max_n][max_n];
string input;

string check(int row, int col, int n) {
    if (n == 1) {
        return string(1, graph[row][col]);
        // return ""+graph[row][col];
    }

    string result = "";

    for (int i = row; i < row + n; i++) {
        for (int j = col; j < col + n; j++) {
            if (graph[i][j] != graph[row][col]) {
                string result = "";
                result += '(';
                result += check(row, col, n / 2);
                result += check(row, col + n / 2, n / 2);
                result += check(row + n / 2, col, n / 2);
                result += check(row + n / 2, col + n / 2, n / 2);
                result += ')';

                return result;
            }
        }
    }

    return string(1, graph[row][col]);
}

// int main(void) {
//     cin >> N;

//     for (int row = 0; row < N; row++) {
//         for (int col = 0; col < N; col++) {
//             cin >> graph[row][col];
//         }
//     }

//     cout << check(0, 0, N) << '\n';

//     return 0;
// }


int main(void){

    char ch = 'B';
    
    cout << string(1,ch) <<endl;
    cout << string(2,ch) <<endl;
    cout << string(3,ch) <<endl;

    cout << str+ ch <<endl;

    return 0;
}