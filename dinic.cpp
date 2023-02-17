#include <bits/stdc++.h>

using namespace std;

template<typename T> class dinic {
public:
  const T inf = numeric_limits<T>::max();
  const int n, source, sink;

  struct edge {
    int from, to;
    T c, f;
  };

  vector<vector<int>> g;
  vector<edge> edges;
  vector<int> d, ptr;
  queue<int> q;
  T need = 1;

  dinic(int _n, int _s, int _t) : n(_n), source(_s), sink(_t) {
    g.resize(n);
    d.resize(n);
    ptr.resize(n);
  }

  void addEdge(int from, int to, T fcap, T bcap) {
    g[from].push_back(edges.size());
    edges.push_back({from, to, fcap, 0});
    g[to].push_back(edges.size());
    edges.push_back({to, from, bcap, 0});
    while (need <= fcap / 2) {
      need <<= 1;
    }
  }

  bool bfs() {
    fill(d.begin(), d.end(), -1);
    q.push(source);
    d[source] = 0;
    while (!q.empty()) {
      int i = q.front();
      q.pop();
      for (int id : g[i]) {
        auto &e = edges[id];
        if (d[e.to] == -1 and e.c - e.f >= need) {
          d[e.to] = d[i] + 1;
          q.push(e.to);
        }
      }
    }
    return d[sink] != -1;
  }

  T dfs(int v, T flow) {
    if (flow == 0) {
      return 0;
    }
    if (v == sink) {
      return flow;
    }
    for (int& j = ptr[v]; j < g[v].size(); ++j) {
      auto& e = edges[g[v][j]], &be = edges[g[v][j] ^ 1];
      if (d[e.to] != d[v] + 1 or e.c - e.f < need) {
        continue;
      }
      T pushed = dfs(e.to, min(flow, e.c - e.f));
      if (pushed) {
        e.f += pushed;
        be.f -= pushed;
        return pushed;
      }
    }
    return 0;
  }

  T maxFlow() {
    T res = 0;
    while (need) {
      if (!bfs()) {
        need >>= 1;
        continue;
      }
      fill(ptr.begin(), ptr.end(), 0);
      while (T pushed = dfs(source, inf)) {
        res += pushed;
      }
    }
    return res;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);



  return 0;
}
