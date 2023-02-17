#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int add(int a, int b) {
  return a + b - mod * (a + b >= mod);
}

int mul(int a, int b) {
  return int(1ll * a * b % mod);
}

int pwr(int a, int x) {
  if (x == 0) {
    return 1;
  }
  return mul(pwr(mul(a, a), x >> 1), (x & 1 ? a : 1));
}

int dvd(int a, int b) {
  return mul(a, pwr(b, mod - 2));
}

int sub(int a, int b) {
  return a - b + mod * (a < b);
}

void inc(int& a, int b) {
  a = add(a, b);
}

void dec(int& a, int b) {
  a = sub(a, b);
}

class matrix {
  int n, m;
  vector<vector<int>> data;
  matrix base(int n) {
    matrix b(n, n);
    for (int i = 0; i < n; ++i) {
      b[i][i] = 1;
    }
    return b;
  }
public:
  matrix(int _n, int _m) : n(_n), m(_m) {
    data.resize(n, vector<int>(m));
  }
  vector<int>& operator[](int i) {
    return data[i];
  }
  matrix operator*(matrix b) {
    matrix a = (*this), c(a.n, b.m);
    if (a.m != b.n) {
      throw 1;
    }
    for (int i = 0; i < a.n; ++i) {
      for (int j = 0; j < b.m; ++j) {
        for (int k = 0; k < a.m; ++k) {
          inc(c[i][j], mul(a[i][k], b[k][j]));
        }
      }
    }
    return c;
  }
  template<typename T> matrix operator^(T x) {
    if (x == 0) {
      return base(n);
    }
    matrix a = *this;
    return ((a * a) ^ (x >> 1)) * (x & 1 ? a : base(n));
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);



  return 0;
}
