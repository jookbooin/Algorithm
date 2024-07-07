#include <bits/stdc++.h>
using namespace std;

struct Point {
    int y, x;

    Point(int y, int x) : y(y), x(x) {}
    Point() { y = -1, x = -1; }

    // bool operator < (const Point & a) const {
    //     return x > a.x;
    // }

    // custom 정렬을 넣을때는 반대로 넣어주어야 함.
    bool operator<(const Point& a) const {
        return x > a.x;
    }
};

struct Point2 {
    int x, y;
};

struct cmp1 {
    bool operator()(Point2 a, Point2 b) {
        return a.x < b.x;
    }
};

struct cmp2 {
    bool operator()(Point2 a, Point2 b) {
        return a.x > b.x;
    }
};

struct cmp3 {
    bool operator()(Point2 a, Point2 b) {
        return a.y > b.y;
    }
};

struct cmp4 {
    bool operator()(Point2 a, Point2 b) {
        return a.y < b.y;
    }
};

priority_queue<Point> pq;
priority_queue<Point2, vector<Point2>, cmp1> pq1;
priority_queue<Point2, vector<Point2>, cmp2> pq2;
priority_queue<Point2, vector<Point2>, cmp3> pq3;
priority_queue<Point2, vector<Point2>, cmp4> pq4;

int main() {
    cout << "일반 pq" << '\n';
    pq.push({1, 1});
    pq.push({2, 2});
    pq.push({3, 3});
    pq.push({4, 4});
    pq.push({5, 5});
    pq.push({6, 6});

    while (pq.size()) {
        cout << pq.top().x << "\n";
        pq.pop();
    }
    cout << endl;

    cout << " pq1 - a.x < b.x : 내림차순" << '\n';
    pq1.push({1, 1});
    pq1.push({2, 2});
    pq1.push({3, 3});
    pq1.push({4, 4});
    pq1.push({5, 5});
    pq1.push({6, 6});

    while (pq1.size()) {
        cout << pq1.top().x<< "\n";
        pq1.pop();
    }
    cout << endl;

    cout << " pq2 - a.x > b.x : 오름차순" << '\n';
    pq2.push({1, 1});
    pq2.push({2, 2});
    pq2.push({3, 3});
    pq2.push({4, 4});
    pq2.push({5, 5});
    pq2.push({6, 6});

    while (pq2.size()) {
        cout << pq2.top().x << "\n";
        pq2.pop();
    }
    cout << endl;

    cout << " pq3 - a.y > b.y : 오름차순" << '\n';
    pq3.push({1, 1});
    pq3.push({2, 2});
    pq3.push({3, 3});
    pq3.push({4, 4});
    pq3.push({5, 5});
    pq3.push({6, 6});

    while (pq3.size()) {
        cout << pq3.top().x << "\n";
        pq3.pop();
    }
    cout << endl;

    cout << " pq4 - a.y < b.y : 내림차순" << '\n';
    pq4.push({1, 1});
    pq4.push({2, 2});
    pq4.push({3, 3});
    pq4.push({4, 4});
    pq4.push({5, 5});
    pq4.push({6, 6});

    while (pq4.size()) {
        cout << pq4.top().x << "\n";
        pq4.pop();
    }
    cout << endl;

    return 0;
}