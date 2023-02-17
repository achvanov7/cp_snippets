#include <bits/stdc++.h>

using namespace std;

class dsu {
  vector<int> p, sz;
public:
  dsu(int n) {
    p.resize(n);
    sz.resize(n, 1);
    iota(p.begin(), p.end(), 0);
  }

  int get(int v) {
    return (v == p[v] ? v : p[v] = get(p[v]));
  }

  bool unite(int u, int v) {
    u = get(u), v = get(v);
    if (u == v) {
      return false;
    }
    if (sz[u] < sz[v]) swap(u, v);
    p[v] = u;
    sz[u] += sz[v];
    return true;
  }

  int size(int v) {
    return sz[get(v)];
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);



  return 0;
}
