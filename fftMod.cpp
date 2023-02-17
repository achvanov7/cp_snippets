#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

int add() { return 0; }

template<typename... M>
int add(int a, M... b) {
  int x = add(b...);
  return a + x - mod * (a + x >= mod);
}

int mul() { return 1; }

template<typename... M>
int mul(int a, M... b) {
  return int(1ll * a * mul(b...) % mod);
}

int pwr(int a, long long x) {
  return (x ? mul(pwr(mul(a, a), x >> 1), (x & 1 ? a : 1)) : 1);
}

int inv(int a) {
  return pwr(a, mod - 2);
}

int sub(int a, int b) {
  return a - b + mod * (a < b);
}

void inc(int &a, int b) {
  a = add(a, b);
}

void dec(int &a, int b) {
  a = sub(a, b);
}

vector<int> fact = {1}, invf = {1};

int C(int n, int k) {
  if (n < k or 0 > k) return 0;
  while (fact.size() <= n) {
    fact.push_back(mul(fact.back(), fact.size()));
    invf.push_back(inv(fact.back()));
  }
  return mul(fact[n], invf[k], invf[n - k]);
}

int base = 1, max_base = -1, root = -1;
vector<int> roots = {0, 1};

void init() {
  int tmp = mod - 1;
  max_base = 0;
  while ((tmp & 1) == 0) {
    tmp >>= 1;
    ++max_base;
  }
  root = 2;
  while (true) {
    if (pwr(root, 1 << max_base) == 1) {
      if (pwr(root, 1 << (max_base - 1)) != 1) {
        break;
      }
    }
    ++root;
  }
}

void ensure_base(int nbase) {
  if (max_base == -1) {
    init();
  }
  if (nbase <= base) {
    return;
  }
  roots.resize(1 << nbase);
  while (base < nbase) {
    int z = pwr(root, 1 << (max_base - 1 - base));
    for (int i = 1 << (base - 1); i < (1 << base); ++i) {
      roots[i << 1] = roots[i];
      roots[i << 1 | 1] = mul(roots[i], z);
    }
    ++base;
  }
}

void fft(vector<int>& a) {
  int n = a.size();
  for (int i = 1, k = 0; i < n; ++i) {
    for (int bit = n >> 1; (k ^= bit) < bit; bit >>= 1) {}
    if (i < k) {
      swap(a[i], a[k]);
    }
  }
  for (int k = 1; k < n; k <<= 1) {
    for (int i = 0; i < n; i += (k << 1)) {
      for (int j = 0; j < k; ++j) {
        int x = a[i + j], y = mul(a[i + j + k], roots[j + k]);
        a[i + j] = add(x, y);
        a[i + j + k] = sub(x, y);
      }
    }
  }
}

vector<int> mul(vector<int> a, vector<int> b) {
  int need = (int)a.size() + (int)b.size() - 1;
  int nbase = 0;
  while ((1 << nbase) < need) {
    ++nbase;
  }
  ensure_base(nbase);
  int sz = 1 << nbase;
  bool eq = a == b;
  a.resize(sz), b.resize(sz);
  fft(a);
  if (eq) {
    b = a;
  } else {
    fft(b);
  }
  int inv = dvd(1, sz);
  for (int i = 0; i < sz; ++i) {
    a[i] = mul(a[i], b[i], inv);
  }
  reverse(a.begin() + 1, a.end());
  fft(a);
  a.resize(need);
  while (!a.empty() && a.back() == 0) {
    a.pop_back();
  }
  return a;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);



  return 0;
}
