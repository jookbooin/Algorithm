#include <bits/stdc++.h>
using namespace std;
int n, a, b, len, lis[504];
vector<pair<int, int>> v;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
	cin >> n;
	for(int i = 0; i < n; i++){
        cin >> a >> b;
        v.push_back({a, b});
	}

    // 정렬
	sort(v.begin(), v.end());

    // n개 만큼 찾아야 함 
    for(int i = 0; i < v.size(); i++){
        auto it = lower_bound(lis, lis + len, v[i].second); // lis 배열중 해당 값이 들어갈 위치 찾음
        
        if(*it == 0) { // 
            len++; 
        }
        *it = v[i].second;
    }
    
    cout << n - len << "\n"; 
    return 0;
}