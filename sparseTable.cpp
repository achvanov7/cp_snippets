#include <bits/stdc++.h>

using namespace std;

template<class C>
class sparse_table {
  vector<vector<C>> t;
  function<C(C, C)> key;
public:
  sparse_table(const vector<C>& a, function<C(C, C)> F) : key(F) {
    int n = a.size(), max_log = 32 - __builtin_clz(n);
    t.resize(max_log);
    t[0] = a;
    for (int j = 1; j < max_log; ++j) {
      t[j].resize(n - (1 << j) + 1);
      for (int i = 0; i < n - (1 << j) + 1; ++i) {
        t[j][i] = key(t[j - 1][i], t[j - 1][i + (1 << (j - 1))]);
      }
    }
  }
  C get(int l, int r) {
    int lg = 32 - __builtin_clz(r - l + 1) - 1;
    return key(t[lg][l], t[lg][r - (1 << lg) + 1]);
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);



  return 0;
}
