#include <bits/stdc++.h>

using namespace std;
typedef long long ll; // 64

ll n,m,k, a,b,c;

ll arr[1000004];
ll tree[1000004];

ll init(vector<ll>& tree, int cur_node, int start, int end){
    
    if(start == end) return tree[cur_node] = arr[start];

    ll mid = (start + end)/2;
    ll left_t = init(tree, cur_node * 2, start, mid);
    ll right_t = init(tree, cur_node * 2 + 1, mid + 1, end);

    tree[cur_node] = left_t + right_t;

    return tree[cur_node];
}

void update(vector<ll>& v, int cur_node, int start, int end, int idx, ll diff){
    // 범위 벗어남
    if(idx < start || idx > end) return;
    
    tree[cur_node] += diff;

    if(start != end){
        int mid = (start + end) / 2;
        update(v, cur_node * 2, start, mid, idx, diff);
        update(v, cur_node * 2 + 1, mid+1, end, idx, diff);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin .tie(0);
    cin.tie(0);

    cin >> n >> m >> k;

    for(int i = 1; i<=n; i++){
        cin >> arr[i];
    }

    ll height = (ll)ceil(log2(n));
    ll tree_size = (1 << (height + 1));

    vector<ll> stree (tree_size);


    init(stree,1, 1, n);

    for(int i = 0; i< m + k ; i++){
        cin >> a >> b >> c;
        if(a == 1){

        }else{ // 합 출력
            
        }
    }

    return 0;
}