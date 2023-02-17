#include <bits/stdc++.h>

using namespace std;

class segtree {
public:
  struct node {
    node() {}

    void apply(int l, int r) {

    }
  };

  node merge(const node& a, const node& b) const {
    return node();
  }

  int n;
  vector<node> t;

  void push(int v, int l, int r) {
    int m = l + r >> 1;
    t[v << 1].apply(l, m);
    t[v << 1 | 1].apply(m + 1, r);
  }

  template<typename... M> void modify(int v, int tl, int tr, int l, int r, const M&... m) {
    if (l <= tl and tr <= r) {
      t[v].apply(tl, tr, m...);
      return;
    }
    if (tl > r or l > tr) {
      return;
    }
    push(v, tl, tr);
    int tm = tl + tr >> 1;
    modify(v << 1, tl, tm, l, r, m...), modify(v << 1 | 1, tm + 1, tr, l, r, m...);
    t[v] = merge(t[v << 1], t[v << 1 | 1]);
  }

  node get(int v, int tl, int tr, int l, int r) {
    if (l <= tl and tr <= r) return t[v];
    if (tl > r or l > tr) return node();
    push(v, tl, tr);
    int tm = tl + tr >> 1;
    return merge(get(v << 1, tl, tm, l, r), get(v << 1 | 1, tm + 1, tr, l, r));
  }

  node getElem(int v, int tl, int tr, int k) {
    if (tl == tr) return t[v];
    push(v, tl, tr);
    int tm = tl + tr >> 1;
    if (k <= tm) return getElem(v << 1, tl, tm, k);
    else return getElem(v << 1 | 1, tm + 1, tr, k);
  }

  template<typename... M> void setElem(int v, int tl, int tr, int k, const M&... m) {
    if (tl == tr) {
      t[v] = node(m...);
      return;
    }
    push(v, tl, tr);
    int tm = tl + tr >> 1;
    if (k <= tm) setElem(v << 1, tl, tm, k, m...);
    else setElem(v << 1 | 1, tm + 1, tr, k, m...);
    t[v] = merge(t[v << 1], t[v << 1 | 1]);
  }

  int find_first_knowingly(int v, int tl, int tr, const function<bool(const node&)> &f) {
    if (tl == tr) return tl;
    push(v, tl, tr);
    int tm = tl + tr >> 1;
    if (f(t[v << 1])) {
      return find_first_knowingly(v << 1, tl, tm, f);
    } else {
      return find_first_knowingly(v << 1 | 1, tm + 1, tr, f);
    }
  }

  int find_first(int v, int tl, int tr, int l, int r, const function<bool(const node&)> &f) {
    if (l <= tl and tr <= r) {
      if (!f(t[v])) return -1;
      return find_first_knowingly(v, tl, tr, f);
    }
    if (l > tr or tl > r) return -1;
    push(v, tl, tr);
    int tm = tl + tr >> 1;
    int res = -1;
    if (l <= tm) res = find_first(v << 1, tl, tm, l, r, f);
    if (r > tm and res == -1) res = find_first(v << 1 | 1, tm + 1, tr, l, r, f);
    return res;
  }

  int find_last_knowingly(int v, int tl, int tr, const function<bool(const node&)> &f) {
    if (tl == tr) return tl;
    push(v, tl, tr);
    int tm = tl + tr >> 1;
    if (f(t[v << 1 | 1])) {
      return find_last_knowingly(v << 1 | 1, tm + 1, tr, f);
    } else {
      return find_last_knowingly(v << 1, tl, tm, f);
    }
  }

  int find_last(int v, int tl, int tr, int l, int r, const function<bool(const node&)> &f) {
    if (l <= tl and tr <= r) {
      if (!f(t[v])) return -1;
      return find_last_knowingly(v, tl, tr, f);
    }
    if (l > tr or tl > r) return -1;
    push(v, tl, tr);
    int tm = tl + tr >> 1;
    int res = -1;
    if (r > tm) res = find_last(v << 1 | 1, tm + 1, tr, l, r, f);
    if (l <= tm and res == -1) res = find_last(v << 1, tl, tm, l, r, f);
    return res;
  }

  segtree(int _n = 0) {
    int p = 1;
    while ((1 << p) < _n) {
      ++p;
    }
    n = 1 << p;
    t.resize(n << 1);
    for (int i = n - 1; i >= 1; --i) {
      t[i] = merge(t[i << 1], t[i << 1 | 1]);
    }
  }

  template<class T> segtree(const vector<T>& a) {
    int p = 1;
    while ((1 << p) < a.size()) {
      ++p;
    }
    n = 1 << p;
    t.resize(n << 1);
    for (int i = 0; i < a.size(); ++i) {
      t[i + n] = a[i];
    }
    for (int i = n - 1; i >= 1; --i) {
      t[i] = merge(t[i << 1], t[i << 1 | 1]);
    }
  }

  template<typename... M> void modify(int l, int r, const M&... m) {
    modify(1, 0, n - 1, l, r, m...);
  }

  node get(int l, int r) {
    return get(1, 0, n - 1, l, r);
  }

  node getElem(int k) {
    return getElem(1, 0, n - 1, k);
  }

  template<typename... M> void setElem(int k, const M&... m) {
    setElem(1, 0, n - 1, k, m...);
  }

  node operator[](int i) {
    return t[i];
  }

  int find_first(int l, int r, const function<bool(const node&)> &f) {
    return find_first(1, 0, n - 1, l, r, f);
  }

  int find_last(int l, int r, const function<bool(const node&)> &f) {
    return find_last(1, 0, n - 1, l, r, f);
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);



  return 0;
}
