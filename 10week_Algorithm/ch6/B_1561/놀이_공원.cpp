
#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll rmax = 60000000000;
ll n,m,lf,rt,ans;

bool check(ll mid, vector<ll>& lv){
    ll sum = m; // 학생 수
    for(ll a : lv){
        sum += ( mid / a);
    }

    return sum >= n;
}

int main(){
    cin >> n >> m;

    vector<ll> v(m);

    if(n <= m){
        cout << n << endl;
        return 0;
    }

    for(ll i = 0; i<m; i++){
        cin >> v[i];
    }

    lf = 0, rt = rmax;
    while(lf <= rt){
        ll mid = (lf + rt) / 2;

        if(check(mid, v)){
            rt = mid - 1;
            ans = mid;
        }else{
            lf = mid + 1;
        }
    }

    // ans : 정답일수도 있는 시간????
    ll sum = m;
    for(ll i = 0; i <m; i ++){
        sum += ((ans-1)/ v[i]);
    }
    
    for(int i = 0; i<m; i++){
        if(ans % v[i] == 0){
            sum++;
        }

        if(sum == n){
            cout << i + 1 << '\n';
            break;
        }
    }
    
    return 0;

}