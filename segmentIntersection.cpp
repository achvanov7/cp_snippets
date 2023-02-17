#include <bits/stdc++.h>

using namespace std;

struct fraction {
  long long a, b;

  void norm() {
    assert(b != 0);
    long long g = gcd(abs(a), abs(b));
    a /= g;
    b /= g;
    if (b < 0) a *= -1, b *= -1;
  }
  fraction(long long x = 0, long long y = 1) : a(x), b(y) {
    norm();
  }
  double val() {
    return 1.0 * a / b;
  }
  bool operator<(const fraction& frac) const {
    return a * frac.b < b * frac.a;
  }
  bool operator==(const fraction& frac) const {
    return a == frac.a and b == frac.b;
  }
  bool operator<=(const fraction& frac) const { return (*this) < frac or (*this) == frac; }
  bool operator>(const fraction& frac) const { return !((*this) <= frac); };
  bool operator>=(const fraction& frac) const { return !((*this) < frac); };
  bool operator!=(const fraction& frac) const { return !((*this) == frac); };
  fraction operator+(const fraction& frac) {
    return fraction(a * frac.b + b * frac.a, b * frac.b);
  }
  fraction operator+=(const fraction& frac) {
    *this = *this + frac;
    return *this;
  }
  fraction operator-(const fraction& frac) {
    return fraction(a * frac.b - b * frac.a, b * frac.b);
  }
  fraction operator-=(const fraction& frac) {
    *this = *this - frac;
    return *this;
  }
  fraction operator*(const fraction& frac) {
    return fraction(a * frac.a, b * frac.b);
  }
  fraction operator*=(const fraction& frac) {
    *this = *this * frac;
    return *this;
  }
  fraction operator/(const fraction& frac) {
    return fraction(a * frac.b, b * frac.a);
  }
  fraction operator/=(const fraction& frac) {
    *this = *this / frac;
    return *this;
  }
};

struct line {
  long long a, b, c;

  void norm() {
    assert(a != 0 or b != 0);
    long long g = gcd(abs(a), gcd(abs(b), abs(c)));
    a /= g;
    b /= g;
    c /= g;
    if (c < 0 or (c == 0 and b < 0) or (c == 0 and b == 0 and a < 0)) {
      a *= -1;
      b *= -1;
      c *= -1;
    }
  }
  line(long long x, long long y, long long z) : a(x), b(y), c(z) {
    norm();
  }
  line (point p, point q) {
    a = q.y - p.y;
    b = p.x - q.x;
    c = p.y * q.x - p.x * q.y;
    norm();
  }
  bool operator<(const line& l) const {
    return make_tuple(a, b, c) < make_tuple(l.a, l.b, l.c);
  }
  bool operator==(const line& l) const {
    return make_tuple(a, b, c) == make_tuple(l.a, l.b, l.c);
  }
  bool operator<=(const line&  l) const { return (*this) < l or (*this) == l; }
  bool operator>(const line& l) const { return !((*this) <= l); };
  bool operator>=(const line& l) const { return !((*this) < l); };
  bool operator!=(const line& l) const { return !((*this) == l); };
};

bool same(const line& a, const line& b) {
  return a == b;
}

bool parallel(const line& a, const line& b) {
  if (same(a, b)) return false;
  if (a.b == 0) {
    return b.b == 0;
  } else if (b.b == 0) {
    return a.b == 0;
  }
  return fraction(a.a, -a.b) == fraction(b.a, -b.b);
}

array<fraction, 2> intersect(const line& a, const line& b) {
  assert(!same(a, b) and !parallel(a, b));
  return {fraction(b.b * a.c - a.b * b.c, b.a * a.b - a.a * b.b), fraction(b.a * a.c - a.a * b.c, a.a * b.b - b.a * a.b)};
}

// -1 no intersection, 0 infinitely many, 1 one intersection, 2 one intersection but they're colinear
pair<int, array<fraction, 2>> intersect(point a, point b, point c, point d) {
  if (a > b) swap(a, b);
  if (c > d) swap(c, d);
  if (a > c) swap(a, c), swap(b, d);
  line l1(a, b), l2(c, d);
  pair<int, array<fraction, 2>> res;
  if (same(l1, l2)) {
    if (b < c) {
      res.first = -1;
    } else if (b == c and b < d) {
      res.first = 2;
      res.second = {b.x, b.y};
    } else {
      res.first = 0;
    }
  } else if (parallel(l1, l2)) {
    res.first = -1;
  } else {
    res.second = intersect(l1, l2);
    res.first = -1;
    if (fraction(max(a.x, c.x)) <= res.second[0] and res.second[0] <= fraction(min(b.x, d.x)) and
        fraction(max(min(a.y, b.y), min(c.y, d.y))) <= res.second[1] and res.second[1] <= fraction(min(max(a.y, b.y), max(c.y, d.y)))) res.first = 1;
  }
  return res;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);



  return 0;
}
