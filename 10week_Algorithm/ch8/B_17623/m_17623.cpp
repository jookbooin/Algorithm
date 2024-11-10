/***
 * < 접합 >
 * xy 
 * - () = 1
 * - {} = 2
 * - [] = 3
 * - 
 * <다시 감쌈>
 * (x) [x] {x}
 * - (x) : 2 * val(x)
 * - {x} : 3 * val(x)
 * - [x] : 5 * val(x)
 * 
 * <dmap>
 * ( ) { } [ ]
 * 1 2 3 4 5 6
 * 
 * 
 * <출력>
 * dmap값 최소 
 * 
 * t = 100
 * n = 1000
 * 
 * 
 */
#include <bits/stdc++.h>

using namespace std;

string dp[1004];
char ch[7] = {' ', '(',')', '{','}','[',']'};

int n,t;
string temp;

bool check(string a, string b){
    if(a == "" && b == "") return false;
    if(a == "") return true; 
    if(a.size() == b.size()){ // b가 사전순으로 작으면 true
        return b < a; 
    }
    return b.size() < a.size(); // b의 길이가 더 작으면 true
}

int main(){

    cin >> n;
    dp[1] = "12";
    dp[2] = "34";
    dp[3] = "56";

    for(int idx = 1; idx <= 1000; idx++){   

		if(idx % 2 == 0 && check(dp[idx], '1' + dp[idx / 2] + '2')) dp[idx] = '1' + dp[idx / 2] + '2'; 
		if(idx % 3 == 0 && check(dp[idx], '3' + dp[idx / 3] + '4')) dp[idx] = '3' + dp[idx / 3] + '4'; 
		if(idx % 5 == 0 && check(dp[idx], '5' + dp[idx / 5] + '6')) dp[idx] = '5' + dp[idx / 5] + '6';   

		for(int i = 1; i < idx; i++){
			if(check(dp[idx], dp[i] + dp[idx - i]))dp[idx] = dp[i] + dp[idx - i]; 
		}
	}  

    for(int i = 0 ; i<n; i++){
        cin >> t;
        cout << dp[t] << endl;
    }

    return 0;
}