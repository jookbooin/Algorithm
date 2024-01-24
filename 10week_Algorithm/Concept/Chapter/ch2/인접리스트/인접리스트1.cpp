#include <bits/stdc++.h>
using namespace std;
const int V = 4;
// vector<int> adj;
vector<int> adj[V];  // 리스트 여러개

int main() {
    adj[0].push_back(1);
    adj[0].push_back(2);
    adj[0].push_back(3);

    adj[1].push_back(0);
    adj[1].push_back(2);

    adj[2].push_back(0);
    adj[2].push_back(1);

    adj[3].push_back(0);

    for (int i = 0; i < 4; i++) {
        cout << i << " :: ";
        for (int there : adj[i]) {
            cout << there << " ";
        }
        cout << '\n';
    }
    
    cout <<endl;

    for (int i = 0; i < 4; i++) {
        cout << i << " :: ";
        for (int j = 0; j < adj[i].size(); j++) {
            cout << adj[i][j] << " ";
        }
        cout << '\n';
    }

}
