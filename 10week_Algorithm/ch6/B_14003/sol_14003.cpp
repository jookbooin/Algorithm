#include <bits/stdc++.h> 

// 10 20 10 30 20 50
// 10 20 50 30 40 70 20 30 40 50
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
        // lis를 이용해서 실제 위치 구함 
        int pos = (int)(lower_bound(lis, lis + len, num) - lis);// 위치
    
        // lis 안에 num이 없을때
        // lis 길이 증가
        if(*lowerPos == INF){ 
            len ++;
        }
        *lowerPos = num;

        // 중간에 (2,50) (4,70) 도 모두 저장
        ans[i].first = pos;  
        ans[i].second = num;
    }

    for(int i = 0; i< n; i++){
        cout << ans[i].first << " " << ans[i].second << endl;
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