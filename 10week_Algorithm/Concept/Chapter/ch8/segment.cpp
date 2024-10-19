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
    
    // 1. 범위 겹치지 않는 경우 (탐색 x)
    if(left > end || right < start) return 0; 

    /**
     * 2. cur_node가 담당하는 [start,end] 범위가
     *    합을 구해야하는 범위인 [left, right] 범위에 포함되는 경우
     * 
     * [start, end]가 [left, right] 범위에 포함되기 때문에 바로 반환
     * */ 
    if(left <= start && end <= right) return segmentTree[cur_node];

    // 3. 왼쪽 or 오른쪽 자식을 루트로 하는 트리에서 다시 탐색 
    int mid = (start + end) / 2;
    int left_sum = sum(cur_node*2, start, mid, left, right);
    int right_sum = sum(cur_node*2 + 1, mid+1, end, left, right);

    return left_sum + right_sum;
}

void update_segmentTree(int cur_node, int start, int end, int idx, int diff){
    // 범위 벗어남 
    if(idx < start || idx > end) return;

    // idx에 영향을 받은 노드들 
    segmentTree[cur_node] = segmentTree[cur_node] + diff;

    // 리프 노드가 아닌 경우 자식 노드들도 변경해주어야 함
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

    // update
    int idx = 1;
    int val = 5;
    int diff = val - arr[idx];
    arr[idx] = val;
    update_segmentTree(1,0,n-1,idx,diff);

    return 0;
}