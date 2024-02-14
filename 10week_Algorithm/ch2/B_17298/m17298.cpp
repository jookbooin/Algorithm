/**
 * 오큰수 : 오른쪽 큰 수 중에서 가장 왼쪽에 있는 수 
 *          없다면 -1 
 * 
 * 3 5 2 7
 * 5 7 7 -1 
 * N = 100 0000 <- 1번
*/


/**
 *       -1   
 * 3 5 2 7 
 * 
 * 뒤에서 접근
 * max 값 저장 -> 현재 값보다 크다면 저장 
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
                while (!st.empty() && cur >= st.top()) {  // cur 위치가 최대가 된다.
                    st.pop();
                }

                if(!st.empty()){
                    ret[i] = st.top();
                }
            }
        }
        
        st.push(cur);
        mx = max(mx,cur);       // 최댓값 초기화

    }

    for(int i = 0 ; i< N ; i++){
        cout << ret[i] << " ";
    }

    return 0;
}



