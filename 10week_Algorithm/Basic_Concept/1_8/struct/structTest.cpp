#include <bits/stdc++.h>

using namespace std;

struct Point {
    int y, x;
    Point(int y, int x) : y(y), x(x) {}

    // y,x ���ǵ��� �ʾ����� �⺻�� ����
    Point() { y = -1, x = -1 ;}

    /** ������ �����ε�
     *  '<' �ǹ̴� ��ȭ��Ű�� �ʰ� , ���۷����͸� �����Ű�� ���̹Ƿ�
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