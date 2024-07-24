#include <bits/stdc++.h>

using namespace std;

int t,n,m,input;
int arr[20004], brr[20004];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;

    for(int i = 0; i< t ; i++){
        cin >> n >> m;  

        int sum = 0;
        vector<int> av(n),bv(m);

        for(int j = 0; j< n; j++){
            cin >> av[i];
            
        }

        for(int j = 0; j< m; j++){
            cin >> bv[i];
        }

        sort(av.begin(),av.end());
        sort(bv.begin(),bv.end());


        for(int a : av){ 
            int num = lower_bound(bv.begin(), bv.end(), a) - bv.begin();
            sum += (num);

        }

        cout << sum << endl;

    }
    return 0;
}