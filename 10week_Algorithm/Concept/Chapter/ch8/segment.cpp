#include <bits/stdc++.h>

using namespace std;
#define MAX 1000004

typedef long long ll;

ll n,m,k,a,b,c;
ll arr[MAX];
vector<int> segmentTree;

int make_segmentTree(int cur_node, int start, int end){
    if(start == end) return segmentTree[cur_node] = arr[start];

    int mid = (start + end) / 2;

    int left = make_segmentTree(cur_node * 2, start, mid);
    int right = make_segmentTree(cur_node * 2 + 1, mid + 1, end);

    segmentTree[cur_node] = left + right;

    return segmentTree[cur_node];
}

// 2. 구간합 
// [start, end] : 해당 노드가 포함하고 있는 범위
// [left, right] : 우리가 구하고자 하는 범위

int sum(int cur_node, int start, int end, int left, int right){
    
    // 1. 범위가 완전히 일치하지 않는 경우 
    if(left > end || right < start) return 0; 

    // 2. 탐색 범위가 완전히 속해 있다.
    if(left <= start && end <= right) return segmentTree[cur_node];

    // 3. 일부만 걸쳐있는 경우 
    int mid = (start + end) / 2;
    int left_sum = sum(cur_node*2, start, mid, left, right);
    int right_sum = sum(cur_node*2 + 1, mid+1, end, left, right);

    return left_sum + right_sum;
}

void update_segmentTree(int cur_node, int start, int end, int idx, int diff){
    // 범위 벗어남 
    if(idx < start || idx > end) return;

    segmentTree[cur_node] = segmentTree[cur_node] + diff;

    if(start != end){
        int mid = (start + end) / 2;
        update_segmentTree(cur_node*2, start, mid, idx, diff);
        update_segmentTree(cur_node*2 + 1, mid + 1, end, idx, diff);
    }
    
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int height = ceil(log2(n));
	int tsize = 1 << (height + 1);

    make_segmentTree(1, 0, n-1);

    return 0;
}