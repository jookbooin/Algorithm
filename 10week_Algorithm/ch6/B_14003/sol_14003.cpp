#include <bits/stdc++.h> 

using namespace std;

const int INF = 1e9 + 4;
int n, lis[1000004], len = 0, num;
pair<int,int> ans[1000004];
stack<int> stk;
int main(){

    fill(&lis[0], &lis[0]+1000004, INF);
    cin >> n;
    for(int i = 0; i< n; i++){
        cin >> num;
        auto lowerPos = lower_bound(lis, lis + len, num); // 값 
    
        // lis 안에 num이 없을때
        // lis 길이 증가
        if(*lowerPos == INF){ 
            len ++;
        }
        *lowerPos = num;

        // lis를 이용해서 실제 위치 구함 
        int pos = (int)(lower_bound(lis, lis + num, num) - lis);// 위치
        ans[i].first = pos;
        ans[i].second = num;
    }

    cout << len << '\n';

    for(int i = n-1; i>=0 ; i--){
        if(ans[i].first == len - 1){
            stk.push(ans[i].second);
            len--;
        }
    }

    while(stk.size()){
        cout << stk.top() << " ";
        stk.pop();
    }

    return 0;
}