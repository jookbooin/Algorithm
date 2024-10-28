/***
 * 1. 초기 준규의 스탯 = (1, 1)
 * 2. i번째 퀘스트를 깨려면 준규의 스탯이
 * - str[i] >= 준.str
 * - int[i] >= 준.int 
 * 여야함
 * 
 * 3. 퀘스트를 깨는 순서는 준규가 마음대로 정할 수 있다.
 * 4. 퀘스트 보상으로 얻는 포인트로 준규 마음대로 스탯을 올릴 수 있다.
 * 
 * 깰 수 있는 퀘스트 개수 최댓값 
 * 
 * n (퀘스트 개수) = 50
 * 
 * str, int, pnt
 * 
 */
#include <bits/stdc++.h>

using namespace std;
int n, ret = 0;
struct abil {
    int st, in , p;
};

vector<abil> av;
int visited[54];
int dp[1004][1004];
int STR, INT, PNT;

int go(int st, int in){
    
    int& ret = dp[st][in];
    if(ret != -1) return ret;
    ret = 0;

    // 1. 현재 상태에서 갈 수 있는 점 확인
    vector<int> vv;
    int pnt = 0;

    for(int i = 0 ; i< n; i++){
        
        if(st >= av[i].st || in >= av[i].in){
            // 현재 st, in 에서 지날 수 있는 점 개수 
            ret++;   

            // 현재 단계에서 새롭게 지나는 점 
            if(!visited[i]){
                visited[i] = true;
                pnt += av[i].p; 
                vv.push_back(i);
            }

        }
    }

    // 2. 갈 수 있는 다음 단계
    for(int i = 0; i<= pnt; i++){
        int next_str = min(1000, st+i);
        int next_int = min(1000, in + (pnt - i));
        ret = max(ret, go(next_str, next_int));
    }

    // 3. 현재 단계에서 지난 점 원복 
    for(int a : vv){
        visited[a] = false;
    }

    return ret;
}

int main(){

    cin >> n;
    for(int i = 0; i<n; i++){
        cin >> STR >> INT >> PNT;
        av.push_back({STR, INT, PNT});
    }

    memset(dp, -1, sizeof(dp));

    // 초기 str = 1, int = 1 
    cout << go(1,1) << endl;

    return 0;
}