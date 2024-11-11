/**
 * t = 1000 초
 * w = 30번 
 * 
 * 2개의 나무 중 1개의 나무에서 열매가 떨어짐 
 * 
 * <입력>
 * - t초
 * - w번 움직임 
 * 
 * < 출력 >
 * - 자두가 받을 수 있는 자두의 최대 개수 
 */

#include <bits/stdc++.h>

using namespace std;

int dp[1004][4][34];
int t ,w , p;
vector<int> v;

int go (int tt, int pos, int cnt){

    // 종료 조건 
    if(tt == t){
        return 0; // 시작점 
    }

    int& ret = dp[tt][pos][cnt];
    if(ret != -1) return ret;
    ret = 0;

    // 움직임 (1 -> 2) ( 2 -> 1)
    int f = go(tt + 1, pos^ 1, cnt - 1);

    // 움직이지 않음 
    int s = go(tt + 1, pos, cnt);

    ret = max(f, s) + (v[tt] == (pos-1));

    return ret;
}

int main(){
    cin >> t >> w;

    for(int i = 0; i<t ; i++){
        cin >> p;
        v.push_back(p);
    }

    memset(dp, -1, sizeof(dp));
    
    // 이동 o
    int f = go(0, 1, w-1);

    // 이동 x
    int s = go(0, 0, w);

    cout << max(f, s) << endl;

    return 0;
}
