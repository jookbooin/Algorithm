#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 4;
int n, num, len = 0;
int lis[1000004];

int main(){
    cin >> n;

    fill(&lis[0], &lis[0] + 1000004, INF );
    for(int i = 0; i<n; i++){
        cin >> num;

        auto lowerPos = lower_bound(lis, lis+len, num);
        if(*lowerPos == INF){
            len++;
        }
        *lowerPos = num;
    }

    cout << len << endl;

    return 0;
}