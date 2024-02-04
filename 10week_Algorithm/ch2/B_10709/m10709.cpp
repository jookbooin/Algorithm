/**
 * N ��
 * 1. 1�� Ÿ��
 * 2. Ÿ�� - �ڱ��ڽ� 
 * 3. Ÿ�� = 1��, ���� ��� 1�� 
 * 4. ���� ������ ��� �� x�� Ÿ�� = (1 + x)��
 * 
 * ���� Ƚ�� M��
 * 1 ��° ���ӿ��� ģ�� idx �� Bij�� ģ���� ���.
 * 
*/

#include <bits/stdc++.h>

const int MAX_VALUE = 101;
using namespace std;

int N, M;
int target[MAX_VALUE];
int write[MAX_VALUE][MAX_VALUE];
int result[MAX_VALUE];

void check(int round){
    int rtarget = target[round];

    for(int i = 1 ; i<= N ; i++){
        if(write[round][i] == rtarget){ // ���⶧
            result[i] += 1;
        }else{
            result[rtarget]++;  // �� ���߸� Ÿ�� + 1
        }

    }

}

int main(void){
    cin >> N;
    cin >> M;

    for(int i = 1; i<=M ; i++)
        cin >> target[i];
    
    for(int row =1 ; row<=M; row++){
        for(int col = 1; col<=N ; col ++){
            cin >> write[row][col];  // row ��° ����, col�� ģ���� [row][col]�� ģ���� ���.

            
        }
        check(row);
    }

    for(int i =1 ; i<=N ; i++){
        cout << result[i] << '\n';
    }


    return 0;
}
// 2 1 0
// 0 2 1
// 0 0 3
// 1 1 1

// 3 4 5