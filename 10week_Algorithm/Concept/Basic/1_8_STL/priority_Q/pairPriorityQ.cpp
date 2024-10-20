#include <iostream>
#include <queue>

using namespace std;

priority_queue<pair<int, int>> pq1;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq2;

int main() {
    pq1.push({1, 2});
    pq1.push({1, 3});
    pq1.push({2, 2});
    pq1.push({2, 5});
    pq1.push({3, 1});

    while (!pq1.empty()) {
        cout << pq1.top().first << " " << pq1.top().second << endl;
        pq1.pop();
    }

    cout << endl;

    pq2.push({1, 2});
    pq2.push({1, 3});
    pq2.push({2, 2});
    pq2.push({2, 5});
    pq2.push({3, 1});

    while (!pq2.empty()) {
        cout << pq2.top().first << " "<<pq2.top().second << endl;
        pq2.pop();
    }

    return 0;
}
