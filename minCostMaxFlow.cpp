#include <bits/stdc++.h>

using namespace std;

template<typename T, typename C> class mcmf {
public:
  const T infT = numeric_limits<T>::max();
  const C infC = numeric_limits<C>::max();
  const int n, source, sink;

  struct edge {
    int from, to;
    T c, f;
    C cost;
  };

  vector<vector<int>> g;
  vector<edge> edges;
  vector<C> d;
  queue<int> q;
  vector<bool> in_queue;
  vector<int> pe;
  T flow;
  C cost;

  mcmf(int _n, int _s, int _t) : n(_n), source(_s), sink(_t) {
    g.resize(n);
    d.resize(n);
    in_queue.resize(n);
    pe.resize(n);
    flow = cost = 0;
  }

  void addEdge(int from, int to, T fcap, T bcap, C cost) {
    g[from].push_back(edges.size());
    edges.push_back({from, to, fcap, 0, cost});
    g[to].push_back(edges.size());
    edges.push_back({to, from, bcap, 0, -cost});
  }

  bool expath() {
    fill(d.begin(), d.end(), infC);
    q.push(source);
    d[source] = 0;
    in_queue[source] = true;
    bool found = false;
    while (!q.empty()) {
      int i = q.front();
      q.pop();
      if (i == sink) {
        found = true;
      }
      in_queue[i] = false;
      for (int id : g[i]) {
        auto &e = edges[id];
        if (e.c - e.f > 0 and d[i] + e.cost < d[e.to]) {
          d[e.to] = d[i] + e.cost;
          pe[e.to] = id;
          if (!in_queue[e.to]) {
            q.push(e.to);
            in_queue[e.to] = true;
          }
        }
      }
    }
    if (found) {
      T push = infT;
      int v = sink;
      while (v != source) {
        auto &e = edges[pe[v]];
        push = min(push, e.c - e.f);
        v = e.from;
      }
      v = sink;
      while (v != source) {
        auto &e = edges[pe[v]];
        e.f += push;
        auto &be = edges[pe[v] ^ 1];
        be.f -= push;
        v = e.from;
      }
      flow += push;
      cost += push * d[sink];
    }
    return found;
  }

  pair<T, C> minCostMaxFlow() {
    while (expath()) {}
    return {flow, cost};
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);



  return 0;
}
