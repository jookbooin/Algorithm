#include <bits/stdc++.h>

using namespace std;

char ch[14];
vector<string> ret;
int visited[14];
int N;

bool opc(char x, char y, char op){

    if(x < y && op == '<') return true;
    else if (x > y && op == '>') return true;
    return false;

}

void go(int idx, string num){ // 다음 단계로 넘어가면서 

    if(idx == N+1){
        ret.push_back(num);
        return;
    }

    for(int i = 0; i <= 9; i++){
        if (visited[i]) continue;
        if(idx == 0 || opc(num[idx - 1], i +'0', ch[idx - 1])){ // string[idx], 숫자(char), 
            visited[i] = 1;
            go(idx+1, num + to_string(i));
            visited[i] = 0;
        }

    }

}

int main(void){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> ch[i];
    }
    
    go(0,"");

    sort(ret.begin(), ret.end());

    cout << ret.back() << "\n" << ret.front();
    
    return 0;
}