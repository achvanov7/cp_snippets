#include <bits/stdc++.h>

using namespace std;

struct point {
  long long x, y;

  point(long long _x = 0, long long _y = 0) : x(_x), y(_y) {}

  point operator + (point a) {
    return point(x + a.x, y + a.y);
  }
  point operator - (point a) {
    return point(x - a.x, y - a.y);
  }
  long long operator * (point a) {
    return x * a.y - a.x * y;
  }
  long long operator ^ (point a) {
    return x * a.x + y * a.y;
  }
  bool operator<(point a) const {
    return x < a.x or (x == a.x and y < a.y);
  }
  bool operator==(const point& a) const {
    return x == a.x and y == a.y;
  }
  bool operator<=(const point& a) const { return (*this) < a or (*this) == a; }
  bool operator>(const point& a) const { return !((*this) <= a); };
  bool operator>=(const point& a) const { return !((*this) < a); };
  bool operator!=(const point& a) const { return !((*this) == a); };

  long long len2() {
    return ((*this) ^ (*this));
  }
};

istream& operator>>(istream& in, point& a) {
  cin >> a.x >> a.y;
  return in;
}

long long dist2(point a, point b) {
  return (a - b).len2();
}
double dist(point a, point b) {
  return sqrt((a - b).len2());
}
double dist(point a, point b, point c) {
  return abs((a - b) * (a - c)) / dist(b, c);
}
double area(point a, point b, point c) {
  return abs((b - a) * (c - a)) / 2.0;
}
long long area2(point a, point b, point c) {
  return abs((b - a) * (c - a));
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);



  return 0;
}
