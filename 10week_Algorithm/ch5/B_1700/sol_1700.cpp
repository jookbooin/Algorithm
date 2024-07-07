#include<bits/stdc++.h>
using namespace std;
int k, n, a[104], visited[104], cnt;
const int INF = 987654321;
vector<int> v;
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> k >> n;
    for(int i = 0; i < n; i++) cin >> a[i];

    for(int i = 0; i < n; i++){
        if(!visited[a[i]]){
            if(v.size() == k){
                int last_idx = 0; // 가장 미래에 참조되는 것 
                int  erase_val;

                for(int cur : v){
                    int find_idx = INF;

                    // 1. 현재 수가 미래에 있는지 확인
                    for(int j = i + 1; j < n; j++){
                        if(cur == a[j]){ // 미래에 참조되는 것 
                            find_idx = j; break;
                        }
                    }

                    // 2. 가장 미래에 참조되는것 업데이트
                    if(last_idx < find_idx){
                        last_idx = find_idx;
                        erase_val = cur;
                    }
                }

                visited[erase_val] = 0;
                cnt++;
                v.erase(find(v.begin(), v.end(), erase_val));
            }

            v.push_back(a[i]); visited[a[i]] = 1;
        }
    }
    cout << cnt << "\n";
    return 0;
}
