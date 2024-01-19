#include <bits/stdc++.h>

using namespace std;

struct Point {
    int y, x;
    Point(int y, int x) : y(y), x(x) {}

    // y,x 정의되지 않았을때 기본값 설정
    Point() { y = -1, x = -1 ;}

    /** 연산자 오버로딩
     *  '<' 의미는 변화시키지 않고 , 오퍼레이터만 변경시키는 것이므로
    bool operator < (const Point & a)const{
        if(x == a.x) 
            return y < a.y;
        return x < a.x;
    }
    */
};

struct Ralo {
    int a, b;
    double c, d, e;
};

void print(Ralo ralo) { cout << ralo.a << " " << ralo.b << " " << ralo.c << " " << ralo.d << " " << ralo.e << '\n'; }

int main() {
    Ralo ralo = {1, 1, 1, 1, 1};
    print(ralo);

    vector<Ralo> ret;
    ret.push_back({1, 2, 3, 4, 5});
    ret.push_back({1, 2, 3, 4, 6});
    ret.push_back({});
    ret.push_back({1, 3});

    for (Ralo ralo : ret) {
        print(ralo);
    }

    return 0;
}