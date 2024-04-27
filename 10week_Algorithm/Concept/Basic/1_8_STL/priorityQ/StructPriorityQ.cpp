#include <bits/stdc++.h>
using namespace std;

struct Point{

    int y,x;

    Point(int y, int x) : y(y), x(x){}
    Point(){y = -1, x = -1;}

    // bool operator < (const Point & a) const {
    //     return x > a.x;
    // }

    // custom 정렬을 넣을때는 반대로 넣어주어야 함.
    bool operator < (const Point & a) const {
        return x < a.x;
    }

};

struct Point2 {
    int y, x;
};

struct cmp{
    bool operator() (Point2 a, Point2 b){
        return a.x < b.x;
    }
};

priority_queue<Point> pq;
priority_queue<Point2,vector<Point2>,cmp> pq2;

int main(){

    pq.push({1,1});
    pq.push({2,2});
    pq.push({3,3});
    pq.push({4,4});
    pq.push({5,5});
    pq.push({6,6});

    cout << pq.top().x << "\n";

    pq2.push({1,1});
    pq2.push({2,2});
    pq2.push({3,3});
    pq2.push({4,4});
    pq2.push({5,5});
    pq2.push({6,6});

    cout << pq2.top().x << "\n";

    return 0;

}