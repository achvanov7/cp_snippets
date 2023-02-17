#include <bits/stdc++.h>

using namespace std;

template<int D = 30, typename T = int> class xorbasis {
public:
  array<T, D> basis;
  int size = 0;

  xorbasis() {
    fill(basis.begin(), basis.end(), 0);
  }
  void insert(T mask) {
    for (int i = D - 1; i >= 0; --i) {
      if (mask >> i & 1) {
        if (basis[i] == 0) {
          basis[i] ^= mask;
          ++size;
          return;
        }
        mask ^= basis[i];
      }
    }
  }
  T maxValue() {
    T res = 0;
    for (int i = D - 1; i >= 0; --i) {
      if (res >> i & 1) continue;
      if (basis[i]) res ^= basis[i];
    }
    return res;
  }
};

template<int D = 30, typename T = int>
xorbasis<D, T> merge(xorbasis<D, T> a, xorbasis<D, T> b) {
  for (int i = 0; i < D; ++i) {
    if (b.basis[i]) {
      a.insert(b.basis[i]);
    }
  }
  return a;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);



  return 0;
}
