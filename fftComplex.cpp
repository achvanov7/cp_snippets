#include <bits/stdc++.h>

using namespace std;

struct comp {
  double re, im;

  comp(double x = 0, double y = 0) : re(x), im(y) {}

  comp operator+(const comp& a) { return comp(re + a.re, im + a.im); }
  comp operator-(const comp& a) { return comp(re - a.re, im - a.im); }
  comp operator*(const comp& a) { return comp(re * a.re - im * a.im, re * a.im + im * a.re); }
};

const double pi = acos(-1);

void fft(vector<comp>& x) {
  int n = x.size();
  for (int i = 1, k = 0; i < n; ++i) {
    for (int bit = n >> 1; (k ^= bit) < bit; bit >>= 1) {}
    if (i < k) {
      swap(x[i], x[k]);
    }
  }
  for (int k = 1; k < n; k <<= 1) {
    comp wlen(cos(pi / k), sin(pi / k));
    for (int i = 0; i < n; i += (k << 1)) {
      comp w(1);
      for (int j = 0; j < k; ++j) {
        comp tmp = w * x[i + j + k];
        x[i + j + k] = x[i + j] - tmp;
        x[i + j] = x[i + j] + tmp;
        w = w * wlen;
      }
    }
  }
}

template<class T> vector<T> mul(vector<T>& a, vector<T>& b) {
  int n = max(a.size(), b.size());
  int lg = 31 - __builtin_clz(n);
  n = 1 << (lg + 1 + (n != (1 << lg)));
  vector<comp> fa(n), fb(n);
  for (int i = 0; i < a.size(); ++i) {
    fa[i] = a[i];
  } for (int i = 0; i < b.size(); ++i) {
    fb[i] = b[i];
  }
  fft(fa);
  if (a == b) {
    fb = fa;
  } else {
    fft(fb);
  }
  for (int i = 0; i < n; ++i) {
    fa[i] = fa[i] * fb[i];
  }
  fft(fa);
  reverse(fa.begin() + 1, fa.end());
  vector<T> c(n);
  for (int i = 0; i < n; ++i) {
    c[i] = (T)(fa[i].re / n + (fa[i].re > 0 ? 0.5 : -0.5));
  }
  return c;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);



  return 0;
}
