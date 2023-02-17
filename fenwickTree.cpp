#include <bits/stdc++.h>

using namespace std;

template<typename C>
class fenwick {
  vector<C> t;
  int n;
public:
  fenwick(int _n = 0) : n(_n) {
    t.resize(n);
  }
  fenwick(const vector<C>& a) : n(a.size()) {
    t.resize(n);
    for (int i = 0; i < n; ++i) {
      upd(i, a[i]);
    }
  }

  C get(int k) {
    C res = 0;
    for (k; k >= 0; k = (k & (k + 1)) - 1) {
      res += t[k];
    }
    return res;
  }

  void upd(int k, C x) {
    for (k; k < n; k |= k + 1) {
      t[k] += x;
    }
  }

  C get(int l, int r) {
    return get(r) - get(l - 1);
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);



  return 0;
}
