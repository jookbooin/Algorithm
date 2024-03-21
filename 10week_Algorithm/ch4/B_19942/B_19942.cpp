#include<bits/stdc++.h>
using namespace std; 
const int INF = 987654321;
int n, mp, mf, ms, mv;
int b, c, d, e, ret = INF,sum;
map<int, vector<vector<int>>> ret_v; // 최솟값 134 : { {1, 2} {2, 4, 5}, {3, 6} }

struct A{
    int p,f,s,v,cost;
};
A adj[16];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin >> n; 
    cin >> mp >> mf >> ms >> mv;  

    for(int i = 0; i < n; i++){
    	cin >> adj[i].p >> adj[i].f >> adj[i].s >> adj[i].v >> adj[i].cost;  
	}

    for(int i = 1; i< (1<<n); i++){ // 6개로 만들 수 있는 모든 경우의 수
        b = c = d = e = sum = 0;
        vector<int> v;

        for(int j = 0; j<n; j ++){ // 111111
            if(i & (1<<j)){
                    v.push_back(j+1);
                    b += adj[j].p;
                    c += adj[j].f;
                    d += adj[j].s;
                    e += adj[j].v;
                    sum += adj[j].cost;
                }
            }

            if(b >= mp && c >= mf && d >=ms && e >= mv){
                if(ret >= sum){
                    ret =sum; // 최소 비용
                    ret_v[ret].push_back(v); // key : 최소 비용
                }
            }
        }

    if(ret == INF) {
        cout << -1 << '\n';
    }else{ // ret은 최소 비용
        sort(ret_v[ret].begin(),ret_v[ret].end());
        cout << ret << '\n';
        for(int a : ret_v[ret][0]){
            cout << a << " ";
        }

    }


    return 0;
}