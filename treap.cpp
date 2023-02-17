#include <bits/stdc++.h>

using namespace std;

template<typename T>
class treap {
public:
  struct node {
    node* l;
    node* r;
    int sz = 0;
    T key;
  };

  T next(T k) {
    // TODO
  }

  int sz(node* t) {
    return (t ? t->sz : 0);
  }

  void recalc(node* t) {
    if (t) {
      t->sz = sz(t->l) + sz(t->r) + 1;
    }
  }

  pair<node*, node*> split(node* t, T k) {
    if (!t) return {0, 0};
    pair<node*, node*> p;
    if (t->key >= k) {
      p = split(t->l, k);
      t->l = p.second;
      recalc(t);
      p.second = t;
    } else {
      p = split(t->r, k);
      t->r = p.first;
      recalc(t);
      p.first = t;
    }
    return p;
  }

  node* merge(node* l, node* r) {
    if (!l) return r;
    if (!r) return l;
    if (rng() % (sz(l) + sz(r)) < sz(l)) {
      l->r = merge(l->r, r);
      recalc(l);
      return l;
    } else {
      r->l = merge(l, r->l);
      recalc(r);
      return r;
    }
  }

  node* get(node* t, int i) {
    if (!t) return t;
    if (sz(t->l) >= i) return get(t->l, i);
    else if (i == sz(t->l) + 1) return t;
    else return get(t->r, i - sz(t->l) - 1);
  }

  int lower_bound_index(node* t, T k) {
    if (!t) return 0;
    if (t->key < k) return sz(t->l) + 1 + lower_bound_index(t->r, k);
    else return lower_bound_index(t->l, k);
  }

  void insert(T k) {
    node* t = new node();
    t->key = k;
    recalc(t);
    auto s1 = split(root, k), s2 = split(s1.second, next(k));
    root = merge(merge(s1.first, t), s2.second);
  }

  void erase(T k) {
    auto s1 = split(root, k), s2 = split(s1.second, next(k));
    assert(sz(s2.first) == 1 and s2.first->key == k);
    root = merge(s1.first, s2.second);
    delete s2.first;
  }

  node* operator[](int i) {
    return get(root, i + 1);
  }

  int lower_bound_index(T k) {
    return lower_bound_index(root, k);
  }

  node* lower_bound(T k) {
    return get(root, lower_bound_index(k) + 1);
  }

  int size() {
    return sz(root);
  }

  mt19937 rng = mt19937(chrono::steady_clock::now().time_since_epoch().count());
  node* root = nullptr;

  treap() {}
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);



  return 0;
}
