#include <bits/stdc++.h>
using namespace std;
int n, m, words[51]; // word 
string s; 

int count(int mask) {
    
    // words 에는 i번째 입력에 속한 문자들을 계산해 놓음
    int cnt = 0;
    for (int word : words) { 
        if(word && (word & mask) == word)cnt++; 
    }
    
    return cnt;
}

// index : 알파벳 위치
// k : 배울 수 있는 단어 개수 
// mask : 배운 단어 비트로 표현 ( |= )
int go(int index, int k, int mask){                      

    if(k <0) return 0;

    if (index == 26) return count(mask);                // 모든 알파벳을 탐색했다.

    int ret = go(index + 1, k-1, mask | (1 << index));  // index 위치의 알파벳을 배우고 다음 단계
                                                        

    if (index != 'a'-'a' && index != 'n'-'a' && index != 't'-'a' && index != 'i'-'a' && index != 'c'-'a') {  
        // a n t i c 위치가 아닌 경우에는 안배울 수도 있음 
        ret = max(ret, go(index+1, k, mask));
        
    }
    return ret;
}

int main(){
    cin >> n >> m;
    for(int i =0; i<n; i++){
        cin >> s;
        for(char ch : s){
            words[i] |= (1 << (ch - 'a'));
        }
    }

    // m 번만 배울 수 있음 
    cout << go(0, m, 0) << '\n';
    return 0;
}