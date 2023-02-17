#include <bits/stdc++.h>

using namespace std;

const int mod1 = 1e9 + 7, mod2 = 1e9 + 9;

class string_hash {
public:
  struct hash {
    long long l, r;
    long long norm(long long x, int mod) {
      x %= mod;
      if (x < 0) {
        x += mod;
      }
      return x;
    }
    hash(long long _l, long long _r) : l(norm(_l, mod1)), r(norm(_r, mod2)) {}
    hash(long long x = 0) : l(norm(x, mod1)), r(norm(x, mod2)) {}
    hash operator+(const hash& a) const {
      return hash(l + a.l, r + a.r);
    }
    hash operator-(const hash& a) const {
      return hash(l - a.l, r - a.r);
    }
    hash operator*(const hash& a) const {
        return hash(l * a.l, r * a.r);
    }
    bool operator==(const hash& a) const {
      return l == a.l and r == a.r;
    }
  };
  const hash P = {239, 997};
  int n;
  vector<hash> p, h, rh;
  string_hash(const string& s) : n(s.size()) {
    p.resize(n + 1);
    h.resize(n + 1);
    rh.resize(n + 1);
    p[0] = 1;
    for (int i = 1; i <= n; ++i) {
      p[i] = p[i - 1] * P;
      h[i] = h[i - 1] + p[i - 1] * (s[i - 1] - 'a' + 1);
    }
    for (int i = n - 1; i >= 0; --i) {
      rh[i] = rh[i + 1] + p[n - 1 - i] * (s[i] - 'a' + 1);
    }
  }
  bool is_equal(int i, int j, int len) {
    if (i > j) {
      swap(i, j);
    }
    return (h[i + len] - h[i]) * p[j - i] == h[j + len] - h[j];
  }
  bool is_poly(int i, int j) {
    return (h[j + 1] - h[i]) * p[max(0, n - 1 - j - i)] == (rh[i] - rh[j + 1]) * p[max(0, i - n + 1 + j)];
  }
  bool is_equal(int i, int j, int k, int g) {
    if (j - i != g - k) return false;
    return (h[j + 1] - h[i]) * p[max(0, n - 1 - k - j)] == (rh[k] - rh[g + 1]) * p[max(0, 1 + k + j - n)];
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);



  return 0;
}
