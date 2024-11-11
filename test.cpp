#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> tree, y_com;
vector<pair<int, int>> point;

int t, n, x, y;

int sum (int idx){
    int ret = 0;
    while(idx > 0){
        ret += tree[idx];
        idx -= (idx & -idx);
    }
    return ret;
}
void update(int pos, int value){
    int idx = pos;
    while(idx <= n){
        tree[idx] += value;
        idx += (idx & -idx);
    }
    return;
}

int find_index(const vector<int> & _y, int value){
    int lo = 0, hi = _y.size() - 1;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if(_y[mid] == value) return mid;
        if(_y[mid] < value) lo = mid + 1;
        else hi = mid - 1;
    }
}

bool y_cmp(int a, int b) {
    return a > b;
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }

    return a.first < b.first;
}

void print_tree(){
    cout <<"    tree : ";
    for(int i = 0; i<=n; i++){
        cout << tree[i] <<" ";
    }
    cout << "\n\n";
}

void print_vv(vector<int>& v){
    cout <<"    v : ";
    for(int i = 0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while (t--) {
        cin >> n;
        tree.clear();
        y_com.clear();
        point.clear();
        tree.resize(n + 1);

        for (int i = 0; i < n; i++) {
            cin >> x >> y;
            point.push_back({x, y});
            y_com.push_back(y);
        }

        sort(point.begin(), point.end(),cmp);   // x 오름차순, y 내림차순
        sort(y_com.begin(), y_com.end());  // y 내림차순
        print_vv(y_com);

        ll ret = 0;
        int cy = point[0].second;
        int idx = find_index(y_com, cy) + 1;
        cout << "cy : "<< point[0].second << " idx : " << idx << endl;
        update(idx, 1);  //
        print_tree();

        for (int i = 1; i < n; i++) {
            cy = point[i].second;
            idx = find_index(y_com, cy) + 1;

            cout << "cy : "<< cy << " idx : " << idx << endl;
            ret += sum(idx);
            update(idx, 1);
            print_tree();
        }
        cout << ret << endl;
    }
    return 0;
}