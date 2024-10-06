#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MVAL = 1e9 + 4;
int n, c, p;
int arr [34];
vector<int> av; // 0 ~ n/2 -1
vector<int> bv; // n/2 ~ n-1

void go(int start, int end,vector<int>& v, int sum) {
    
    // 종료 조건 
    if(sum > c) return;

    if(start > end){
        v.push_back(sum);
        return;
    }

    // 포함
    go(start + 1, end, v,sum + arr[start]);

    // 포함 x 
    go(start + 1, end, v,sum);
    
}

int main() {
    cin >> n >> c;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 0 ~ n/2 - 1 합
    go(0, n / 2 - 1, av,0);

    // n/2 ~ n - 1 합 
    go(n / 2, n - 1, bv,0);

    // 정렬 
    sort(av.begin(), av.end());
    sort(bv.begin(), bv.end());

    // bv에서 찾는다.
    ll sum = 0;
    for(int a : av){
        if(c >= a){
            sum += (upper_bound(bv.begin(), bv.end(), c-a) - bv.begin());
        }
    }

    cout << sum << endl;
    return 0;
}
