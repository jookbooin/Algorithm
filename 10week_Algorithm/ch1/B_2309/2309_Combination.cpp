
/**
 * 1. ����
 * 
 * n�� for�� 
*/

#include <bits/stdc++.h>
using namespace std;

int arr[9], sum; // �Է�
pair<int,int> ret;
vector<int> result;

void solve(){
    for(int i = 0 ; i<9 ; i++){
        for(int j = 0 ; j < i ; j ++ ){
            if(sum - arr[i] - arr[j] == 100){
                ret = {i,j};
                return;
            }
        }
    }
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    
    for (int i = 0; i < 9; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    solve();

    for(int i = 0 ; i<9 ; i++){
        if(i == ret.first || i == ret.second)
            continue;
        result.push_back(arr[i]);
    }

    sort(result.begin(),result.end());

    for(int answer : result)
        cout << answer << '\n';

    return 0;
}

