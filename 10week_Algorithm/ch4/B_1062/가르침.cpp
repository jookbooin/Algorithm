/**
 * 어떤 K개의 글자 가르침 -> K개의 글자로만 이루어진 단어만 읽을 수 있음
 * anta / / tica
 *
 *
 * N = 50
 * K = 26
 * 길이 8 이상
 *
 * K 개 배움
 *
 * 1. K >= 5
 * 2. 기본 포함 ( a, n, t, i, c )
 * 3. K 개 초과로 이루어진 것 제외
 * 4.
 */

// substr(4, str.size()-4-4)

#include <bits/stdc++.h>

using namespace std;

int N, K, ret = 0;
string s;
int alpha[26];
vector<string> input;
bool flag;

void check(vector<int> b){
    for(int i : b) alpha[i] = 1; 
    int cnt = 0;
    
    for(string inner : input){
        int i;
        int siz = inner.size();
        for(i = 0; i< siz; i++){
            char ch = inner[i];
            if(!alpha[ch-'a']){
                break;
            }
        }

        if(i == siz) cnt ++;
        
    }

    ret = max(ret,cnt);
    // logic

    for(int i : b) alpha[i] = 0;
}

void combi(int start, vector<int> b){

    if(b.size() == K-5){
        check(b);
        return;
    }

    for(int i = start + 1; i< 26; i++){
        if(alpha[i]) continue;
        b.push_back(i);
        combi(i,b);
        b.pop_back();
    }

}

int main() {
    cin >> N >> K;

    for (char ch : {'a', 'n', 't', 'i', 'c'}) {
        alpha[ch - 'a'] = 1;
    }

    if(K < 5){
        cout << 0 << '\n';
        return 0;
    }

    for (int i = 0; i < N; i++) {
        cin >> s;
        input.push_back(s);
    }

    vector<int> b;
    combi(-1,b);
    
    cout << ret <<'\n';

    return 0;
}