/**
 * 100
 * 1�� : A
 * 2�� : B
 * 3�� : C
 * 
 * ���� �ð� <-> ���� �ð� 
 * 
 * �� 3��
*/

#include<bits/stdc++.h>

using namespace std;

int one,two,three,sum;
int arr[100];

int main(void){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> one >> two >> three ;
    
    for(int i = 0; i<3 ; i++){
        int in,out;
        cin >> in >> out ;
        
        for(int i = in; i<out ; i++){
            arr[i] ++;
        }

    }

    for(int j = 1; j < 100; j ++){
        if(arr[j]){ // arr[i]�� �����Ѵٸ�
            if(arr[j]==1) sum += one;
            else if(arr[j]==2) sum += two*2;
            else if(arr[j]==3) sum += three*3;
        }
    }

    cout << sum << '\n';
    return 0;
}

/** 
 * 5 3 1 
 * 
 * 0 1 2 3 4 5 6 7 8 9
 * 0 1 2 3 3 2 1 1 0
 *   5 3 1 1 3 5 5 
 * 
 * 5*3 + 3*2*2 + 1*2*3
 * 15 + 12 + 6
*/
