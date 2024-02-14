#include <bits/stdc++.h>

using namespace std;

vector<int> tree[10004];

int N, M, mx, f, s;
int dp[10004], visited[10004];

int dfs(int idx) {
    visited[idx] = 1;
    int ret = 1;  //  ���� ���
    for (int a : tree[idx]) {
        if (visited[a]) continue;
        ret += dfs(a);      // + �ڽĵ�
    }
    
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;

    for (int i = 0; i < M; i++) {
        cin >> f >> s;
        tree[s].push_back(f);
    }

    for (int i = 1; i <= N; i++) {
        fill(&visited[0], &visited[0] + 10004, 0);
        dp[i] = dfs(i);         // ������� ��� + DP ����
        mx = max(dp[i], mx);
    }

    for(int i = 1; i<= N ;i++){
        if(mx == dp[i]){        // ������ �ƴ� �迭�� �����ϴ� ����� �ֳ�
            cout << i << " ";
        }
    }
}
