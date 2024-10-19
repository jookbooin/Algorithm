#include <bits/stdc++.h>

using namespace std;

#define end ff
const int INF = 1000000000;
const int SIZE = 300000;

int n, m, end = 0, start = 1, ret = INF;
int arr[SIZE];

bool check(int mid){

    int sum =0;
    for (int i = 0; i < m; i++) {
        sum += arr[i]/m;
        sum += arr[i]%mid ? 1 : 0;
    }

    return sum <= n; 
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i = 0; i< m; i++){
        cin >> arr[i];
        end = max(end, arr[i]);
    }

    while(start <= end){ 

        int mid = (start + end) / 2;

        if(check(mid)){ // mid 줄일 수 있다.
            ret = mid;
            end = mid - 1;
        }else{ // mid 크게 해야 한다.
            start = mid + 1;
        }
    }

    cout << ret << endl;

    return 0;
}