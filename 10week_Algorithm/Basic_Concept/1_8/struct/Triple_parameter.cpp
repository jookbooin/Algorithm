struct Point {
    int x, y, z;
    Point(int y, int x, int z) : y(y), x(x), z(z) {}
    Point() { y = -1, x = -1, z = -1; }
    bool operator<(const Point& a) const {
        if (x == a.x) {
            if (y == a.y) return z < a.z;
            return y > a.y;
        }
        return x < a.x;
    }
};