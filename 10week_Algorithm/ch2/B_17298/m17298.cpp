/**
 * ��ū�� : ������ ū �� �߿��� ���� ���ʿ� �ִ� �� 
 *          ���ٸ� -1 
 * 
 * 3 5 2 7
 * 5 7 7 -1 
 * N = 100 0000 <- 1��
*/


/**
 *       -1   
 * 3 5 2 7 
 * 
 * �ڿ��� ����
 * max �� ���� -> ���� ������ ũ�ٸ� ���� 
 * 
*/

#include <bits/stdc++.h>
using namespace std;
int N,mx;  
int val[1000004];
int ret[1000004];
stack<int> st;

int main(void){
    cin >> N ;

    for(int i =0 ; i< N; i++){
        cin >> val[i];
    }

    // for(int i = 0; i< N ; i ++){
    //     cout << val[i] << " ";
    // }
    
    for(int i = N-1 ; i>=0; i--){
        int cur = val[i];
        
        if(i == N-1){
            ret[i] = -1;
            mx = cur;
        }else{

            if(cur >= mx){       // 
                ret[i] = -1;
            } else {            // cur < mx
                while (!st.empty() && cur >= st.top()) {  // cur ��ġ�� �ִ밡 �ȴ�.
                    st.pop();
                }

                if(!st.empty()){
                    ret[i] = st.top();
                }
            }
        }
        
        st.push(cur);
        mx = max(mx,cur);       // �ִ� �ʱ�ȭ

    }

    for(int i = 0 ; i< N ; i++){
        cout << ret[i] << " ";
    }

    return 0;
}



