#include <bits/stdc++.h>

using namespace std;

const int mod1 = 1e9 + 7, mod2 = 1e9 + 9;

int pwr(int a, long long x, int mod) {
  if (x == 0) return 1;
  int sq = pwr(a, x / 2, mod);
  sq = 1ll * sq * sq % mod;
  if (x & 1) sq = 1ll * sq * a % mod;
  return sq;
}

struct mhash {
  long long l, r;

  long long norm(long long& x, const int mod) {
    x %= mod;
    if (x < 0) {
      x += mod;
    }
    return x;
  }

  mhash(long long _l, long long _r) : l(norm(_l, mod1)), r(norm(_r, mod2)) {}
  mhash(long long x = 0) : l(norm(x, mod1)), r(norm(x, mod2)) {}

  mhash operator = (const mhash& a) {
    l = a.l, r = a.r;
    return (*this);
  }
  mhash operator + (const mhash& a) const {
    return mhash(l + a.l, r + a.r);
  }
  mhash operator += (const mhash& a) {
    l += a.l;
    r += a.r;
    norm(l, mod1), norm(r, mod2);
    return (*this);
  }
  mhash operator * (const mhash& a) const {
    return mhash(l * a.l, r * a.r);
  }
  mhash operator *= (const mhash& a) {
    l *= a.l;
    r *= a.r;
    norm(l, mod1), norm(r, mod2);
    return (*this);
  }
  mhash operator - (const mhash& a) const {
    return mhash(l - a.l, r - a.r);
  }
  mhash operator -= (const mhash& a) {
    l -= a.l;
    r -= a.r;
    norm(l, mod1), norm(r, mod2);
    return (*this);
  }
  mhash operator / (const mhash& a) const {
    return mhash(l * pwr(a.l, mod1 - 2, mod1), r * pwr(a.r, mod2 - 2, mod2));
  }
  mhash operator /= (const mhash& a) {
    l *= pwr(a.l, mod1 - 2, mod1);
    r *= pwr(a.r, mod2 - 2, mod2);
    norm(l, mod1), norm(r, mod2);
    return (*this);
  }
  const bool operator < (const mhash& a) const {
    return l < a.l or (l == a.l and r < a.r);
  }
  const bool operator == (const mhash& a) const {
    return l == a.l and r == a.r;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);



  return 0;
}
